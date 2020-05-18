#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline ll read() {	ll x;   cin >> x;   return x;   }


const string WORDS_1[20] = {"zero", "one", "two", "three", "four", "five",
							"six", "seven", "eight", "nine", "ten", "eleven", "twelve",
							"thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
							"eighteen", "nineteen"};
const string WORDS_2[8] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};


string solve(string s) {
	int n = s.size();
	int i = 0;
	while (i < n && s[i] == '0') ++i;
	if (i >= n) return "zero";
	if (i == n-3)
		return "hundred";
	int x = s[i] - '0';
	if (i == n-1)
		return WORDS_1[x];
	int y = s[i+1] - '0';
	if (x < 2)
		return WORDS_1[x*10 + y];
	string ans = WORDS_2[x-2];
	if (y == 0) return ans;
	return ans + WORDS_1[y];
}


int main() {
#ifdef DEBUG
	freopen("1-one.in", "r", stdin);
	freopen("1-one.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cout.precision(9);

	int nTest = read();
	string s;
	while (nTest--) {
		cin >> s;
		cout << solve(s) << '\n';
	}
	return 0;
}