#include <sstream>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
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

const int MAX_S = 100000;
const int MAX_N = 55;

char s[MAX_S];
int stack[MAX_N];
vi e[MAX_N];
bool ok[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }

bool is_num(char x) {   return '0' <= x && x <= '9';    }


int main() {
#ifndef ONLINE_JUDGE
    freopen("1360.in", "r", stdin);
    freopen("1360.out", "w", stdout);
#endif
    while (gets(s)) {
        int len = strlen(s), top = 0, n = 0;
        stack[0] = 0;
        foru(i,0,MAX_N) e[i].clear();

        if (len < 2) break;

        int i = 0;
        while (i < len) {
            if (s[i] == '(' || s[i] == ' ') {
                ++i;
                continue;
            }
            if (s[i] == ')') {
                ++i;
                --top;
                continue;
            }
            if (!is_num(s[i])) break;

            int j = i, u = 0;
            while (j < len && is_num(s[j])) u = 10*u + int(s[j++])-int('0');
            i = j;
            e[stack[top]].pb(u);
            e[u].pb(stack[top]);
            stack[++top] = u;
            n = max(n,u);
        }

        fill(ok,true);
        ok[0] = false;
        foru(i,1,n-1)
            foru(u,1,n) if (ok[u]) {
                int deg = 0, v;
                for(int sz = size(e[u]), j = 0; j < sz; ++j)
                    if (ok[e[u][j]]) {
                        ++deg;
                        v = e[u][j];
                    }
                if (deg == 1) {
                    ok[u] = false;
                    printf("%d",v);
                    if (i < n-1) printf(" ");
                    break;
                }
            }
        printf("\n");
    }
    return 0;
}
