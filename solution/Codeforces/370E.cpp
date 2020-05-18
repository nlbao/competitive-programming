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

const int MAX_N = 2*int(1e5)+5;



bool check() {
	a[n+1] = 0;
	fill(f, 0);
	fill(g, 0);
	ford(i, n, 1) {
		if (a[i] == 0) f[i] = f[i+1] + 1;
		if (a[i+1] != 0) g[i] = a[i+1];
		else g[i] = g[i+1];
	}

	ford(i, 1, n)
		if (a[i] > n)
			return false;

	fill(ok, false);
	int crr = 1;
	foru(i, 1, n) {
		if (a[i] > crr) return false;
		
	}


	return true;
}


int main() {
#ifdef DEBUG
	freopen("370E.in", "r", stdin);
	freopen("370E.out", "w", stdout);
#endif
	read(n);
	foru(i, 1, n) read(a[i]);
	if (!check()) prinf("-1");
	return 0;
}