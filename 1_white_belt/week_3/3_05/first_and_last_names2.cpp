// https://www.coursera.org/learn/c-plus-plus-white/programming/aN8U1/imiena-i-familii-2

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct FullName {
    string name;
    string sirname;
};

class Person {

public:
    void ChangeFirstName(int year, const string& first_name) {
        if (year_name_sirname.count(year) == 0) {
            year_name_sirname[year].sirname = "";
        }
        year_name_sirname[year].name = first_name;
    }

    void ChangeLastName(int year, const string& last_name) {
        if (year_name_sirname.count(year) == 0) {
            year_name_sirname[year].name = "";
        }
        year_name_sirname[year].sirname = last_name;
    }

    string GetFullName(int year) {
        if (year_name_sirname.empty()) {
            return "Incognito";
        }
        else {
            for (const auto& i : year_name_sirname) {
                if (year < i.first) return "Incognito";
                break;
            }
        }

        string name, sirname;;
        for (const auto& i : year_name_sirname) {
            if (i.first <= year && !i.second.sirname.empty()) {
                sirname = i.second.sirname;
            }
            if (i.first <= year && !i.second.name.empty()) {
                name = i.second.name;
            }
        }

        if (name.empty()) {
            return sirname + " with unknown first name";
        }
        else if(sirname.empty()) {
            return name + " with unknown last name";
        }
        else {
            return name + " " + sirname;
        }
    }
    string GetFullNameWithHistory(int year) {
        if (year_name_sirname.empty()) {
            return "Incognito";
        }
        else {
            for (const auto& i : year_name_sirname) {
                if (year < i.first) {
                    return "Incognito";
                }
                break;
            }
        }

        string name, sirname;
        vector<string> sirnames;
        vector<string> names;

        for (const auto& i : year_name_sirname) {
            if (i.first <= year && !i.second.sirname.empty()) {
                if (i.second.sirname != sirname && !sirname.empty()) {
                    sirnames.push_back(sirname);
                }
                sirname = i.second.sirname;
            }
            if (i.first <= year && !i.second.name.empty()) {
                if (i.second.name != name && !name.empty()) {
                    names.push_back(name);
                }
                name = i.second.name;
            }
        }

        string names_str, sirnames_str;
        if (!sirnames.empty()) {
            sirnames_str += " (" + sirnames[sirnames.size() - 1];
            if (sirnames.size() > 1) {
                for (size_t i = sirnames.size() - 1; i > 0; --i) {
                    sirnames_str += ", " + sirnames[i - 1];
                }
            }
            sirnames_str += ")";
        }

        if (!names.empty()) {
            names_str += " (" + names[names.size() - 1];
            if (names.size() >1) {
                for (size_t i = names.size() - 1; i > 0; --i) {
                    names_str += ", " + names[i - 1];
                }
            }
            names_str += ")";
        }

        if (name.empty()) {
            return sirname + sirnames_str + " with unknown first name";
        }
        else if (sirname.empty()) {
            return name + names_str + " with unknown last name";
        }
        else {
            return name + names_str + " " + sirname + sirnames_str;
        }
    }

private:
    map<int, FullName> year_name_sirname;
};

