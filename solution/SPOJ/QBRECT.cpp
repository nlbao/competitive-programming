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


const int MAX_N = 1003;

int m, n, res, back;
int a[MAX_N], q[MAX_N];
int pLeft[MAX_N], pRight[MAX_N];



void update(int i) {
	while (back && (i >= n || a[q[back]] > a[i])) {
		int k = q[back--];
		pRight[k] = i-1;
		res = max(res, a[k]*(pRight[k]-pLeft[k]+1));
	}
	if (back == 0) pLeft[i] = 0;
	else
		if (a[q[back]] == a[i]) pLeft[i] = pLeft[q[back]];
		else pLeft[i] = q[back]+1;
	q[++back] = i;
}



int main() {
#ifdef DEBUG
	freopen("QBRECT.inp", "r", stdin);
	freopen("QBRECT.out", "w", stdout);
#endif
	res = 0;
	fill(a, 0);
	scanf("%d%d", &m, &n);
	a[n] = 0;
	for (int i = 0; i < m; ++i) {
		back = 0;
		for (int j = 0; j < n; ++j) {
			int x = read();
			if (x == 1) ++a[j];
			else a[j] = 0;
			update(j);
		}
		update(n);
	}
	printf("%d\n", res);
	return 0;
}