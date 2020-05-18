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

const int MAX_N = 5003;

int n, k;
char s[MAX_N];
int a[MAX_N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("k-mismatch.in", "r", stdin);
    freopen("k-mismatch.out", "w", stdout);
#endif
    k = read();
    gets(s);
    gets(s);
    n = strlen(s);

    ll res = 0;
    foru(d,1,n-1) {
        int m = 0, pos = 1, c = 0, last = n-1;
        ford(i,n-1-d,0) {
            int j = i+d;
            if (s[i] != s[j]) {
                a[++m] = j;
                ++c;
            }
            if (c > k) {
                last = a[pos++]-1;
                --c;
            }
            if (last >= j) res += ll(last-j+1);
        }
    }
    cout << res << endl;
    return 0;
}
