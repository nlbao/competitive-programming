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

const int MAX_N = 10004;
const ll BASE = 10007LL;


char s[MAX_N];
string morse[26] = {".-", "-...", "-.-.", "-..",
                    ".", "..-.", "--.", "....",
                    "..", ".---", "-.-", ".-..",
                    "--", "-.", "---", ".--.",
                    "--.-", ".-.", "...", "-",
                    "..-", "...-", ".--", "-..-",
                    "-.--", "--.."};

ll p[MAX_N], f[MAX_N], h[MAX_N];
map<ll,ll> q;

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }


ll value(char x) {  if (x == '-') return 3; return 2;   }

ll get_h(int i, int j) {
    if (i == 0) return h[j];
    return h[j]-h[i-1]*p[j-i+1];
}

ll qfind(ll x) {
    if (q.find(x) == q.end()) return 0;
    return q[x];
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("1481.in", "r", stdin);
    freopen("1481.out", "w", stdout);
#endif
    int nTest = read();
    rep(test_id,nTest) {
        scanf("%s",s);
        int n = strlen(s);
        h[0] = value(s[0]);
        foru(i,1,n-1) h[i] = h[i-1]*BASE + value(s[i]);

        p[0] = 1;
        foru(i,1,n) p[i] = p[i-1]*BASE;

        q.clear();
        int m = read();
        rep(id,m) {
            scanf("%s",&s);
            ll g = 0;
            int k = strlen(s);
            rep(i,k) {
                string tmp = morse[int(s[i])-int('A')];
                rep(j,size(tmp)) g = g*BASE + value(tmp[j]);
            }
            if (q.find(g) == q.end()) q[g] = 1;
            else ++q[g];
        }

        f[0] = qfind(get_h(0,0));
        foru(i,1,n-1) {
            f[i] = qfind(get_h(0,i));
            foru(j,max(i-80,1),i)
                f[i] = f[i] + qfind(get_h(j,i))*f[j-1];
        }

        printf("%d\n",int(f[n-1]));
    }
    return 0;
}
