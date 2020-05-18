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

const int MAX_N = 3*int(1e5)+5;

int n;
vii q;
pii a[MAX_N];
int res[MAX_N];



int main() {
#ifdef DEBUG
	freopen("379C.in", "r", stdin);
	freopen("379C.out", "w", stdout);
#endif
	read(n);
	rep(i, n) a[i] = mp(read(), i);
	sort(a, a+n);

	q.clear();
	res[a[0].sc] = a[0].fr;
	foru(i, 1, n-1)
		if (a[i].fr == a[i-1].fr) q.pb(a[i]);
		else {
			res[a[i].sc] = a[i].fr;
			for (int x = a[i-1].fr+1; x < a[i].fr && !q.empty(); ++x) {
				res[q.back().sc] = x;
				q.pop_back();
			}
		}
	for (int x = a[n-1].fr+1; !q.empty(); ++x) {
		res[q.back().sc] = x;
		q.pop_back();
	}

	rep(i, n) printf("%d ", res[i]);
	return 0;
}