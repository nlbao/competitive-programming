
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
typedef pair<int, int> ii;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define sz(a) (int)a.size()
#define pb push_back
#define sqr(x) (x)*(x)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }

const int MAXN = 200005;

int n;
vector <int> res;
int a[MAXN], b[MAXN], c[MAXN];
vector <ii> arr;

ii findMin(int x, int y, int z) {
    vector <int> a(3, 0); a[0] = x; a[1] = y; a[2] = z;
    sort(a.begin(), a.end());
    return ii(a[0], a[1]);
}
ii findMax(int x, int y, int z) {
    vector <int> a(3, 0); a[0] = x; a[1] = y; a[2] = z;
    sort(a.begin(), a.end());
    return ii(a[1], a[2]);
}

int main() {
#define DEBUG
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    cin >> n;
    ii choose(-1, -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        ii x = findMin(a[i], b[i], c[i]);
        choose.first = max(choose.first, x.first);
        choose.second = max(choose.second, x.second);
    }
    for (int i = 0; i < n; i++) {
        ii y = findMax(a[i], b[i], c[i]);
        if (y.first > choose.first && y.second > choose.second) res.pb(i + 1);
    }
    cout << sz(res) << endl;
    for (int i = 0; i < sz(res) - 1; i++) cout << res[i] << " ";
    cout << res[sz(res)-1] << endl;

	return 0;
}
