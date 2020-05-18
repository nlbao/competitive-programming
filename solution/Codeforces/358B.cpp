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
const ll BASE = 10007LL;

char s[MAX_N];
string a[MAX_N];
int lenA[MAX_N];
ll p[MAX_N], h[MAX_N], g[MAX_N];


ll getH(int i, int j) {
	if (i == 0) return h[j];
	return h[j] - h[i-1]*p[j-i+1];
}


int main() {
#ifdef DEBUG
	freopen("358B.in", "r", stdin);
	freopen("358B.out", "w", stdout);
#endif
	int n = readln();
	rep(i, n) getline(cin, a[i]);
	scanf("%s", &s);

	// rep(i, n) cout << a[i] << endl;
	// cout <<s <<endl;

	p[0] = 1;
	foru(i, 1, MAX_N-1) p[i] = p[i-1]*BASE;

	int lenS = strlen(s);
	h[0] = s[0];
	foru(i, 1, lenS-1) h[i] = h[i-1]*BASE + ll(s[i]);

	rep(i, n) {
		lenA[i] = a[i].size();
		g[i] = 0;
		rep(j, lenA[i]) g[i] = g[i]*BASE + ll(a[i][j]);
	}

	int pos = 0;
	rep(i, n) {
		if (pos >= lenS) {
			cout << "no";
			return 0;
		}
		while (pos+lenA[i] <= lenS && getH(pos, pos+lenA[i]-1) != g[i]) ++pos;
		if (pos+lenA[i] > lenS) {
			cout << "no";
			return 0;
		}
		pos += lenA[i];
	}
	cout << "yes";
	return 0;
}