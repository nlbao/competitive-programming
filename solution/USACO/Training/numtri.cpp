/*
    ID: storm59061
    LANG: C++
    TASK: numtri
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

const int MAX_N = 1002;

int f[MAX_N], a[MAX_N];


int main() {
#ifndef ONLINE_JUDGE
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);
#endif
    int n = read(), res = 0;
    fill(f,0);
    foru(i,1,n) {
        foru(j,1,i)
            a[j] = max(f[j-1],f[j]) + read();
        foru(j,1,i) f[j] = a[j];
    }
    foru(j,1,n) res = max(res,f[j]);
    cout << res << endl;
    return 0;
}
