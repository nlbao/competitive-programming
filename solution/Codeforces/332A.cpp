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

const int MAX_N = 2002;

char s[MAX_N];


int main() {
#ifndef ONLINE_JUDGE
    freopen("332A.in", "r", stdin);
    freopen("332A.out", "w", stdout);
#endif
    int n = read();
    scanf("%s",&s);
    int m = strlen(s), res = 0, crr = 0;
    char pre[2] = {'x'};
    foru(i,1,m) {
        if (i > 1 && crr == 0) {
            bool ok = true;
            rep(j,3)
                if (pre[j] != pre[(j+1)%3]) {
                    ok = false;
                    break;
                }
            if (ok) ++res;
        }
        rep(j,2) pre[j] = pre[j+1];
        pre[2] = s[i-1];
        crr = (crr+1)%n;
    }
    cout << res;
    return 0;
}
