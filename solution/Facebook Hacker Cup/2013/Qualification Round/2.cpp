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
typedef vector<int> VI;
typedef pair<int, int> PI;

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

const int MAX_N = 202;

int n;
//char s[MAX_N];
string s;
bool f[MAX_N][MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

bool ck(char a, char b) {
    if (a == ':' && b == ')') return true;
    if (a == ':' && b == '(') return true;
    return false;
}

bool solve() {
    if (n == 0) return true;
    fill(f,false);
    rep(i,n)
        if (('a' <= s[i] && s[i] <= 'z') || s[i] == ' ' || s[i] == ':') f[i][i] = true;
        else if (s[i] != '(' && s[i] != ')') return false;
    rep(i,n-1) f[i][i+1] = ck(s[i],s[i+1]);

    foru(len,1,n)
        rep(i,n-len+1) {
            int j = i+len-1;
            if (s[i] == '(' && s[j] == ')' && f[i+1][j-1]) {
                f[i][j] = true;
                continue;
            }
            foru(k,i,j-1)
                if (f[i][k] && f[k+1][j]) {
                    f[i][j] = true;
                    break;
                }
        }
    return f[0][n-1];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("2_.in", "r", stdin);
    freopen("2.out", "w", stdout);
#endif
    int nTest = read();
    getline(cin, s);
    rep(test_id,nTest) {
        getline(cin, s);
        n = size(s);
        printf("Case #%d: ",test_id+1);
        if (solve()) printf("YES");
        else printf("NO");
        if (test_id < nTest) printf("\n");
    }
    return 0;
}
