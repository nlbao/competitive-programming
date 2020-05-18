/*
    ID: storm59061
    LANG: C++
    TASK: zerosum
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

const int MAX_N = 10;
const int LIM = 10000000;

int n;
char f[MAX_N];

void tryf(int i, int pre, int sum, bool plus) {
    if (pre > LIM || sum > LIM) return;
    int new_sum = plus?sum+pre:sum-pre;
    if (i > n) {
        if (new_sum == 0) {
            printf("1");
            foru(i,2,n) printf("%c%d",f[i],i);
            printf("\n");
        }
        return;
    }

    f[i] = ' ';
    tryf(i+1, pre*10+i, sum, plus);
    f[i] = '+';
    tryf(i+1, i, new_sum, true);
    f[i] = '-';
    tryf(i+1, i, new_sum, false);
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);
#endif
    read(n);
    tryf(2,1,0,true);
    return 0;
}
