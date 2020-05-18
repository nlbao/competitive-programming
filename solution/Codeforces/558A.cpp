#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 111;


pii a[MAX_N];


int main() {
#ifdef DEBUG
	freopen("558A.in", "r", stdin);
	freopen("558A.out", "w", stdout);
#endif
	int n = read();
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &a[i].first, &a[i].second);
	sort(a, a + n);

	int ans = 0, p = -1;
	for (int i = 0; i < n; ++i)
		if (a[i].first > 0) break;
		else if (a[i].first < 0) p = i;
	if (p == -1) {
		ans = a[0].second;
	}
	else {
		int m1 = p+1, m2 = n-m1;
		// left
		int t1 = min(m1, m2+1);
		int t2 = min(m1, m2);
		int s = 0;
		for (int i = p-t1+1; i <= p+t2; ++i)
			s += a[i].second;
		ans = max(ans, s);
		// right
		t1 = min(m1, m2);
		t2 = min(m1+1, m2);
		s = 0;
		for (int i = p-t1+1; i <= p+t2; ++i)
			s += a[i].second;
		ans = max(ans, s);
	}
	printf("%d\n", ans);
	return 0;
}