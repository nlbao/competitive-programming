#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define rep(i,n) for(int i=0;i<n;i++)
#define fori(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define foreach(it, x) for(__typeof(x.begin()) it=x.begin(); it!=x.end(); ++it)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sqr(x) ((x)*(x))


const int MAX_N = 1e5+5;
const int oo = 1e9;


int n, m;
vector<pii> e[MAX_N];
int d[MAX_N];
ll c[MAX_N];
set<pii> heap;


ll solve(int s, int t) {
    fori(i,1,n) {
        d[i]=oo;
        c[i]=0;
    }
    d[s]=0; c[s]=1;
    heap.insert(mp(d[s], s));
    while (!heap.empty()) {
        int u=heap.begin()->sc;
        heap.erase(heap.begin());
        foreach(it, e[u]) {
            int v=it->sc;
            int tmp=d[u]+it->fr;
            if (tmp>d[v]) continue;
            if (tmp==d[v]) {
                c[v]+=c[u];
                continue;
            }
            set<pii>::iterator p=heap.find(mp(d[v],v));
            if (p!=heap.end()) heap.erase(p);
            d[v]=tmp;
            heap.insert(mp(d[v],v));
            c[v]=c[u];
        }
    }
    return c[t];
}


int main() {
#ifdef DEBUG
    freopen("C.in", "r", stdin);
#endif // DEBUG
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    fori(i,1,m) {
        int x, y, c;
        cin >> x >> y >> c;
        ++x, ++y;
        e[x].pb(mp(c, y));
    }
    int s, t;
    cin >> s >> t;
    ++s, ++t;
    cout << solve(s, t) << endl;
}