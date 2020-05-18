#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <queue>
#include <deque>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector< pair<int, int> > vii;

#define foru(i,a,b) for(int i = int(a); i <= int(b); ++i)
#define ford(i,b,a) for(int i = int(b); i >= int(a); --i)
#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define all(a) a.begin(),a.end()
#define size(a) int(a.size())
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

const int MAX_N = 63;

ll n, R, low, height;
vector<ll> res;
map<ll, bool> q;

void add(ll x) {
	if ((x >= 1) && (x <= height) && (q.find(x) == q.end()))
		res.pb(x);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("D.in", "r", stdin);
    //freopen("output.out", "w", stdout);
#endif
    ll n, R;
    cin >> n >> R;
    low = 1LL<<n;
    height = (1LL<<(n+1)) - 1;

    rep(i, R) {
    	ll x;
    	cin >> x;
    	while (x > 0) {
    		q[x] = true;
    		x = x>>1;
    	}
    }

    tr(q, it) {
    	ll x = it->fr;
    	add(x<<1);
    	add((x<<1) + 1);
    }

    //cout << (1LL<<62) << endl;

    sort(all(res));
    int m = size(res);
    rep(i, m) printf("%lld ", res[i]);
    return 0;
}
