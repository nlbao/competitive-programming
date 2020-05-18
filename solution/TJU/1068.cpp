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

const int MAX_N = 99;

char s[MAX_N], t[MAX_N];
int a[MAX_N], f[MAX_N][MAX_N], trace[MAX_N][MAX_N];
string res[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }


int main() {
#ifndef ONLINE_JUDGE
    freopen("1068.in", "r", stdin);
    freopen("1068.out", "w", stdout);
#endif
    int nTest = read(), m, n;
    foru(test_id,1,nTest) {
        scanf("%d%d",&m,&n);
        scanf("%s",&s);
        scanf("%s",&t);
        foru(i,1,n) read(a[i]);

        fill(trace,0);
        f[1][1] = a[1];
        foru(i,2,n) {
            f[i][1] = f[i-1][1] + i*a[i];
            foru(j,2,min(i,m)) {
                f[i][j] = f[i-1][j-1] + a[i];
                trace[i][j] = i-1;
                ford(k,i-2,j-1) {
                    int tmp = f[k][j-1];
                    foru(h,k+1,i) tmp += (h-k)*a[h];
                    if (tmp <= f[i][j]) {
                        f[i][j] = tmp;
                        trace[i][j] = k;
                    }
                }
            }
        }

        int i = n;
        ford(j,m,1) {
            if (i < 1) break;
            res[j] = "";
            foru(k,trace[i][j],i-1) res[j] += t[k];
            i = trace[i][j];
        }

        printf("Keypad #%d:\n",test_id);
        foru(i,1,m) {
            printf("%c: ",s[i-1]);
            for(int sz = size(res[i]), k = 0; k < sz; ++k) printf("%c",res[i][k]);
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
