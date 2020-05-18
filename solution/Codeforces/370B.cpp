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

const int MAX_N = 111;

int n;
int m[MAX_N];
vi a[MAX_N];
bool ok[MAX_N];


bool check(int id) {
	fill(ok, false);
	rep(i, m[id])
		ok[a[id][i]] = true;

	rep(x, n)
		if (x != id) {
			bool ck = true;
			rep(i, m[x])
				if (!ok[a[x][i]]) {
					ck = false;
					break;
				}
			if (ck) return false;
		}
	return true;
}


int main() {
#ifdef DEBUG
	freopen("370B.in", "r", stdin);
	freopen("370B.out", "w", stdout);
#endif
	read(n);
	rep(i, n) {
		read(m[i]);
		rep(j, m[i])
			a[i].pb(read());
		sort(a[i].begin(), a[i].end());
	}

	rep(i, n)
		if (check(i)) printf("YES\n");
		else printf("NO\n");
	return 0;
}