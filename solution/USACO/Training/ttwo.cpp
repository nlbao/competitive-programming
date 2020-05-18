/*
    ID: storm59061
    LANG: C++
    TASK: ttwo
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

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln() {  int x;  scanf("%d\n",&x);   return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }

const int MAX_N = 13;
const int n = 10;
const int dx[4] = {-1, 0, +1, 0};
const int dy[4] = {0, +1, 0, -1};

int Fx, Fy, Cx, Cy, Fd, Cd;
char s[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N][MAX_N][MAX_N][4][4];

bool ok(int i, int j) {
    return !(i < 0 || j < 0 || i >= n || j >= n || s[i][j] == '*');
}

int solve() {
    int res = 0;
    fill(visited, false);
    for(;;) {
        if (Fx == Cx && Fy == Cy) return res;
        if (visited[Fx][Fy][Cx][Cy][Fd][Cd]) return 0;
        visited[Fx][Fy][Cx][Cy][Fd][Cd] = true;
        ++res;

        int x = Fx + dx[Fd], y = Fy + dy[Fd];
        if (ok(x,y)) {  Fx = x; Fy = y; }
        else Fd = (Fd+1)%4;

        x = Cx + dx[Cd], y = Cy + dy[Cd];
        if (ok(x,y)) {  Cx = x; Cy = y; }
        else Cd = (Cd+1)%4;

    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("ttwo.in", "r", stdin);
    freopen("ttwo.out", "w", stdout);
#endif
    rep(i,n) {
        scanf("%s",&s[i]);
        rep(j,n)
            if (s[i][j] == 'F') {   Fx = i; Fy = j; }
            else if (s[i][j] == 'C') {  Cx = i; Cy = j; }
    }
    Fd = Cd = 0;
    cout << solve() << endl;
    return 0;
}
