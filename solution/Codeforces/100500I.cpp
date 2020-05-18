#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <bitset>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define filla(a,x) memset(a, (x), sizeof(a))
#define for_each(it, X) for(typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = 4*int(1e5)+5;

pii c[33];
string s;


int main() {
#ifdef DEBUG
	freopen("100500I.in", "r", stdin);
	freopen("100500I.out", "w", stdout);
#endif
	int nTest = readln();
	for (int test_id = 1; test_id <= nTest; ++test_id) {
		for (int i = 0; i < 26; ++i)
			c[i] = make_pair(0, i);
		while (true) {
			getline(cin, s);
			int n = s.length();
			if (n < 1) continue;
			if (n == 1 && s[0] == '*') break;
			for (int i = 0; i < n; ++i) {
				char ch = s[i];
				if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')) {
					ch = tolower(ch);
					++c[ch-'a'].first;
				}
			}
		}
		sort(c, c+26);
		int sum = 0;
		for (int i = 25; i > 20; --i)
			if (c[i].first > 0)
				sum += c[i].second;
		// for (int i = 0; i < 26; ++i)
		// 	cout << c[i].first << " " << c[i].second << endl;1
		// cout << "sum: " << sum << endl;
		if (sum > 62) printf("Case %d: Effective\n", test_id);
		else printf("Case %d: Ineffective\n", test_id);
	}
	return 0;
}