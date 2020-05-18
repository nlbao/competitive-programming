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
typedef pair<int, int> pi;
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

const int MAX_N = 100005;

char s[MAX_N];
int f[MAX_N], g[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }

void print_s(int l, int r) {
    printf("<");
    foru(i,l,r) printf("%c",s[i]);
    printf(">\n");
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("291B.in", "r", stdin);
    freopen("291B.out", "w", stdout);
#endif
    gets(s);
    int n = strlen(s);
    f[n-1] = g[n-1] = n;
    ford(i,n-2,0) {
        if (s[i+1] == '"') f[i] = i+1;
        else f[i] = f[i+1];
        if (s[i+1] == ' ') g[i] = i+1;
        else g[i] = g[i+1];
    }

    for(int i = 0; i < n; ) {
        while (i < n && s[i] == ' ') ++i;
        if (i == n) break;
        if (s[i] == '"') {
            print_s(i+1,f[i]-1);
            i = f[i]+1;
        }
        else {
            print_s(i,g[i]-1);
            i = g[i]+1;
        }
    }
    return 0;
}
