#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 1e5+5;


int n, nQ;
int a[MAX_N], f[MAX_N];


int main() {
#ifdef DEBUG
	freopen("special-lcm-of-subarray.in", "r", stdin);
	freopen("special-lcm-of-subarray.out", "w", stdout);
#endif
	scanf("%d%d", &n, &nQ);
	int p1=-1, p2;
	f[0]=1;
	for (int i = 1; i <= n; ++i) {
		a[i]=read();
		if (a[i]==3) {
			if (p1<0) p1=i;
			else p2=i;
		}
		f[i]=f[i-1];
		if (a[i]!=3) f[i]=(f[i]*a[i])%3;
	}

	while (nQ--) {
		int l, r;
		scanf("%d%d", &l, &r);
		int c=int(l<=p1 && p1<=r) + int(l<=p2 && p2<=r);
		if (c==1) printf("0\n");
		else printf("%d\n", (f[r]*f[l-1])%3);
	}
	return 0;
}