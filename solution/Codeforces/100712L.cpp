#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fori(i,a,b) for(int i=(a); i<=(b); ++i)
#define ford(i,a,b) for(int i=(a); i>=(b); --i)
#define forix(i,a,b,x) for(int i=(a); i<=(b); i+=(x))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'

inline ll read() {  ll x;   cin >> x;   return x;   }


const int MAX_N = 1e5+5;
const int MAX_G = 4*MAX_N;
const int oo = 1e9;


int n, limit, pos, u, v;
int q[MAX_N], f[MAX_N], g[MAX_G];
string s;


void update(int k, int l, int r) {
    if (l>pos || r<pos) return;
    if (l==r) {
        g[k]=f[pos];
        return;
    }
    int mid=(l+r)>>1;
    int kl=k<<1, kr=kl+1;
    update(kl, l, mid);
    update(kr, mid+1, r);
    g[k]=min(g[kl], g[kr]);
}


int get(int k, int l, int r) {
    if (l>v || r<u || u>v) return oo;
    if (u<=l && r<=v) return g[k];
    int mid=(l+r)>>1;
    int kl=k<<1, kr=kl+1;
    return min(get(kl, l, mid), get(kr, mid+1, r));
}


int main() {
#ifdef DEBUG
    freopen("100712L.in", "r", stdin);
    freopen("100712L.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);   cin.tie(0);
    cout.precision(9);
    cout.setf(ios::fixed, ios::floatfield);

    int nTest=read();
    fori(testid,1,nTest) {
        cin >> n >> limit;
        cin >> s;
        fori(i,0,MAX_G-1) g[i]=oo;
        f[0]=0;
        int last=-oo;
        fori(i,1,n) {
            f[i]=f[i-1]+1;
            u=max(0, i-limit);
            v=last-1;
            if (u==0 && v>=u) {
                f[i]=min(f[i], f[0]+1);
                ++u;
            }
            f[i]=min(f[i], get(1,1,n) + 1);
            pos=i;
            update(1,1,n);
            if (i<n && s[i-1]==s[i]) last=i;
        }
        cout << f[n]-1 << endl;
    }

    return 0;
}