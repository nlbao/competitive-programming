#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vecint;
typedef pair<int, int> ppi;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }

const int MAX_N = int(1e5)+5;
const ll MODULE = ll(1e9)+7;

char s[MAX_N];
ll f[MAX_N];


ll mmod(ll x) {
	return x%MODULE;
}


int main() {
#ifdef DEBUG
	freopen("sam-and-substrings.in", "r", stdin);
	freopen("sam-and-substrings.out", "w", stdout);
#endif
	scanf("%s", s);
	int n = strlen(s);
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		f[i] = s[i] - int('0');
		if (i)
			f[i] = mmod( f[i] + mmod(f[i-1]*10) + mmod(f[i]*ll(i)) );
		res = mmod(res + f[i]);
	}
	cout << res << endl;
	return 0;
}