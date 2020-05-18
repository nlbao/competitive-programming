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

const int MAX_N = 21;
const int MAX_M = 1<<MAX_N;
const int oo = int(1e9);

int a[MAX_N], f[MAX_M];

int main() {
#ifndef ONLINE_JUDGE
    freopen("G.in", "r", stdin);
    //freopen("output.out", "w", stdout);
#endif
    int nTest = read();
    foru(test_id, 1, nTest) {
    	int n = read(), m = (1<<n) - 1;

    	rep(i, n) {
    		a[i] = 1<<i;
    		int d = read();
    		rep(j, d)
    			a[i] |= 1<<(read()-1);
    	}

    	rep(i, m+1) f[i] = oo;
    	f[0] = 0;
    	rep(mask, m)
    		rep(i, n) {
    			int x = mask|a[i];
    			f[x] = min(f[x], f[mask] + 1);
    		}
    	printf("%d\n", f[m]);
    }
    return 0;
}
