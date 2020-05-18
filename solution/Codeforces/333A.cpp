#include <sstream>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
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

ll p[37];

int main() {
#ifndef ONLINE_JUDGE
    freopen("333A.in", "r", stdin);
    freopen("333A.out", "w", stdout);
#endif
    ll n;
    cin >> n;
    if (n < 3) {
        cout << 1;
        return 0;
    }

    p[0] = 1LL;
    foru(i,1,35) p[i] = p[i-1]*3LL;
    int first = -1, last;
    ll m = n;
    ford(i,35,0)
        while (n >= p[i]) {
            n -= p[i];
            if (first == -1) first = i;
            last = i;
        }
    if (first == last) cout << 1;
    else cout << m/p[last+1] + 1LL;
    return 0;
}
