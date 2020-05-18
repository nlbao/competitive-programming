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


const int MAX_N = 1e6+6;
const ll BASE = 1e4+7;


int n;
ll ans, h[MAX_N], value[MAX_N];
vector<int> e[2][MAX_N];
int a[MAX_N], stk[MAX_N];
bool ok[MAX_N];
set<ll> q;


inline void addEdge(vector<int> e[MAX_N], int u, int v) {
    e[u].pb(v);
}


void createTree(const string &s, vector<int> e[MAX_N]) {
    int pos=n, top=0, len=s.size(), u=0;
    fori(i,0,len-1) {
        if (s[i]=='(') {
            ++pos;
            if (top>0) addEdge(e, stk[top], pos);
            stk[++top]=pos;
            u=0;
        }
        else if (s[i]==')') {
            if (u>0) addEdge(e, stk[top], u);
            --top;
            u=0;
        }
        else if (s[i]==',') {
            if (u>0) addEdge(e, stk[top], u);
            u=0;
        }
        else u=u*10 + (s[i]-'0');
    }
}


void dfs_0(int u) {
    ok[u]=0;
    h[u]=value[u];
    foreach(it, e[0][u]) {
        int v=*it;
        if (!ok[v]) continue;
        dfs_0(v);
        h[u] += h[v];
    }
    q.insert(h[u]);
}


void dfs_1(int u) {
    ok[u]=0;
    h[u]=value[u];
    foreach(it, e[1][u]) {
        int v=*it;
        if (!ok[v]) continue;
        dfs_1(v);
        h[u] += h[v];
    }
    if (q.find(h[u])!=q.end())
        ++ans;
}


int main() {
#ifdef DEBUG
    freopen("J.in", "r", stdin);
#endif // DEBUG
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    string s;
    fori(i,0,1) {
        cin >> s;
        createTree(s, e[i]);
    }
    filla(value, 0);
    value[1]=BASE;
    fori(i,2,n) value[i] = value[i-1] * BASE;

    ans=0;
    q.clear();
    filla(ok, 1);
    dfs_0(n+1);
    filla(ok, 1);
    dfs_1(n+1);
    cout << ans << endl;
}