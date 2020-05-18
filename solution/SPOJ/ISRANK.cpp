// #pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fori(i,a,b) for (ll i=(a); i<=(b); ++i)
#define ford(i,a,b) for (ll i=(a); i>=(b); --i)
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define has(a, x) (a.find(x) != a.end())
#define all(x) x.begin(), x.end()
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


namespace fastIO {
	const size_t amount = 16;
	static char buffer[1<<16];
	static char* dataEnd = buffer + sizeof(buffer);
	static const char* pos = dataEnd;

	inline void readAhead() {
	    size_t remaining = dataEnd - pos;
	    if (remaining < amount) {
			memmove(buffer, pos, remaining);
			size_t sz = fread(buffer + remaining, 1, sizeof(buffer) - remaining, stdin);
			pos = buffer;
			dataEnd = buffer + remaining + sz;
			if (dataEnd != buffer + sizeof(buffer))
				*dataEnd = 0;
	    }
	}

	inline int readInt() {
		readAhead();
		int x = 0;
		bool neg = false;
		if (*pos == '-') {
			++pos;
			neg = true;
		}
	    while (*pos < '0' || *pos > '9') ++pos;
	    while (*pos >= '0' && *pos <= '9') {
			x *= 10;
			x += *pos - '0';
			++pos;
	    }
	    return neg ? -x : x;
	}
};

using namespace fastIO;


const int MAX_N = 12;
const int MAX_LEN = 1e4+14;
const int MAX_BLOCK = 222;
const int oo = 1e9+4;


int n, p1, p2, minVal, maxVal;
int len[MAX_N], blockSize[MAX_N], tmp[MAX_N * MAX_LEN];
int _rank[MAX_N][MAX_LEN], point[MAX_N][MAX_LEN];
vector<int> a[MAX_N][MAX_BLOCK];


inline int getCnt(int id, int k, int val) {
	return (a[id][k].empty()) ? 0 : a[id][k].end() - upper_bound(all(a[id][k]), val);
}


int countGreaterThan(int id, int val) {
	int ans=0;
	for (int l=1, r, k=1; l<=len[id]; l=r+1, ++k) {
		r=min(len[id], l+blockSize[id]-1);
		if (r<p1) continue;
		if (l>p2) break;
		if (p1<=l && r<=p2) {
			ans += getCnt(id, k, val);
			continue;
		}
		fori(i,l,r) if (p1<=i && i<=p2 && point[id][i]>val) ++ans;
	}
	return ans;
}


inline int getMax(int id, int k) {
	return (a[id][k].empty()) ? -1 : a[id][k].back();
}


inline int getMin(int id, int k) {
	return (a[id][k].empty()) ? oo : a[id][k].front();
}


inline void findMinMax(int id) {
	for (int l=1, r, k=1; l<=len[id]; l=r+1, ++k) {
		r=min(len[id], l+blockSize[id]-1);
		if (r<p1) continue;
		if (l>p2) break;
		if (p1<=l && r<=p2) {
			maxVal = max(maxVal, getMax(id, k));
			minVal = min(minVal, getMin(id, k));
			continue;
		}
		fori(i,l,r) if (p1<=i && i<=p2) {
			maxVal=max(maxVal, point[id][i]);
			minVal=min(minVal, point[id][i]);
		}
	}
}


int main() {
#ifdef DEBUG
	freopen("ISRANK.in", "r", stdin);
	freopen("ISRANK.out", "w", stdout);
#endif
	n = readInt();
	fori(i,1,n) len[i] = readInt();
	fori(i,1,n) fori(j,1,len[i]) _rank[i][j] = readInt();
	fori(i,1,n) fori(j,1,len[i]) point[i][_rank[i][j]] = readInt();
	fori(id,1,n) {
		blockSize[id] = min(len[id], (int)sqrt(len[id])+4);
		for (int l=1, r, k=1; l<=len[id]; l=r+1, ++k) {
			r=min(len[id], l+blockSize[id]-1);
			a[id][k].clear();
			fori(i,l,r) a[id][k].pb(point[id][i]);
			sort(all(a[id][k]));
		}
	}

	int c=0;
	fori(i,1,n) fori(j,1,len[i]) tmp[++c] = point[i][j];
	sort(tmp+1, tmp+1+c);

	int nQ = readInt();
	bool inQ[MAX_N];
	while (nQ--) {
		filla(inQ, 0);
		int m, k;
		m = readInt();
		fori(i,1,m) {
			int x = readInt();
			inQ[x]=1;
		}
		p1 = readInt();
		p2 = readInt();
		k = readInt();
		--k;
		minVal = oo;
		maxVal = -1;
		fori(i,1,n) if (inQ[i]) findMinMax(i);

		int l=1, r=c, ans=-1;
		while (l<=c && tmp[l]<minVal) ++l;
		while (r>=l && tmp[r]>maxVal) --r;
		while (l<=r) {
			int mid=(l+r)>>1, val=tmp[mid], cnt=0;
			fori(i,1,n) if (inQ[i]) cnt += countGreaterThan(i, val);
			if (cnt==k) {
				ans=val;
				r=mid-1;
			}
			else if (cnt>k) l=mid+1;
			else r=mid-1;
		}
		printf("%d\n", ans);
	}

	return 0;
}