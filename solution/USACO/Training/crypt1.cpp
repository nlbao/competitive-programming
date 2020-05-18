/*
    ID: storm59061
    LANG: C++
    TASK: crypt1
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

int n, res = 0;
int a[11], f[11];
bool ok[11];

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }


bool in_set(int x, int limit) {
    if (x > limit) return false;
    while (x > 0) {
        if (!ok[x%10]) return false;
        x /= 10;
    }
    return true;
}

int toNum(int i, int j) {
    int x = 0;
    foru(k,i,j) x = x*10 + f[k];
    return x;
}


bool check() {
    int x = toNum(1,3);
    foru(i,4,5)
        if (!in_set(x*toNum(i,i),999)) return false;
    if (!in_set(x*toNum(4,5),9999)) return false;
    return true;
}


void tryf(int i) {
    if (i > 5) {
        if (check()) ++res;
        return;
    }
    rep(j,n) {
        f[i] = a[j];
        tryf(i+1);
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);
#endif
    n = read();
    fill(ok,false);
    rep(i,n) ok[read(a[i])] = true;
    tryf(1);
    cout << res << endl;
    return 0;
}
