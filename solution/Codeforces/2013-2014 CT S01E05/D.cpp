#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
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

const ll BASE = 10007;
const int MAX_N = 20;
const int oo = 1000000000;

char s[MAX_N], t[MAX_N];
map<ll, bool> qa, qb;
int f[1<<MAX_N];
ll a[MAX_N], b[MAX_N];
ll hb[MAX_N][MAX_N], gb[MAX_N][MAX_N];

ll num(char x) {
	if (x == 'A') return 1;
	if (x == 'C') return 2;
	if (x == 'G') return 3;
	return 4;
}

bool ok_a(ll x) {
	return qa.find(x) != qa.end();
}

bool ok_b(ll x) {
	return qb.find(x) != qb.end();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
#endif
    int nTest = read();
    gets(s);
    rep(test_id, nTest) {
    	gets(s);
    	gets(t);
    	//cout << s << endl << t << endl;
    	int m = strlen(s), n = strlen(t);
    	rep(i, m) a[i] = num(s[i]);
    	rep(i, n) b[i] = num(t[i]);

    	qa.clear();
    	rep(i, m) {
    		ll h = 0, g = 0, p = 1;
    		foru(j, i, m-1) {
    			h = h*BASE + a[j];
    			g += p*a[j];
    			p *= BASE;
    			qa[h] = qa[g] = true;
    		}
    	}

    	rep(i, n) {
    		ll h = 0, g = 0, p = 1;
    		foru(j, i, n-1) {
    			h = h*BASE + b[j];
    			g += p*b[j];
    			p *= BASE;
    			hb[i][j] = h;
    			gb[i][j] = g;
    		}
    	}

    	int final = (1<<n)-1;
    	rep(i, final+1) f[i] = oo;
    	rep(i, n)
    		for(int j = i, x = 0; j < n; ++j) {
    			x += (1<<j);
    			if (ok_a(hb[i][j]))
    				f[x] = 1;
    		}

    	rep(x, final) if (f[x] < oo) {
    		qb.clear();
    		rep(i, n)
    			for(int j = i; j < n && (x&(1<<j)); ++j)
    				qb[hb[i][j]] = qb[gb[i][j]] = true;

    		rep(i, n) {
    			for(int j = i, y = x; j < n && !(x&(1<<j)); ++j) {
    				y += (1<<j);
    				if (!(ok_a(hb[i][j]) || ok_b(hb[i][j]))) break;
    				f[y] = min(f[y], f[x] + 1);
    			}
    		}
    	}

    	if (f[final] == oo) printf("impossible\n");
    	else printf("%d\n",f[final]);
    }
    return 0;
}