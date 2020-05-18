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

const int MAX_N = 222;

int x[MAX_N], y[MAX_N];
//vector< pair<double,double> > a;
vii a;

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }


int main() {
#ifndef ONLINE_JUDGE
    freopen("277B.in", "r", stdin);
    freopen("277B.out", "w", stdout);
#endif
    int n = read(), m = read();

    if (n == 2*m) {
        cout << -1;
        return 0;
    }

    fill(x,0);
    fill(y,0);
    x[2] = 1;   y[2] = 1;
    double d = 3.1416/180;
    foru(i,3,m) {
        double alpha = atan(y[i-1]/x[i-1]);
        x[i] = int(cos(alpha-d));
        y[i] = int(sin(alpha-d));
    }
    foru(i,1,4) {
        x[m+i] = x[i];
        y[m+i] = y[i];
    }

    a.clear();
    foru(i,1,m) a.pb(mp(x[i],y[i]));
    foru(i,2,m-1) a.pb(mp((x[1]+x[i]+x[i+1])/3, (y[1]+y[i]+y[i+1])/3));
    if (size(a) < n) a.pb(mp(100000000,100000000));

    int sz = size(a);
    rep(i,sz) printf("%.8f %.8f\n",a[i].fr,a[i].sc);
    return 0;
}
