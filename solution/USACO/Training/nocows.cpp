/*
    ID: storm59061
    LANG: C++
    TASK: nocows
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

const int MAX_N = 202;
const int MAX_K = 102;
const int MODULO = 9901;

int f[MAX_N][MAX_K];
//f[n][k] is number of trees with n nodes and height <= k

int mmod(int x) {
    x %= MODULO;
    return (x+MODULO)%MODULO;
}

int cal_f(int n, int k) {
    if (n%2 == 0 || k == 0) return 0;
    if (n == 1) return 1;
    if (f[n][k] != -1) return f[n][k];
    int sum = 0;
    for(int i = 1; i < n-1; i += 2)
        sum = mmod(sum + cal_f(i,k-1)*cal_f(n-i-1,k-1));
    return f[n][k] = sum;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w", stdout);
#endif
    int n = read(), k = read();
    foru(i,1,n)
        foru(j,1,k) f[i][j] = -1;
    printf("%d\n",mmod(cal_f(n,k)-cal_f(n,k-1)));
    return 0;
}
