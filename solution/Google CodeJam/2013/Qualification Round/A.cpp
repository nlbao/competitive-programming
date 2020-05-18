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


int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }

string a[4];
char b[4];

bool check(char x) {
    rep(i,4)
        if (b[i] != x && b[i] != 'T') return false;
    return true;
}

bool win(char x) {
    rep(i,4) {
        rep(j,4) b[j] = a[i][j];    //row
        if (check(x)) return true;
        rep(j,4) b[j] = a[j][i];    //col
        if (check(x)) return true;
    }
    rep(i,4) b[i] = a[i][i];
    if (check(x)) return true;
    rep(i,4) b[i] = a[i][3-i];
    if (check(x)) return true;
    return false;
}

string solve() {
    if (win('X')) return "X won";
    if (win('O')) return "O won";
    rep(i,4)
        rep(j,4)
            if (a[i][j] == '.') return "Game has not completed";
    return "Draw";
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("A-large.in", "r", stdin);
    freopen("A.out", "w", stdout);
#endif
    cout << not 123;
    int nTest;
    readln(nTest);
    foru(test_id,1,nTest) {
        rep(i,4) getline(cin,a[i]);
        cout << "Case #" << test_id << ": " << solve() << endl;
        string t;
        getline(cin,t);
    }
    return 0;
}
