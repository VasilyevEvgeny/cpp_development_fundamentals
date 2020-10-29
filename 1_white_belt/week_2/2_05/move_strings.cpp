// https://www.coursera.org/learn/c-plus-plus-white/programming/nfWe8/pieriemieshchieniie-strok

void MoveStrings(vector<string>& source, vector<string>& destination) {
	for (auto s : source)
		destination.push_back(s);

		source.clear();
}


