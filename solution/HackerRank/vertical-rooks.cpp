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

const int MAX_N = 2003;

int n;
int a[MAX_N], b[MAX_N];

char check() {
    int c = 0, c1 = 0, c2 = 0;
    rep(i,n) {
        int d = abs(a[i]-b[i]);
        c += int(d > 1);
        c1 += int(d > 2);
        c2 += int(d == 2);
    }
    //cout << c2 << " " << c1 << endl;
    if (c2 == c) return char(c%2+1 + int('0'));
    if (c2%2 == 1 && c1%2 == 0) return '2';
    if (c2%2 == 0 && c1%2 == 1) return '1';
    if (c2%2 == 0 && c1%2 == 0) return '1';
    return '2';

    if (c%2 == 1) return '2';
    if (c1%2 == 1) return '2';
    return '1';
    //return char(c%2+1 + int('0'));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("vertical-rooks.in", "r", stdin);
    freopen("vertical-rooks.out", "w", stdout);
#endif
    int nTest = read();
    rep(id,nTest) {
        read(n);
        rep(i,n) scanf("%d",&a[i]);
        rep(i,n) scanf("%d",&b[i]);
        printf("player-%c\n", check());
    }
    return 0;
}
