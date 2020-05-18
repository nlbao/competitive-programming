#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <bitset>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = int(1e3) + 3;
const int MAX_A = int(1e4);
const int oo = int(1e9);


int n;
int a[MAX_N];


int solve_1() {
	int ans = 0;
	for (int i = 1; i < n; ++i)
		if (a[i] < a[i-1])
			ans += a[i-1]-a[i];
	return ans;
}


int check(int value) {
	int sum = 0, t = a[0];
	for (int i = 1; i < n; ++i) {
		int x = min(value, t);
		t -= x;
		sum += x;
		if (a[i] < t)
			return oo;
		t = a[i];
	}
	return sum;
}


int solve_2() {
	int ans = oo;
	for (int x = 0; x <= MAX_A; ++x) {
		int t = check(x);
		ans = min(ans, t);
	}
	return ans;
}


int main() {
#ifdef DEBUG
	// freopen("A.in", "r", stdin);
	// freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-large.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif
	int nTest = read();
	for (int testid = 1; testid	<= nTest; ++testid) {
		n = read();
		for (int i = 0; i < n; ++i)
			a[i] = read();
		int ans1 = solve_1();
		int ans2 = solve_2();
		printf("Case #%d: %d %d\n", testid, ans1, ans2);
	}
	return 0;
}