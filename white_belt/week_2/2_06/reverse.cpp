void Reverse(vector<int>& initial) {
	vector<int> reversed;
	for (int i = initial.size()-1; i >= 0; --i)
		reversed.push_back(initial[i]);

	initial.clear();

	for (auto s : reversed)
		initial.push_back(s);
}

