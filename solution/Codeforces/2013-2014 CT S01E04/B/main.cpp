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
typedef pair<string, string> pss;

#define foru(i,a,b) for(int i = int(a); i <= int(b); ++i)
#define ford(i,b,a) for(int i = int(b); i >= int(a); --i)
#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define all(a) a.begin(),a.end()
#define sz(a) int(a.size())
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

char s[100];
map<pss, string> q;
vector<string> row, col;


void enter() {
    q.clear();
    row.clear();
    col.clear();
    set<string> srow, scol;
    int n = read();
    gets(s);
    rep(i, n) {
        char s1[4], s2[4], s3[4];
        scanf("%s%s%s", &s1, &s2, &s3);
        q[mp(s1,s2)] = s3;
        srow.insert(s1);
        scol.insert(s2);
    }
    row = vector<string> (all(srow));
    col = vector<string> (all(scol));
}

string f(string s) {
    while (sz(s) < 3) s += " ";
    return s;
}

void solve() {
    sort(all(row));
    sort(all(col));
    int n = sz(row), m = sz(col);

    string line = "+";
    rep(i, m+1) line += "---+";
    printf("%s\n", line.c_str());
    printf("|   |");
    rep(i, m) printf("%s|", f(col[i]).c_str());
    printf("\n");

    rep(i, n) {
        printf("%s\n", line.c_str());
        printf("|%s|", f(row[i]).c_str());
        rep(j, m) {
            pss p = mp(row[i], col[j]);
            string res = "   ";
            if (q.find(p) != q.end())
                res = f(q[p]);
            printf("%s|", res.c_str());
        }
        printf("\n");
    }
    printf("%s\n", line.c_str());
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    int nTest = read();
    rep(test_id, nTest) {
        enter();
        solve();
    }
    return 0;
}
