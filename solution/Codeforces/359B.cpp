#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <queue>
#include <deque>
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

const int MAX_N = 100005;

int n, k, limit;
int a[MAX_N];
bool ok[MAX_N];

int find(int x) {
	ford(i, limit, x+1)
		if (ok[i] && ok[i-x]) {
			ok[i] = ok[i-x] = false;
			return i;
		}
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("359B.in", "r", stdin);
    freopen("359B.out", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    limit = 2*n;

    int m = 0;
    fill(a, 0);
    fill(ok, true);
    ford(i, 20, 0)
    	if ((k>>i)&1) {
    		int x = 1<<i;
    		int y = find(x);
    		a[++m] = y;
    		a[++m] = y-x;
 			y = find(x);
    		a[++m] = y-x;
    		a[++m] = y;
    	}

    for(int i = m+1, j = 1; i <= limit; ++i) {
    	while (j <= limit && !ok[j]) ++j;
    	if (j > limit) break;
    	a[i] = j++;
    }

    foru(i, 1, limit) printf("%d ", a[i]);
    return 0;
}