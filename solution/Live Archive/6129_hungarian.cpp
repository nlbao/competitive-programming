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
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


struct Hungarian {		// MAX-cost perfect-matching
	static const int N = 555, oo = 1e9;
	int n, max_match, cost[N][N], q[N];   //n workers and n jobs
	int lx[N], ly[N], xy[N], yx[N], slack[N], slackx[N], prev[N];
	bool S[N], T[N];	//sets S and T in algorithm

	void init(int nn) {    n=nn;	filla(cost, 0);    }
	void addEdge(int u, int v, int w) {    cost[u][v]=w;	}

	void updateLabels() {
		int delta = oo;
		fori(y,1,n) if (!T[y]) delta = min(delta, slack[y]);
		fori(x,1,n) if (S[x]) lx[x] -= delta;
		fori(y,1,n) if (T[y]) ly[y] += delta;
		fori(y,1,n) if (!T[y]) slack[y] -= delta;
	}

	void addToTree(int x, int prevx) {
		S[x] = 1;
		prev[x] = prevx;
		fori(y,1,n) if (lx[x] + ly[y] - cost[x][y] < slack[y]) {
			slack[y] = lx[x] + ly[y] - cost[x][y];
			slackx[y] = x;
		}
	}

	void initLabels() {
		filla(lx, 0);
		filla(ly, 0);
		fori(x,1,n) fori(y,1,n) lx[x] = max(lx[x], cost[x][y]);
	}

	void augment() {
		if (max_match == n) return;
		int root, wr = 0, rd = 0;
		filla(S, 0);
		filla(T, 0);
		filla(prev, -1);
		fori(x,1,n) if (xy[x] == -1) {
			q[wr++] = root = x;
			prev[x] = -2;
			S[x] = 1;
			break;
		}
		fori(y,1,n) {
			slack[y] = lx[root] + ly[y] - cost[root][y];
			slackx[y] = root;
		}

		int x, pos=0;
		while (!pos) {
			while (rd < wr && !pos) {
				x = q[rd++];
				fori(y,1,n) if (cost[x][y]==lx[x]+ly[y] && !T[y]) {
					if (yx[y] == -1) {
						pos=y;
						break;
					}
					T[y] = 1;
					q[wr++] = yx[y];
					addToTree(yx[y], x);
				}
			}
			if (pos) break;

			updateLabels();
			wr = rd = 0;
			fori(y,1,n) if (!T[y] && slack[y]==0) {
				if (yx[y] == -1) {
					x = slackx[y];
					pos=y;
					break;
				}
				else {
					T[y] = 1;
					if (!S[yx[y]]) {
						q[wr++] = yx[y];
						addToTree(yx[y], slackx[y]);
					}
				}
			}
		}

		if (pos) {
			max_match++;
			for (int cx=x, cy=pos, ty; cx!=-2; cx=prev[cx], cy=ty) {
				ty = xy[cx];
				yx[cy] = cx;
				xy[cx] = cy;
			}
			augment();
		}
	}

	int getMatch() {
		int ans = 0;	max_match = 0;
		filla(xy, -1);
		filla(yx, -1);
		initLabels();
		augment();
		fori(x,1,n) ans += cost[x][xy[x]];
		return ans;
	}
};


const int MAX_N = 111;


int n;
int a[2][MAX_N][MAX_N], assign[2][MAX_N];
int finish[MAX_N], cTime[MAX_N];
Hungarian matching;


int main() {
#ifdef DEBUG
	freopen("6129.in", "r", stdin);
	freopen("6129.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int testid=0;
	while (1) {
		cin >> n;
		if (n==0) break;
		fori(x,0,1) fori(i,1,n) fori(j,1,n) cin >> a[x][i][j];
		int idle=0;

		// phase 1
		matching.init(n);
		fori(i,1,n) fori(j,1,n) matching.addEdge(i, j, -a[0][i][j]);

		matching.getMatch();
		fori(u,1,n) {
			int v=matching.xy[u];
			assign[0][u]=v;
			finish[v]=cTime[u]=-matching.cost[u][v];
		}

		// phase 2
		matching.init(n);
		fori(i,1,n) fori(j,1,n) matching.addEdge(i, j, -(max(cTime[i], finish[j]) + a[1][i][j]));

		matching.getMatch();
		fori(u,1,n) {
			int v=matching.xy[u];
			assign[1][u]=v;
			int tmp=-matching.cost[u][v];
			idle += tmp-a[1][u][v]-cTime[u];
			cTime[u]=tmp;
		}

		cout << "Case " << ++testid << ":\n";
		fori(i,1,n) cout << "Worker " << i << ": " << assign[0][i] << " " << assign[1][i] << " " << cTime[i] << endl;
		cout << "Total idle time: " << idle << endl;
	}

	return 0;
}