#pragma comment(linker, "/STACK:1024000000")
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
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 104;
const int MAX_COST = 204;
const int MAX_A = 28;


struct node {
	int id, pos, cost;
	node() {}
	node (int id, int pos, int cost) : id(id), pos(pos), cost(cost) {}
};


int nA, nW, crrTurn;
int cost[MAX_A], revA[MAX_A];
int score[MAX_N], w[MAX_N][MAX_N], p[MAX_N], len[MAX_N], kmp[MAX_N][MAX_N];
int g[MAX_N][MAX_N], f[MAX_N][MAX_N][MAX_COST], turn[MAX_N][MAX_N][MAX_COST];
vector<node> e[MAX_N][MAX_N][MAX_A];


void init() {
	fori(id,1,nW)
		fori(pos,1,len[id]) {
			g[id][pos]=0;
			fori(i,1,nW) if (len[i]<=pos) {
				bool ck=1;
				fori(k,1,len[i]) if (w[id][pos-len[i]+k] != w[i][k]) {
					ck=0;
					break;
				}
				if (ck) g[id][pos]+=score[i];
			}
			// cout << "	" << id << " " << pos << ": " << g[id][pos] << endl;
		}

	fori(id,1,nW) {
		kmp[id][1]=0;
		int j=0;
		fori(i,2,len[id]) {
			while (j>0 && w[id][j+1]!=w[id][i]) j=kmp[id][j];
			if (w[id][j+1]==w[id][i]) ++j;
			kmp[id][i]=j;
		}
	}

	fori(id,1,nW) {
		fori(i,1,nW) p[i]=0;
		fori(pos,1,len[id]) {
			fori(i,1,nA) e[id][pos][i].clear();
			fori(i,1,nW) {
				while (p[i]>0 && w[i][p[i]+1]!=w[id][pos]) p[i]=kmp[i][p[i]];
				if (w[i][p[i]+1]==w[id][pos]) ++p[i];
			}
			fori(i,1,nW) {
				int j=p[i];
				if (j==len[i]) j=kmp[i][j];
				++j;
				// if (id==2 && pos==3 && i==2) cout << "!!!! " << p[i] << " " << j << endl;
				if (j<=len[i]) {
					int k=revA[w[i][j]];
					if (id==1 || i==1) continue;
					if (id==3 || i==3) continue;
					e[id][pos][k].pb(node(i, j, cost[k]));
					// cout << "edge: " << id << " " << pos << " " << k << " ---> " << i << " " << j << " " << cost[k] << endl;
				}
				int k=revA[w[i][1]];
				e[id][pos][k].pb(node(i, 1, cost[k]));
				// cout << "edge 2: " << id << " " << pos << " " << k << " ---> " << i << " " << 1 << " " << cost[k] << endl;
			}
		}
	}
}


int solve(int id, int pos, int limit) {
	// cout << id << " " << pos << " " << limit << endl;
	if (limit<0) return 0;
	if (limit==0) return g[id][pos];
	if (turn[id][pos][limit]==crrTurn) {
		return f[id][pos][limit];
	}
	int tmp=0;
	fori(i,1,nA) {
		// cout << "	" << i << endl;
		foreach(it, e[id][pos][i]) {
			if (it->id<0) continue;
			tmp=max(tmp, solve(it->id, it->pos, limit-it->cost));
		}
	}
	f[id][pos][limit]=tmp+g[id][pos];
	// cout << id << " " << pos << " " << limit << ": " << f[id][pos][limit] << endl;
	// cout << "		" << turn[id][pos][limit] << " " << crrTurn << endl;
	turn[id][pos][limit]=crrTurn;
	return f[id][pos][limit];
}


int main() {
#ifdef DEBUG
	freopen("6806.in", "r", stdin);
	freopen("6806.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	crrTurn=0;
	filla(turn, 0);
	string s;

	int nTest=read(), limit;
	fori(testid,1,nTest) {
		cin >> nA >> nW >> limit;
		filla(revA, 0);
		fori(i,1,nA) {
			cin >> s >> cost[i];
			revA[s[0]-'A'+1]=i;
		}
		fori(i,1,nW) {
			cin >> s >> score[i];
			len[i]=sz(s);
			fori(k,1,len[i]) w[i][k]=s[k-1]-'A'+1;
		}
		init();
		++crrTurn;
		int ans=0;
		fori(i,1,nW) ans=max(ans, solve(i, 1, limit-cost[revA[w[i][1]]]));
		cout << "Case #" << testid << ": " << ans << endl;
	}

	return 0;
}