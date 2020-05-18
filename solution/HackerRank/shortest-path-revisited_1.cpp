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
#define err(x) cout << __LINE__ << ": " << #x << " = " << (x) << endl;
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define has(a, x) (a.find(x) != a.end())
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


struct SAM {
	static const int MAX_A = 29;
	static const int MAX_N = 1e5+5;
	static const int MAX_SAM = 2*MAX_N;

	struct State {
		int len, link;
		int nexts[MAX_A];

		State() {
			len=0;	link=-1;
			filla(nexts, -1);
		}

		State operator = (const State &o) {
			len=o.len;	link=o.link;
			fori(i,0,MAX_A-1) nexts[i]=o.nexts[i];
			return *this;
		}

		bool hasNext(int x) {
			return nexts[x]>-1;
		}
	};

	int nSAM, last, id[MAX_SAM], c[MAX_N];
	State sam[MAX_SAM];
	ll f[MAX_SAM];

	void init() {
		nSAM = 1;	last = 0;
		sam[0] = State();
		f[0] = 0;
	}

	void add(int x) {
		int cur = nSAM++;
		sam[cur] = State();
		sam[cur].len = sam[last].len + 1;
		f[cur] = 1;

		int p = last;
		for (; p != -1 && !sam[p].hasNext(x); p = sam[p].link)
			sam[p].nexts[x] = cur;

		if (p == -1) sam[cur].link = 0;
		else {
			int q = sam[p].nexts[x];
			if (sam[q].len != sam[p].len + 1) {
				int clone = nSAM++;
				sam[clone] = sam[q];
				sam[clone].len = sam[p].len + 1;
				f[clone] = 0;
				for (; p != -1 && sam[p].nexts[x] == q; p = sam[p].link)
					sam[p].nexts[x] = clone;
				sam[cur].link = sam[q].link = clone;
			}
			else sam[cur].link = q;
		}
		last = cur;
	}

	void topoSort() { // by length
		filla(c, 0);
		fori(i,0,nSAM-1) ++c[sam[i].len];
		fori(i,1,MAX_N-1) c[i] += c[i-1];
		fori(i,0,nSAM-1) id[--c[sam[i].len]] = i;
	}

	void calNumberOfOccurrences() {
		topoSort();
		ford(i,nSAM-1,0) {
			int u=id[i];
			f[sam[u].link] += f[u];
		}
	}
};


const int MAX_N = 1011;
const ll oo = 1e18;


int n, m, nSAM;
string pattern;
vector<pair<pair<int, char>, int> > e[MAX_N];
ll d[MAX_N][2*MAX_N];
SAM sam;


struct cmp {
	bool operator() (const pii &a, const pii &b) const {
		if (d[a.fr][a.sc] != d[b.fr][b.sc])
			return d[a.fr][a.sc] < d[b.fr][b.sc];
		return a < b;
	}
};
set<pii, cmp> heap;


ll solve() {
	fori(i,1,n) fori(j,0,nSAM-1) d[i][j]=oo;
	d[1][0]=0;
	heap.clear();
	heap.insert(mp(1, 0));
	while (!heap.empty()) {
		int u=heap.begin()->fr, i=heap.begin()->sc;
		heap.erase(heap.begin());
		if (u==n) return d[u][i];
		foreach(it, e[u]) {
			int x = it->fr.sc - 'a';
			if (!sam.sam[i].hasNext(x)) continue;
			int j = sam.sam[i].nexts[x], v = it->sc;
			ll tmp=d[u][i] + sam.f[j] * it->fr.fr;
			if (tmp<d[v][j]) {
				heap.erase(mp(v, j));
				d[v][j]=tmp;
				heap.insert(mp(v, j));
			}
		}
	}
	return oo;
}


int main() {
#ifdef DEBUG
	freopen("shortest-path-revisited.in", "r", stdin);
	freopen("shortest-path-revisited.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> m;
	fori(i,1,m) {
		int x, y, w;
		char c;
		cin >> x >> y >> w >> c;
		e[x].pb(mp(mp(w, c), y));
		e[y].pb(mp(mp(w, c), x));
	}

	cin >> pattern;
	int len=sz(pattern);
	sam.init();
	fori(i,0,len-1)
		sam.add(pattern[i]-'a');
	sam.calNumberOfOccurrences();
	nSAM = sam.nSAM;

	cout << solve() << endl;

	return 0;
}