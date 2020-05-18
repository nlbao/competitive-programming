#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <utility>
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


int main() {

#ifndef ONLINE_JUDGE
    freopen("352C.in", "r", stdin);
    freopen("352C.out", "w", stdout);
#endif
    int n = read(), m = 2*n, p = 0;
    double s0 = 0, s = 0;
    rep(i, m) {
    	double a;
    	scanf("%lf", &a);
    	s0 += a;
    	s += floor(a);
    	p += ceil(a)-floor(a);
        // printf("%.3lf\n", a);
    }

	double res = 1000000000.0;
    int l = max(0, n-min(n,m-p)), r = min(n,p);
    foru(i,l,r) {
    	double tmp = s-s0+i;
    	if (tmp < 0) tmp = -tmp;
    	res = min(res, tmp);
    }
    printf("%.3lf\n", res);
    return 0;
}