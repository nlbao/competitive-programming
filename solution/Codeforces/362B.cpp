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

int n, m;
int a[3111];

string check() {
	if (a[0] == 1 || a[m-1] == n) return "NO";
	rep(i, m-2)
		if (a[i]+1 == a[i+1] && a[i]+2 == a[i+2])
			return "NO";
	return "YES";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("362B.in", "r", stdin);
    freopen("362B.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    rep(i, m) scanf("%d", &a[i]);
    sort(a, a+m);
    cout << check() << endl;

    return 0;
}