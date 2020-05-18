#include <cstdio>
#include <cstdlib>
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
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_LEN = 2004;
const int MAX_N = 22;
const int MAX_M = 2200;


int n;
int b[MAX_N][MAX_LEN], len[MAX_N];
string a[MAX_N];
string s;
bool english[MAX_M], france[MAX_M], tmpEng[MAX_M], tmpFra[MAX_M], checked[MAX_M], chk0[MAX_M];
vector<string> elems[MAX_N];
map<string, int> num;


vector<string> parse(const string &s, char delim) {
    vector<string> ans;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim))
        ans.push_back(item);
    return ans;
}


inline bool contains(bool a[], int s) {
	return a[s] == true;
}


int solve_0() {
	// to num
	int k = 0;
	num.clear();
	for (int i = 0; i < n; ++i)
		foreach(it, elems[i])
			num[*it];
	foreach(it, num)
		it->second = ++k;
	for (int i = 0; i < n; ++i) {
		len[i] = elems[i].size();
		for (int j = 0; j < len[i]; ++j)
			b[i][j] = num[elems[i][j]];
	}

	//
	filla(english, false);
	filla(france, false);
	filla(chk0, false);
	int c0 = 0;
	for (int i = 0; i < len[0]; ++i) english[b[0][i]] = true;
	for (int i = 0; i < len[1]; ++i) france[b[1][i]] = true;
	for (int i = 0; i < MAX_M; ++i)
		if (english[i] && france[i]) {
			++c0;
			chk0[i] = true;
		}
	if (n == 2) return c0;

	//
	int m = n-2, ans = 1e9;
	for (int mask = 0; mask < (1<<m); ++mask) {
		int c = 0;
		filla(tmpEng, false);
		filla(tmpFra, false);
		filla(checked, false);

		for (int i = 0; i < m; ++i) {
			int id = i+2;
			if (mask & (1<<i)) { // 1, france
				for (int k = 0; k < len[id]; ++k) {
					int s = b[id][k];
					if (contains(chk0, s) || contains(checked, s)) continue;
					tmpFra[s] = true;
					bool isEng = contains(english, s) || contains(tmpEng, s);
					bool isFra = true;
					if (isEng && isFra) {
						++c;
						checked[s] = true;
					}
				}
			}
			else {	// 0, english
				for (int k = 0; k < len[id]; ++k) {
					int s = b[id][k];
					if (contains(chk0, s) || contains(checked, s)) continue;
					tmpEng[s] = true;
					bool isEng = true;
					bool isFra = contains(france, s) || contains(tmpFra, s);
					if (isEng && isFra) {
						++c;
						checked[s] = true;
					}
				}
			}
		}
		ans = min(ans, c0 + c);
	}
	return ans;
}


int main() {
#ifdef DEBUG
	// freopen("C.in", "r", stdin);
	// freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		n = read();
		getline(cin, s);
		for (int i = 0; i < n; ++i) {
			getline(cin, s);
			a[i] = s;
			elems[i] = parse(s, ' ');
			// cout << a[i] << endl;
			// foreach(it, elems[i])
				// cout << "	" << *it << endl;
		}

		int ans = solve_0();
		printf("Case #%d: %d\n", testid, ans);
	}
	return 0;
}