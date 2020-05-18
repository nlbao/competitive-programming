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

#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector< pair<int, int> > vii;

#define foru(i,a,b) for(int i = int(a); i <= int(b); ++i)
#define ford(i,b,a) for(int i = int(b); i >= int(a); --i)
#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define all(a) a.begin(),a.end()
#define sz(a) int(a.size())
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln() {  int x;  scanf("%d\n",&x);   return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }


const int MAX_N = int(1e5)+5;
const int MODULE = int(1e9)+7;

int n, m;
char a[MAX_N], b[MAX_N];
int mnext[MAX_N][33], f[MAX_N];


int num(char x) {
	return x-'a';
}


int mmod(int x) {
	return x%MODULE;
}


int solve() {
	rep(i, 30) mnext[n][i] = n;
	ford(i, n-1, 0) {
		rep(j, 30) mnext[i][j] = mnext[i+1][j];
		mnext[i][num(a[i])] = i;
	}


	f[n] = 0;
	ford(i, n-1, 0) {
		f[i] = 1;
		int aa = num(a[i]);
		rep(x, 30)
			if (x != aa)
				f[i] = mmod(f[i] + f[mnext[i][x]]);
		// cout << i << " " << f[i] << endl;
	}

	int res = 0, pos = 0;
	rep(last, m) {
		if (last && b[last] == b[last-1]) break;
		int low = num(b[last]);
		pos = mnext[pos][low]+1;
		if (pos >= n) break;
		// cout << "       " << last << "     " << pos << "       " << f[mnext[pos][low+1]] << endl;
		foru(x, low+1, 29) {
			if (last && x == num(b[last-1])) continue;
			res = mmod(res + f[mnext[pos][x]]);
		}
	}
	rep(i, 30)
		if (i > num(b[0]))
			res = mmod(res + f[mnext[0][i]]);
	return res;
}


int main() {
#ifdef DEBUG
	freopen("DIFFSTR.in", "r", stdin);
	freopen("DIFFSTR.out", "w", stdout);
#endif
	int nTest = readln();
	rep(test_id, nTest) {
		scanf("%s%s", &a, &b);
		n = strlen(a);
		m = strlen(b);
		printf("%d\n", solve());
	}
	return 0;
}