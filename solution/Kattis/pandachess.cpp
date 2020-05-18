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
#define lowbit(x) ((x)&(-(x)))


const int MAX_N = 4e5+5;


int n, m, nD;
int f[MAX_N], c[MAX_N], p[MAX_N], deg[MAX_N];
map<string, int> id;
string a[MAX_N], b[MAX_N];
vector<int> e[MAX_N];
bool ok[MAX_N];
queue<int> q;


void update(int i, int val) {
    while (i<=n) {
        f[i]=max(f[i], val);
        i += lowbit(i);
    }
}


int get(int i) {
    int ans=0;
    while (i>0) {
        ans=max(ans, f[i]);
        i -= lowbit(i);
    }
    return ans;
}


int main() {
#ifdef DEBUG
    freopen("H.in", "r", stdin);
#endif // DEBUG
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll ans=0;
    cin >> n >> m >> nD;
    id.clear();
    fori(i,1,m) {
        cin >> a[i] >> b[i];
        id[a[i]];
        id[b[i]];
    }
    int nID=0;
    foreach(it, id) it->sc = ++nID;

    int nC=0;
    filla(ok, 0);
    string tmp;
    map<string, int>::iterator it;
    fori(i,1,n) {
        cin >> tmp;
        it=id.find(tmp);
        if (it==id.end()) {
            ++ans;
            continue;
        }
        int x=it->sc;
        c[++nC]=x;
        ok[x]=1;
    }
    n=id.size();
    fori(i,1,n) if (!ok[i]) ++ans;

    // topo-sort
    filla(deg, 0);
    fori(i,1,m) {
        int x=id[a[i]], y=id[b[i]];
        if (x==y) continue;
        e[x].pb(y);
        ++deg[y];
    }
    fori(i,1,nID) if (deg[i]==0)
        q.push(i);

    int nTime=0;
    while (!q.empty()) {
        int u=q.front();    q.pop();
        p[u]=++nTime;
        foreach(it, e[u]) {
            int v=*it;
            --deg[v];
            if (deg[v]!=0) continue;
            q.push(v);
        }
    }

    // longest increasing subsequence
    int longest=0;
    filla(f, 0);
    fori(i,1,nC) {
        int x=p[c[i]];
        int t=get(x-1)+1;
        update(x, t);
        longest=max(longest, t);
    }

    int nDup=0;
    filla(ok, 0);
    fori(i,1,nC)
        if (ok[c[i]]) ++nDup;
        else ok[c[i]]=1;
    ans += nDup;
    ans += 2LL*(nC-nDup-longest);
    cout << ans << endl;
}