#include <sstream>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>
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

const int MAX_N = 1000006;

char a[MAX_N], b[MAX_N];
int c[MAX_N][27];

ll gcd(ll a, ll b) {
    if (a == 0 || b == 0) return a+b;
    return gcd(b, a%b);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("356B.in", "r", stdin);
    freopen("356B.out", "w", stdout);
#endif
    ll n, m;
    cin >> n >> m;
    gets(a);
    gets(a);
    gets(b);

    ll la = strlen(a), lb = strlen(b);
    ll g = gcd(la, lb);
    ll min_len = la/g*lb;
    ll p = la*n/min_len;

    ll res = min_len;
    fill(c, 0);
    rep(i, la) ++c[i%g][a[i]-'a'];
    rep(i, lb) res -= c[i%g][b[i]-'a'];

    cout << res*p << endl;
    return 0;
}
