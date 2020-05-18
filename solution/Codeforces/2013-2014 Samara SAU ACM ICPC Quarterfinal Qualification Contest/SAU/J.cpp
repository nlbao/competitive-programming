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

#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vecint;
typedef pair<int, int> ppi;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define sz(a) (int)a.size()
#define pb push_back
#define sqr(x) (x)*(x)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }

int maxVal, res, n;

int main() {
#define DEBUG
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    cin >> n;
    maxVal = -1;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        if (a > maxVal) res = max(res, b), maxVal = a;
    }
    cout << res << endl;

	return 0;
}

