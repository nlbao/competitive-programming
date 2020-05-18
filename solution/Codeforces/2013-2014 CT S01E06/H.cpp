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

const int MAX_N = 111;


struct point {
    int x1, y1, x2, y2;
};

int n, H, W;
point p[MAX_N];


bool is_overlap(int i, int j) {
//if (RectA.X1 < RectB.X2 && RectA.X2 > RectB.X1 &&
    //RectA.Y1 < RectB.Y2 && RectA.Y2 > RectB.Y1)
    return  p[i].x1 <= p[j].x2 && p[i].x2 >= p[j].x1 &&
            p[i].y1 <= p[j].y2 && p[j].y2 >= p[j].y1;
}


bool check_overlap() {
    rep(i, n)
        foru(j, i+1, n)
            if (is_overlap(i, j))
                return true;
    return false;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("H.in", "r", stdin);
    freopen("H.out", "w", stdout);
#endif

    int nTest = read();
    rep(test_id, nTest) {
        scanf("%d%d", &H, &W);
        read(n);
        rep(i, n) scanf("%d%d%d%d", &p[i].x1, &p[i].y1, &p[i].x2, &p[i].y2);
        cout << check_overlap() << endl;
    }
    return 0;
}
