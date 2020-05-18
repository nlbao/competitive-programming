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


int m, n, back;
int q[MAX_N], pLeft[MAX_N];
ll a[MAX_N], f[MAX_N];
ll res;



inline void update(int i)  {
	while (back && a[q[back]] > a[i]) --back;
	int l = 0;
	if (back) {
		l = q[back];
		if (a[l] == a[i]) l = pLeft[l];
		else ++l;
	}
	pLeft[i] = l;
	f[i] = a[i]*ll(i-l+1);
	if (l) f[i] += f[l-1];
	res += f[i];
	q[++back] = i;
}



int main() {
#ifdef DEBUG
	freopen("CREC01.inp", "r", stdin);
	freopen("CREC01.out", "w", stdout);
#endif
	res = 0;
	fill(a, 0);
	scanf("%d%d\n", &m, &n);
	for (int i = 0; i < m; ++i) {
		back = 0;
		for (int j = 0; j < n; ++j) {
			char c;
			scanf("%c", &c);
			if (c == '1') ++a[j];
			else a[j] = 0;
			update(j);
		}
		scanf("\n");
	}
	cout << res << endl;
	return 0;
}