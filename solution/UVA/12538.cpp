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
#include <ext/rope>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;
using namespace __gnu_cxx;

typedef long long ll;
typedef pair<int, int> pii;

#define filla(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = 5*int(1e4)+4;

crope tmp, version[MAX_N], vnow;
char s[222];


int main() {
#ifdef DEBUG
	freopen("12538.in", "r", stdin);
	freopen("12538.out", "w", stdout);
#endif
	int n = read(), m = 0, d = 0;
	for (int id = 1; id <= n; ++id) {
		int types = read(), p, c, v;
		if (types == 1) {
			scanf("%d %s\n", &p, s);
			p -= d;
			vnow.insert(p, s);
			version[++m] = vnow;
		}
		else if (types == 2) {
			scanf("%d%d", &p, &c);
			p -= d;
			c -= d;
			vnow.erase(p-1, c);
			version[++m] = vnow;
		}
		else {
			scanf("%d%d%d", &v, &p, &c);
			p -= d;
			c -= d;
			v -= d;
			tmp = version[v].substr(p-1, c);
			string s = string(tmp.begin(), tmp.end());
			for (int i = 0, len = (int)s.length(); i < len; ++i)
				d += (s[i] == 'c');
			// d += count(tmp.begin(), tmp.end(), 'c');
			cout << tmp << "\n";
		}
	}
	return 0;
}