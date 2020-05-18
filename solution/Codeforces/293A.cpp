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

const int MAX_N = 2000006;

string s, t;
vi a[4], b[4];
bool ok[MAX_N];
int sza[4], szb[4];

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }


int main() {
#ifndef ONLINE_JUDGE
    freopen("293A.in", "r", stdin);
    freopen("293A.out", "w", stdout);
#endif
    int n = read(), m = 2*n;
    getline(cin,s);
    getline(cin,s);
    getline(cin,t);
    rep(i,m) {
        if (s[i] == '1') a[t[i] != '1'].pb(i);
        else a[2+(t[i] != '1')].pb(i);
        if (t[i] == '1') b[s[i] != '1'].pb(i);
        else b[2+(s[i] != '1')].pb(i);
    }
    rep(i,4) {
        sza[i] = size(a[i]);
        szb[i] = size(b[i]);
    }

    /*rep(i,4) {
        rep(j,size(a[i])) cout << a[i][j] << " ";
        cout << endl;
    }
    rep(i,4) {
        rep(j,size(b[i])) cout << b[i][j] << " ";
        cout << endl;
    }*/

    fill(ok,true);
    int ida = 0, idb = 0, posa = 0, posb = 0, cs = 0, ct = 0;
    rep(turn,m)
        if (turn%2 == 0) {
            while (ida >= sza[posa] || !ok[a[posa][ida]])
                if (ida >= sza[posa]) {
                    ++posa;
                    ida = 0;
                }
                else ++ida;
            cs += (posa < 2);
            ok[a[posa][ida]] = false;
            //cout << "A " << ida << " " << posa << "        " << a[posa][ida] << endl;
        }
        else {
            while (idb >= szb[posb] || !ok[b[posb][idb]])
                if (idb >= szb[posb]) {
                    ++posb;
                    idb = 0;
                }
                else ++idb;
            ct += (posb < 2);
            ok[b[posb][idb]] = false;
            //cout << "B " << idb << " " << posb << "        " << b[posb][idb] << endl;
        }

    //cout << cs << " " << ct << endl;

    string res = "Draw";
    if (cs > ct) res = "First";
    else if (cs < ct) res = "Second";
    cout << res << endl;
    return 0;
}
