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

const int MAX_N = 100005;

int a[MAX_N][4];
int b[4], c[4];
map<pair<pi,pi>, bool> q;

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }


int main() {
#ifndef ONLINE_JUDGE
    freopen("291C.in", "r", stdin);
    freopen("291C.out", "w", stdout);
#endif
    int n = read(), k = read();
    string s;
    getline(cin, s);
    rep(i,n) {
        getline(cin, s);
        int len = size(s);
        for(int j = 0, c = 0; j < len; ++j, ++c) {
            a[i][c] = 0;
            while (j < len && s[j] != '.')
                a[i][c] = a[i][c]*10 + int(s[j++]-'0');
        }
        //cout << s << " " << a[i][0] << " " << a[i][1] << " " << a[i][2] << " " << a[i][3] << endl;
    }

    s = "";
    rep(i,32) s += '0';
    rep(i,31) {
        s[i] = '1';
        for(int j = 0, c = 0; j < 32; j += 8, ++c) {
            b[c] = 0;
            ford(t,j+7,j)
                if (s[t] == '1')
                    b[c] += 1<<(j+7-t);
        }

        q.clear();
        rep(i,n) {
            rep(j,4) c[j] = a[i][j]&b[j];
            q[mp(mp(c[0],c[1]),mp(c[2],c[3]))] = true;
        }

        if (size(q) == k) {
            rep(j,3) printf("%d.",b[j]);
            printf("%d",b[3]);
            return 0;
        }
    }
    cout << -1;
    return 0;
}
