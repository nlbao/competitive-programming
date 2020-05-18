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

const int MAX_N = 55;

struct matrix{
	int m, n;
	int val[MAX_N][MAX_N];
	matrix (int x = 0, int y = 0) {
		m = x;
		n = y;
		fill(val, 0);
	}
};

int n, module, a, b, c, t;
int s[MAX_N];

matrix mul(matrix a, matrix b) {
	matrix c(a.m, b.n);
	foru(k,1,a.n)
		foru(i,1,a.m)
			foru(j,1,b.n)
				c.val[i][j] = (c.val[i][j] + a.val[i][k]*b.val[k][j])%module;
	return c;
}

matrix pow(matrix a, int n) {
	if (n == 1)
		return a;
	matrix b = pow(a, n>>1);
	b = mul(b, b);
	if (n&1) b = mul(b, a);
	return b;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("6184.in", "r", stdin);
    freopen("6184.out", "w", stdout);
#endif
	for(;;) {
		scanf("%d%d%d%d%d%d", &n, &module, &a, &b, &c, &t);
		if (n < 1) break;
    	foru(i,1,n) scanf("%d", &s[i]);

    	if (t < 1) {
    		foru(i,1,n-1) printf("%d ", s[i]);
    		printf("%d\n", s[n]);
    		continue;
    	}

    	matrix base(n, n);
    	base.val[0][1] = a;
    	base.val[1][1] = b;
    	base.val[2][1] = c;
    	foru(j,2,n)
    		foru(i,1,n)
    			base.val[i][j] = base.val[i-1][j-1];
    	base = pow(base, t);

    	matrix res(1, n);
    	foru(i,1,n) res.val[1][i] = s[i];
    	res = mul(res, base);

    	foru(i,1,n-1) printf("%d ", res.val[1][i]);
    	printf("%d\n", res.val[1][n]);
    }
    return 0;
}