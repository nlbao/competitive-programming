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

#define filla(a,x) memset(a, (x), sizeof(a))
#define foreach(it, X) for(typeof((X).begin()) it = (X).begin(); (it) != (X).end(); (it)++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = 111;

string a[MAX_N];


int main() {
#ifdef DEBUG
	freopen("grid-challenge.in", "r", stdin);
	freopen("grid-challenge.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		int n = read();
		getline(cin, a[0]);
		for (int i = 0; i < n; ++i) {
			getline(cin, a[i]);
			sort(a[i].begin(), a[i].end());
		}
		bool ok = true;
		for (int i = 1; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (a[i][j] < a[i-1][j]) {
					ok = false;
					break;
				}
		if (ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}