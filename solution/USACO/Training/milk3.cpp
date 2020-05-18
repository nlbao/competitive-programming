/*
    ID: storm59061
    LANG: C++
    TASK: milk3
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

const int MAX_N = 22;

int A, B, C;
bool res[MAX_N];
bool ok[MAX_N][MAX_N][MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }


void tryf(int a, int b, int c) {
    if (ok[a][b][c]) return;
    ok[a][b][c] = true;
    if (a == 0) res[c] = true;

    tryf(a-min(a,B-b),b+min(a,B-b),c);
    tryf(a-min(a,C-c),b,c+min(a,C-c));
    tryf(a+min(b,A-a),b-min(b,A-a),c);
    tryf(a,b-min(b,C-c),c+min(b,C-c));
    tryf(a+min(c,A-a),b,c-min(c,A-a));
    tryf(a,b+min(c,B-b),c-min(c,B-b));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);
#endif
    fill(ok,false);
    fill(res,false);
    scanf("%d%d%d",&A,&B,&C);
    tryf(0,0,C);

    vi a;
    foru(i,0,C)
        if (res[i]) a.pb(i);
    int n = size(a);
    rep(i,n-1) printf("%d ",a[i]);
    printf("%d\n",a[n-1]);
    return 0;
}
