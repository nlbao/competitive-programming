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

const int MAX_N = 1000006;

int a[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }


int main() {
#ifndef ONLINE_JUDGE
    freopen("292A.in", "r", stdin);
    freopen("292A.out", "w", stdout);
#endif
    int n = read(), time = 0, s = 0, q = 0;
    fill(a,0);
    rep(i,n) {
        int t = read();
        read(a[t]);
    }

    foru(i,1,1000000) {
        if (q > 0) {
            --q;
            time = i;
        }
        if (a[i] > 0) {
            q += a[i];
            s = max(s,q);
            time = i;
        }

    }
    time += q;

    cout << time << " " << s;
    return 0;
}
