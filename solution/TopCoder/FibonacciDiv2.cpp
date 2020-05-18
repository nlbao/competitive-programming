#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vecint;
typedef pair<int, int> ppi;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }


const int MAX_N = int(1e6+6);
const int MAX_F = int(1e2+2);

int f[MAX_F];
bool ok[MAX_N];


class FibonacciDiv2 {
public:
	int find(int N) {
		fill(ok, false);
		f[0] = 0;
		f[1] = 1;
		ok[0] = ok[1] = true;
		for (int i = 2; i < MAX_F && f[i-1] < MAX_N; ++i) {
			ok[f[i-1]] = true;
			f[i] = f[i-1] + f[i-2];
		}
		int res = MAX_N;
		for (int i = N; i >= 0; --i)
			if (ok[i]) {
				res = min(res, N-i);
				break;
			}
		for (int i = N; i < MAX_N; ++i)
			if (ok[i]) {
				res = min(res, i-N);
				break;
			}
		return res;
	}
};


int main() {
#ifdef DEBUG
	freopen("FibonacciDiv2.in", "r", stdin);
	freopen("FibonacciDiv2.out", "w", stdout);
#endif
	int nTest = read();
	FibonacciDiv2 main_class;
	for (int test_id = 0; test_id < nTest; ++test_id) {
		int n = read();
		printf("%d\n", main_class.find(n));
	}
	return 0;
}