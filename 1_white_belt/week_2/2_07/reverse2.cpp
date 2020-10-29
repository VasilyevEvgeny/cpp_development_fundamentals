// https://www.coursera.org/learn/c-plus-plus-white/programming/l5jN8/razvorot-posliedovatiel-nosti-2

vector<int> Reversed(const vector<int>& v) {
	vector<int> reversed;
	for (int i = v.size()-1; i >= 0; --i)
		reversed.push_back(v[i]);

	return reversed;
}
