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

const int MAX_N = 2*int(1e6)+6;
const ll BASE = 10007LL;
const int MAX_LOG = 23;

struct entry {
	int nr[2], p;
} l[MAX_N];

int n, lenA, lenB, step = 1, minLen;
char a[MAX_N], b[MAX_N];
ll hA[MAX_N], hB[MAX_N], p[MAX_N];
set<ll> q;
vi tres, res;
vii list[2];
int value[MAX_N];
int pp[MAX_LOG][MAX_N];


int num(char x) {	return x-'a'+1;		}


ll getHa(int i, int j) {
	if (i == 0) return hA[j];
	else return hA[j] - hA[i-1]*p[j-i+1];
}


ll getHb(int i, int j) {
	if (i == 0) return hB[j];
	else return hB[j] - hB[i-1]*p[j-i+1];
}


bool check(int len) {
	q.clear();
	rep(i, lenB-len+1) {
		q.insert(getHb(i, i+len-1));
	}
	tres.clear();
	rep(i, lenA-len+1) {
		ll h = getHa(i, i+len-1);
		if (q.find(h) == q.end())
			tres.pb(i);
	}
	if (tres.empty()) return false;
	res.clear();
	res.assign(tres.begin(), tres.end());
	return true;
}


// int cmp(entry a, entry b) {
// 	if (a.nr[0] == b.nr[0]) return a.nr[1] < b.nr[1];
// 	return a.nr[0] < b.nr[0];
// }


// void suffix_array(int n) {
// 	rep(i, n) pp[0][i] = a[i]-'a';
// 	step = 1;
// 	for (int cnt = 1; (cnt>>1) < n; ++step, cnt <<= 1) {
// 		rep(i, n) {
// 			l[i].nr[0] = pp[step-1][i];
// 			if (i+cnt < n) l[i].nr[1] = pp[step-1][i+cnt];
// 			else l[i].nr[1] = -1;
// 			l[i].p = i;
// 		}
// 		sort(l, l+n, cmp);
// 		rep(i, n)
// 			if (i && l[i].nr[0] == l[i-1].nr[0] && l[i].nr[1] == l[i-1].nr[1])
// 				pp[step][l[i].p] = pp[step][l[i-1].p];
// 			else
// 				pp[step][l[i].p] = i;
// 	}
// }


// int compare (int i, int j, int l, int k) {
// 	pii a = mp(pp[k][i], pp[k][i+l-(1<<k)]);
// 	pii b = mp(pp[k][j], pp[k][j+l-(1<<k)]);
// 	return a == b ? 0 : a < b ? -1 : 1;
// }


int compare(int i, int j) {
	int l = 0, r = minLen-1, len = 0;
	while (l <= r) {
		int mid = (l+r)>>1;
		if (getHa(i, i+mid-1) == getHa(j, j+mid-1)) {
			len = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	return a[i+len] - a[j+len];
}



int main() {
#ifdef DEBUG
	freopen("NHREMIND.in", "r", stdin);
	freopen("NHREMIND.out", "w", stdout);
#endif
	readln(n);
	scanf("%s", b);
	rep(i, n-1) {
		scanf("%s", a);
		strcat(b, "#");
		strcat(b, a);
	}
	scanf("%s", a);

	lenA = strlen(a);
	lenB = strlen(b);
	p[0] = 1;
	foru(i, 1, max(lenA, lenB)) p[i] = p[i-1]*BASE;
	rep(i, lenA) {
		hA[i] = num(a[i]);
		if (i) hA[i] += hA[i-1]*BASE;
	}
	rep(i, lenB) {
		hB[i] = num(b[i]);
		if (i) hB[i] += hB[i-1]*BASE;
	}


	minLen = MAX_N;
	int l = 1, r = lenA;
	while (l <= r) {
		int mid = (l+r)>>1;
		if (check(mid)) {
			minLen = mid;
			r = mid-1;
		}
		else l = mid+1;
	}

	// q.clear();
	// rep(i, 2) list[i].clear();
	// int szRes = res.size();
	// rep(i, szRes) {
	// 	int x = res[i];
	// 	ll h = getHa(x, x+minLen-1);
	// 	if (q.find(h) == q.end()) {
	// 		q.insert(h);
	// 		list[0].pb(mp(x, x));
	// 	}
	// }

	// int pos = -1;
	// for (int c = 0, t = 0, tt = 1; c <= minLen; tt = t, t = 1-t, ++c) {
	// 	int sz = list[t].size(), minA = MAX_N;
	// 	if (sz < 2) {
	// 		if (sz) pos = list[t][0].sc;
	// 		break;
	// 	}
	// 	list[tt].clear();
	// 	rep(i, sz) {
	// 		value[i] = num(a[list[t][i].fr]);
	// 		minA = min(minA, value[i]);
	// 	}
	// 	rep(i, sz)
	// 		if (value[i] == minA)
	// 			list[tt].pb(mp(list[t][i].fr + 1, list[t][i].sc));
	// }

	// foru(i, pos, pos+minLen-1) printf("%c", a[i]);


	int pos = res[0];
	int szRes = res.size(), k = 0;
	// suffix_array(lenA);
	// while ( ((k+1)<<1) <= minLen ) ++k;
	// foru(i, 1, szRes-1)
	// 	if (compare(res[i], pos, minLen, k) < 0)
	// 		pos = res[i];

	foru(i, 1, szRes-1)
		if (compare(res[i], pos) < 0)
			pos = res[i];

	foru(i, pos, pos+minLen-1) printf("%c", a[i]);

	return 0;
}