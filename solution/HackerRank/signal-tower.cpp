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

const int MAX_N = 100005;
const double oo = 1000000000000000000;

int n, nQ;
int a[MAX_N], b[MAX_N];
double x[MAX_N], y[MAX_N], sx[MAX_N], sy[MAX_N];

double solve(int l, int r) {
    int n = r-l+1;
    foru(i,l,r) {
        x[i-l] = a[i]+b[i];
        y[i-l] = a[i]-b[i];
    }
    sort(x, x+n);
    sort(y, y+n);

    sx[0] = x[0];
    sy[0] = y[0];
    foru(i,1,n-1) {
        sx[i] = sx[i-1] + x[i];
        sy[i] = sy[i-1] + y[i];
    }

    double minX = oo, minY = oo;
    int mid = n/2;
    //rep(i,n) {
    foru(i, max(0,mid-2), min(n-1,mid+2)) {
        minX = min(minX, (i+1)*x[i] - sx[i] + (sx[n-1]-sx[i]) - (n-1-i)*x[i]);
        minY = min(minY, (i+1)*y[i] - sy[i] + (sy[n-1]-sy[i]) - (n-1-i)*y[i]);
    }

    return (minX + minY)/2;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("signal-tower.in", "r", stdin);
    freopen("signal-tower.out", "w", stdout);
#endif
    scanf("%d%d",&n,&nQ);
    foru(i,1,n) scanf("%d",&a[i]);
    foru(i,1,n) scanf("%d",&b[i]);
    rep(i,nQ) {
        int l = read(), r = read();
        printf("%.3f\n",solve(l,r));
    }
    return 0;
}
