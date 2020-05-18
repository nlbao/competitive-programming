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

const int MAX_N = 13;
const int MAX_M = 33;
const int oo = int(1e7);

vi a[MAX_N];
int szA[MAX_N], c[MAX_M], cast[MAX_N];


int main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
#endif
    int nTest = read();
    foru(test_id, 1, nTest) {
    	int n, m;
    	scanf("%d%d", &n, &m);
    	rep(i, n) {
    		a[i].clear();
    		scanf("%d", &szA[i]);
    		rep(j, szA[i]) a[i].pb(read());
    		scanf("%d", &cast[i]);
    	}
    	foru(i, 1, m) scanf("%d", &c[i]);

    	int res = 0;
    	rep(x, n) {
    		int minC = oo;
    		rep(i, szA[x])
    			minC = min(minC, c[a[x][i]]);
    		if (minC < oo)
    			res += minC*cast[x];
    	}
    	printf("%d\n", res);
    }
    return 0;
}
