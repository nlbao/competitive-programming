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
const int MAX_M = 103;

int n, m;
int a[MAX_N], b[MAX_N];
vii res;


int main() {
#ifdef DEBUG
	freopen("370C.in", "r", stdin);
	freopen("370C.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	foru(i, 1, n) read(a[i]);
	sort(a+1, a+1+n);
	int c = 0;
	foru(i, n/2+1, n) b[++c] = a[i];
	foru(i, 1, (n/2)) b[++c] = a[i];

	int maxPair = 0;
	res.clear();
	foru(i, 1, n) {
		if (a[i] != b[i]) ++maxPair;
		res.pb(mp(a[i], b[i]));
	}

	printf("%d\n", maxPair);
	int szRes = res.size();
	rep(i, szRes)
		printf("%d %d\n", res[i].fr, res[i].sc);
	return 0;
}