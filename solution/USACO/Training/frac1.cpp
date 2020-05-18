/*
    ID: storm59061
    LANG: C++
    TASK: frac1
*/
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


int gcd(int a, int b) {
    if (a == 0 || b == 0) return a+b;
    return gcd(b,a%b);
}

struct fraction {
    int a, b;
    fraction (int x, int y) {
        int d = gcd(x,y);
        a = x/d;
        b = y/d;
        if (a == 0) b = 1;
    }
    bool operator<(const fraction &other) const {
        return a*other.b < b*other.a;
    }
};


int main() {
#ifndef ONLINE_JUDGE
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);
#endif
    int n = read();
    vector<fraction> f;
    foru(i,1,n)
        foru(j,0,i)
            f.pb(fraction(j,i));
    sort(all(f));

    int sz = size(f);
    fraction pre(n+1,n);
    rep(i,sz) {
        if (f[i].a != pre.a || f[i].b != pre.b)
            printf("%d/%d\n",f[i].a,f[i].b);
        pre = f[i];
    }
    return 0;
}
