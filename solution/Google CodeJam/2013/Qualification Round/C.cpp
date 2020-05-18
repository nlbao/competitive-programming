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
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int a[1000];
ll list[10000007];

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }

bool is_palin(ll n) {
    int m = 0;
    while (n > 0) {
        a[m++] = n%10;
        n /= 10;
    }
    int i = 0, j = m-1;
    while (i < j) {
        if (a[i] != a[j]) return false;
        ++i;    --j;
    }
    return true;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
#endif
    int c = 0;
    ll limit = 100000000000000LL;
    for(ll i = 1; i < limit; ++i) {
        ll j = i*i;
        if (j > limit) break;
        if (is_palin(i) && is_palin(j)) list[++c] = j;
    }

    cout << c << endl;
    foru(i,1,c) cout << list[i] << endl;

    int nTest = read();
    foru(test_id,1,nTest) {
        ll a = read(), b = read(), res = 0;
        /*foru(i,1,b) if (is_palin(i)) {
            int j = i*i;
            if (j > b) break;
            if (j < a) continue;
            if (is_palin(j)) ++res;
        }*/
        int l = 1, r = c, t1 = c, t2 = 1;
        while (l <= r) {
            int mid = (l+r)>>1;
            if (list[mid] < a) l = mid+1;
            else {
                t1 = mid;
                r = mid-1;
            }
        }

        l = 1;  r = c;
        while (l <= r) {
            int mid = (l+r)>>1;
            if (list[mid] > b) r = mid-1;
            else {
                t2 = mid;
                l = mid+1;
            }
        }

        if (t1 <= t2) res = t2-t1+1;
        printf("Case #%d: %d\n",test_id,res);
    }
    return 0;
}
