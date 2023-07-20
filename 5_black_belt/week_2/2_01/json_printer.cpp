#include "test_runner.h"

#include <cassert>
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stack>
#include <string>

using namespace std;

void PrintJsonString(std::ostream& out, std::string_view str);

template <typename ParentContext>
class JsonContext {
protected:
    JsonContext(ostream& out, ParentContext& parent)
            : out_(out)
            , parent_(parent)
    {
    }

    ostream& out_;
    ParentContext& parent_;
};

class EmptyContext {};

template <typename ParentContext>
class ObjectKeyContext;

template <typename ParentContext>
class ObjectValueContext;

template <typename ParentContext>
class ArrayContext : public JsonContext<ParentContext> {
public:
    using Self = ArrayContext<ParentContext>;

    ArrayContext(ostream& out, ParentContext& parent)
            : JsonContext<ParentContext>(out, parent)
    {
        this->out_ << '[';
    }

    ~ArrayContext() {
        EndArray();
    }

    ArrayContext& Number(int64_t value) {
        MaybePrintComma();
        this->out_ << value;
        return *this;
    }

    ArrayContext& Null() {
        MaybePrintComma();
        this->out_ << "null";
        return *this;
    }

    ArrayContext& String(string_view s) {
        MaybePrintComma();
        PrintJsonString(this->out_, s);
        return *this;
    }

    ArrayContext& Boolean(bool value) {
        MaybePrintComma();
        this->out_ << (value ? "true" : "false");
        return *this;
    }

    ArrayContext<Self> BeginArray() {
        MaybePrintComma();
        return ArrayContext<Self>(this->out_, *this);
    }

    ParentContext& EndArray() {
        if (!array_ended_) {
            this->out_ << ']';
            array_ended_ = true;
        }
        return this->parent_;
    }

    ObjectKeyContext<Self> BeginObject() {
        MaybePrintComma();
        return ObjectKeyContext<Self>(this->out_, *this);
    }
private:
    bool first_printed_ = false;
    bool array_ended_ = false;

    void MaybePrintComma() {
        if (first_printed_) {
            this->out_ << ',';
        } else {
            first_printed_ = true;
        }
    }
};

template <typename ParentContext>
class ObjectKeyContext : public JsonContext<ParentContext> {
public:
    using Self = ObjectKeyContext<ParentContext>;

    ObjectKeyContext(ostream& out, ParentContext& parent)
            : JsonContext<ParentContext>(out, parent)
    {
        this->out_ << '{';
    }

    ~ObjectKeyContext() {
        EndObject();
    }

    ObjectValueContext<Self> Key(string_view s) {
        MaybePrintComma();
        PrintJsonString(this->out_, s);
        return ObjectValueContext<Self>(this->out_, *this);
    }

    ParentContext& EndObject() {
        if (!object_ended_) {
            this->out_ << '}';
            object_ended_ = true;
        }
        return this->parent_;
    }
private:
    bool first_printed_ = false;
    bool object_ended_ = false;

    void MaybePrintComma() {
        if (first_printed_) {
            this->out_ << ',';
        }
        else {
            first_printed_ = true;
        }
    }
};

template <typename ParentContext>
class ObjectValueContext : public JsonContext<ParentContext> {
public:
    ObjectValueContext(ostream& out, ParentContext& parent)
            : JsonContext<ParentContext>(out, parent)
    {
        this->out_ << ':';
    }

    ~ObjectValueContext() {
        if (!value_filled_) {
            Null();
        }
    }

    ParentContext& Number(int64_t value) {
        value_filled_ = true;
        this->out_ << value;
        return this->parent_;
    }

    ParentContext& Null() {
        value_filled_ = true;
        this->out_ << "null";
        return this->parent_;
    }

    ParentContext& String(string_view s) {
        value_filled_ = true;
        PrintJsonString(this->out_, s);
        return this->parent_;
    }

    ParentContext& Boolean(bool value) {
        value_filled_ = true;
        this->out_ << (value ? "true" : "false");
        return this->parent_;
    }

    ArrayContext<ParentContext> BeginArray() {
        value_filled_ = true;
        return ArrayContext<ParentContext>(this->out_, this->parent_);
    }

    ObjectKeyContext<ParentContext> BeginObject() {
        value_filled_ = true;
        return ObjectKeyContext<ParentContext>(this->out_, this->parent_);
    }
private:
    bool value_filled_ = false;
};

void PrintJsonString(std::ostream& out, std::string_view str) {
    ostringstream os;
    os << quoted(str);
    out << os.str();
}

ArrayContext<EmptyContext> PrintJsonArray(std::ostream& out) {
    static EmptyContext empty;
    return ArrayContext<EmptyContext>(out, empty);
}

ObjectKeyContext<EmptyContext> PrintJsonObject(std::ostream& out) {
    static EmptyContext empty;
    return ObjectKeyContext<EmptyContext>(out, empty);
}

void TestPrintString() {
    ostringstream output;

    {
        PrintJsonString(std::cout, "Hello, \"world\"");
    }

    ASSERT_EQUAL(output.str(), R"(Hello, \"world\")");
}

void TestArray() {
    std::ostringstream output;

    {
        auto json = PrintJsonArray(output);
        json
                .Number(5)
                .Number(6)
                .BeginArray()
                .Number(7)
                .EndArray()
                .Number(8)
                .String("bingo!");
    }

    ASSERT_EQUAL(output.str(), R"([5,6,[7],8,"bingo!"])");
}

void TestArray2() {
    std::ostringstream output;

    {
        PrintJsonArray(output)
                .Null()
                .String("Hello")
                .Number(123)
                .Boolean(false)
                .EndArray();
    }

    ASSERT_EQUAL(output.str(), R"([null,"Hello",123,false])");
}

void TestArray3() {
    std::ostringstream output;

    {
        PrintJsonArray(output)
                .Null()
                .String("Hello")
                .Number(123)
                .Boolean(false);
    }

    ASSERT_EQUAL(output.str(), R"([null,"Hello",123,false])");
}

void TestArray4() {
    std::ostringstream output;

    {
        PrintJsonArray(output)
                .String("Hello")
                .BeginArray()
                .String("World");
    }

    ASSERT_EQUAL(output.str(), R"(["Hello",["World"]])");
}

void TestObject() {
    std::ostringstream output;

    {
        auto json = PrintJsonObject(output);
        json
                .Key("id1").Number(1234)
                .Key("id2").Boolean(false)
                .Key("").Null()
                .Key("\"").String("\\");
    }

    string str = R"({"id1":1234,"id2":false,"":null,"\"":"\\"})";
    ASSERT_EQUAL(output.str(), str);
}

void TestObject2() {
    std::ostringstream output;

    {
        PrintJsonObject(output)
                .Key("foo")
                .BeginArray()
                .String("Hello")
                .EndArray()
                .Key("foo")  // ������������� ����� �����������
                .BeginObject()
                .Key("foo");  // �������� ������� � ����� ��������� ������� null � �������� ��������
    }

    string str = R"({"foo":["Hello"],"foo":{"foo":null}})";
    ASSERT_EQUAL(output.str(), str);
}

void TestAutoClose() {
    std::ostringstream output;

    {
        auto json = PrintJsonArray(output);
        json.BeginArray().BeginObject();
    }

    ASSERT_EQUAL(output.str(), R"([[{}]])");
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestArray);
    RUN_TEST(tr, TestArray2);
    RUN_TEST(tr, TestArray3);
    RUN_TEST(tr, TestArray4);
    RUN_TEST(tr, TestObject);
    RUN_TEST(tr, TestObject2);
    RUN_TEST(tr, TestAutoClose);

    return 0;
}
