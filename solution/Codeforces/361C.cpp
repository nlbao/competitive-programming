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

const int MAX_N = 5005;

int n, m;
int t[MAX_N], l[MAX_N], r[MAX_N];
ll value[MAX_N], a[MAX_N], s[MAX_N], maxA[MAX_N];
bool ok[MAX_N];


bool check() {
	fill(s, 0);
	foru(i, 1, n) a[i] = int(1e9);
	rep(id, m) {
		if (t[id] == 1)
			foru(i, l[id], r[id])
				s[i] += value[id];
		else
			foru(i, l[id], r[id])
				a[i] = min(a[i], value[id] - s[i]);
	}

	fill(s, 0);
	rep(id, m) {
		if (t[id] == 1)
			foru(i, l[id], r[id])
				s[i] += value[id];
		else {
			bool ck = false;
			foru(i, l[id], r[id])
				if (a[i]+s[i] == value[id]) {
					ck = true;
					break;
				}
			if (!ck) return false;
		}
	}
	foru(i, 1, n)
		if (abs(a[i]) > 1e9) return false;
	return true;
}


int main() {
#ifdef DEBUG
	freopen("361C.in", "r", stdin);
	freopen("361C.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	rep(i, m) {
		scanf("%d%d%d", &t[i], &l[i], &r[i]);
		value[i] = read();
	}

	if (!check()) {
		printf("NO");
		return 0;
	}
	printf("YES\n");
	foru(i, 1, n) printf("%d ", int(a[i]));
	return 0;
}