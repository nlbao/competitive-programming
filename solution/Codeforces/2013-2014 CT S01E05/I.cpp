#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
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

const int MAX_N = 204;
const double oo = 1000000000000000000.0;

int n, c;
double x[MAX_N];
double g[MAX_N][MAX_N], f[MAX_N][MAX_N];


int main() {
#ifndef ONLINE_JUDGE
    freopen("I.in", "r", stdin);
    freopen("I.out", "w", stdout);
#endif
    int nTest = read();
    rep(test_id, nTest) {
    	scanf("%d%d", &n, &c);
    	foru(i,1,n) x[i] = read();

    	fill(g, 0);
    	foru(i,1,n)
    		foru(j,i+2,n)
    			// g[i][j] = (j-i-1)*(j*x[i]-i*x[j] + (i+j)*(j-i-1)/2)/(j-i);
    			foru(k,i+1,j-1) {
    				double tmp = x[k] - (x[i] + (k-i)*(x[j]-x[i])/(j-i));
    				if (tmp < 0) tmp = -tmp;
    				g[i][j] += tmp;
    			}

    	f[1][0] = oo;
    	f[1][1] = 0;
    	foru(i,2,n) {
    		f[i][1] = oo;
    		f[i][2] = g[1][i];
    		foru(x, 3, min(i,c)) {
    			f[i][x] = oo;
    			foru(j, x-1, i-1)
    				f[i][x] = min(f[i][x], f[j][x-1] + g[j][i]);
            }
    	}
    	printf("%.4lf\n", f[n][c]/n);
    }
    return 0;
}