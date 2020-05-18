// parse a string by delimiter
inline vector<string> parse(const string &s, char delim) {
	vector<string> a;    stringstream ss(s);    string x;
	while (getline(ss, x, delim)) a.push_back(x);
	return a;
}