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

const int MAX_N = 11;

int n;
int a[MAX_N], c[MAX_N];
char b[MAX_N];
vector<string> list, res;
string f;

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }


void tryf(int len, int pos) {
    if (pos<<1 > len-1) {
        rep(i,n) if (c[i] == 0) return;
        list.pb(f);
        return;
    }

    rep(i,n) {
        f[pos] = f[len-1-pos] = b[i];
        ++c[i];
        tryf(len,pos+1);
        --c[i];
        f[pos] = f[len-1-pos] = '-';
    }
}


void gen(int n) {
    foru(len,max(n*2-1,4),12) {
        f = "";
        rep(i,len) f += "-";
        fill(c,0);
        tryf(len,0);
    }
}

bool ck(string s) {
    int n = size(s);
    if (n > 1 && s[0] == '0') return false;
    int x = 0;
    rep(i,n) x = x*10 + (s[i]-'0');
    if (x > 255) return false;
    return true;
}


void solve() {
    int sz = size(list);
    rep(i,sz) {
        string s = list[i];
        int n = size(s);
        foru(x,1,3)
            foru(y,1,3)
                foru(z,1,3) {
                    int t = n-x-y-z;
                    if (t < 1 || t > 3) continue;
                    if (ck(s.substr(0,x)) && ck(s.substr(x,y)) && ck(s.substr(x+y,z)) && ck(s.substr(x+y+z,t))) {
                        string tmp = s.substr(0,x) + "." + s.substr(x,y) + "." + s.substr(x+y,z) + "." + s.substr(x+y+z,t);
                        res.pb(tmp);
                    }
                }
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("292C.in", "r", stdin);
    freopen("292C.out", "w", stdout);
#endif
    n = read();
    rep(i,n) {
        read(a[i]);
        b[i] = char(a[i]+int('0'));
    }

    gen(n);
    solve();

    n = size(res);
    printf("%d\n", n);
    rep(i,n) printf("%s\n", res[i].c_str());
    return 0;
}
