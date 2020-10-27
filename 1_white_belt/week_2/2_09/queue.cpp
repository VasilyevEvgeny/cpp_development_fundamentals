#include <iostream>
#include <vector>

using namespace std;

void command_COME_add(vector<bool>& queue, int k) {

	queue.assign(queue.size()+k, false);
}

void command_COME_remove(vector<bool>& queue, int k) {

	queue.resize(queue.size()-k);
}

void command_WORRY(vector<bool>& queue, int i) {

	queue[i] = true;
}

void command_QUIET(vector<bool>& queue, int i) {

	queue[i] = false;
}

void command_WORRY_COUNT(vector<bool>& queue) {

	int n = 0;
	for (auto person : queue)
		if (person)
			++n;
	cout << n << endl;
}


int main() {

	int Q;
	vector<bool> queue;
	string c;
	int idx;

	cin >> Q;

	int n = 0;
	while (n < Q) {
		cin >> c;
		if (c == "COME") {
			cin >> idx;
			if (idx > 0)
				queue.resize(queue.size()+idx, false);
			else if (idx < 0)
				queue.resize(queue.size()+idx);
		}
		else if (c == "WORRY") {
			cin >> idx;
			queue[idx] = true;
		}
		else if (c == "QUIET") {
			cin >> idx;
			queue[idx] = false;
		}
		else if (c == "WORRY_COUNT") {
			int number = 0;
			for (auto q : queue)
				if (q)
					++number;
			cout << number << endl;
		}

		++n;

	}

	return 0;
}

