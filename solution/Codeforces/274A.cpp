#include <sstream>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <deque>
#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
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

const int MAX_N = 100005;

int a[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }


int main() {
#ifndef ONLINE_JUDGE
    freopen("274A.in", "r", stdin);
    freopen("274A.out", "w", stdout);
#endif
    int n = read(), k = read(), res = 0;
    rep(i,n) read(a[i]);
    sort(a,a+n);
    rep(i,n) if (a[i]) {
        ++res;
        int l = i+1, r = n-1;
        ll tmp = ll(a[i])*ll(k);
        while (l <= r) {
            int mid = (l+r)>>1;
            if (a[mid] == tmp) {
                a[mid] = 0;
                break;
            }
            else if (a[mid] < tmp) l = mid+1;
            else r = mid-1;
        }
    }
    cout << res;
    return 0;
}
