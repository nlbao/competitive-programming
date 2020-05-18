/*
    ID: storm59061
    LANG: C++
    TASK: subset
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

const int MAX_N = 40;
const int MAX_S = MAX_N*(MAX_N+1)/2;

int main() {
#ifndef ONLINE_JUDGE
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
#endif
    int n = read(), sum = n*(n+1)/2;
    if (sum%2 == 1) {
        printf("0\n");
        return 0;
    }

    ll f[MAX_S] = {0};
    f[0] = 1;
    foru(i,1,n)
        ford(j,sum-i,0)
            f[j+i] += f[j];
    printf("%lld\n",f[sum/2]/2);
    return 0;
}
