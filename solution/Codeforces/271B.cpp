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

const int MAX_N = 555;
const int MAX_P = 200005;

int a[MAX_N][MAX_N];
bool ok[MAX_P];

int read() {   int x;   scanf("%d",&x);   return x;   }
void read(int &x) {  scanf("%d",&x);    }
void readln(int &x) {   scanf("%d\n",&x);   }

int cal(int x) {
    foru(i,x,MAX_P-1)
        if (ok[i]) return i-x;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("271B.in", "r", stdin);
    freopen("271B.out", "w", stdout);
#endif
    fill(ok,true);
    ok[0] = ok[1] = false;
    foru(i,2,MAX_P-1)
        if (ok[i]) {
            ll j = ll(i)*ll(i);
            while (j < MAX_P) {
                ok[j] = false;
                j += i;
            }
        }

    int n = read(), m = read(), res = 1000000000;
    foru(i,1,n)
        foru(j,1,m) read(a[i][j]);

    foru(i,1,n) {
        int sum = 0;
        foru(j,1,m) sum += cal(a[i][j]);
        res = min(res,sum);
    }

    foru(i,1,m) {
        int sum = 0;
        foru(j,1,n) sum += cal(a[j][i]);
        res = min(res,sum);
    }

    cout << res;
    return 0;
}
