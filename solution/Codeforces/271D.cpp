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

const int MAX_N = 1555;
const ll BASE = 10007;
const ll MODULE = 1000000009;

char s[MAX_N];
bool ok[33];
map<ll,bool> f;

int read() {   int x;   scanf("%d",&x);   return x;   }
void read(int &x) {  scanf("%d",&x);    }
void readln(int &x) {   scanf("%d\n",&x);   }

int main() {
#ifndef ONLINE_JUDGE
    freopen("271D.in", "r", stdin);
    freopen("271D.out", "w", stdout);
#endif
    scanf("%s",&s);
    int n = strlen(s);
    char a[33];
    scanf("%s",a);
    rep(i,26) ok[i+1] = (a[i] == '1');
    int k = read();

    f.clear();
    int res = 0;
    rep(i,n) {
        ll h = 0;
        int c = 0;
        foru(j,i,n-1) {
            ll x = s[j]-'a'+1;
            c += (!ok[x]);
            if (c > k) break;
            //h = (h*BASE + x)%MODULE;
            h = h*BASE + x;
            if (f.find(h) == f.end()) {
                ++res;
                f[h] = true;
            }
        }
    }
    cout << res;
    return 0;
}
