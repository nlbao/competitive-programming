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


int main() {
#ifdef DEBUG
	freopen("VMCANDLE.in", "r", stdin);
	freopen("VMCANDLE.out", "w", stdout);
#endif
	ll k;
	cin >> k;
	ll x = ceil((sqrt(4.0*k + 1.0)+1.0)/2.0);
	cout << x+k-1 << endl;
	return 0;
}