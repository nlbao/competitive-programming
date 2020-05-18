/*
    ID: storm59061
    LANG: C++
    TASK: hamming
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

int n, m = 0, length, dmin;
int list[66];

int d(int x, int y) {
    x ^= y;
    y = 0;
    rep(i,length) y += (x>>i)&1;
    return y;
}

bool check(int value) {
    rep(i,m)
        if (d(value, list[i]) < dmin)
            return false;
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);
#endif
    scanf("%d%d%d",&n,&length,&dmin);
    list[m++] = 0;
    foru(mask,1,(1<<length)-1) {
        if (m == n) break;
        if (check(mask))
            list[m++] = mask;
    }

    int count = 0;
    rep(i,n) {
        printf("%d",list[i]);
        if (i == n-1) {
            printf("\n");
            break;
        }
        if (++count == 10) {
            printf("\n");
            count = 0;
        }
        else printf(" ");
    }
    return 0;
}
