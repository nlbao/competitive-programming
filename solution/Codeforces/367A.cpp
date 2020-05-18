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

const int MAX_N = 100005;


char s[MAX_N];
int a[MAX_N], c[3][MAX_N];


int get_c(int type, int l, int r) {
	return c[type][r] - c[type][l-1];
}


bool check(int l, int r) {
	int len = r-l+1;
	if (len < 3) return true;
	int c[3];
	rep(i, 3) c[i] = get_c(i, l, r);
	switch (len%3) {
		case 0: if (c[0] == c[1] && c[0] == c[2])
					return true;
				break;
		case 1: rep(i, 3)
					foru(j, i+1, 2)
						if (c[i] == c[j] && c[3-i-j] == c[i]+1)
							return true;
				break;
		case 2: rep(i, 3)
					foru(j, i+1, 2)
						if (c[i] == c[j] && c[3-i-j] == c[i]-1)
							return true;
				break;
	}
	return false;
}


int main() {
#ifdef DEBUG
	freopen("367A.in", "r", stdin);
	freopen("367A.out", "w", stdout);
#endif
	scanf("%s", &s);
	int n = strlen(s);
	rep(i, n) a[i+1] = s[i]-'x';

	fill(c, 0);
	foru(i, 1, n) {
		rep(type, 3) c[type][i] = c[type][i-1];
		++c[a[i]][i];
	}

	int nTest = read();
	rep(test_id, nTest) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (check(x, y)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}