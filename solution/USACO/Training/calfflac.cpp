/*
    ID: storm59061
    LANG: C++
    TASK: calfflac
*/
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

const int MAX_N = 20004;

int res = 0, rleft, rright;
string s = "", t = "";
int id[MAX_N];


int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }

void fix() {
    s = "";
    int n = size(t), c = 0;
    rep(i,n) {
        char x = tolower(t[i]);
        if ('a' <= x && x <= 'z') {
            s += x;
            id[c++] = i;
        }
    }
}

void up(int len, int l, int r) {
    if (len < res) return;
    if (len == res && l >= rleft) return;
    res = len;
    rleft = l;   rright = r;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("calfflac.in", "r", stdin);
    freopen("calfflac.out", "w", stdout);
#endif
    char ch;
    while (scanf("%c",&ch) != EOF) s += ch;
    //while (getline(cin,t)) s += t;
    //cout << s << endl;
    t = s;
    fix();

    int n = size(s);
    rep(i,n) {
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            up(r-l+1, id[l], id[r]);
            --l;    ++r;
        }
    }
    rep(i,n-1) {
        int l = i, r = i+1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            up(r-l+1, id[l], id[r]);
            --l;    ++r;
        }
    }

    cout << res << endl;
    cout << t.substr(rleft,rright-rleft+1) << endl;
    return 0;
}
