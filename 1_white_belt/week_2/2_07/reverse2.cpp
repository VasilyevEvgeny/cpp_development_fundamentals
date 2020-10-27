
vector<int> Reversed(const vector<int>& v) {
	vector<int> reversed;
	for (int i = v.size()-1; i >= 0; --i)
		reversed.push_back(v[i]);

	return reversed;
}
