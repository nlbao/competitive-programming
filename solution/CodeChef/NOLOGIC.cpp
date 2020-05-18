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

char s[333];
bool ok[33];

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }

int num(char x) {
    if ('a' <= x && 'x' <= 'z') return x-'a';
    return x-'A';
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("NOLOGIC.in", "r", stdin);
    freopen("NOLOGIC.out", "w", stdout);
#endif
    int nTest = read();
    gets(s);
    rep(test_id,nTest) {
        gets(s);
        fill(ok,true);
        int n = strlen(s);
        rep(i,n) ok[num(s[i])] = false;
        string res = "~";
        rep(i,26) if (ok[i]) {
            res = char(int('a')+i);
            break;
        }
        cout << res << endl;
    }
    return 0;
}
