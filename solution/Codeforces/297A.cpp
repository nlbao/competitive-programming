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

const int MAX_N = 1003;

int n, m;
string a, b;

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }

bool all0(string s) {
    int n = size(s);
    rep(i,n)
        if (s[i] == '1') return false;
    return true;
}


bool check(string s) {
    //cout << s << endl;
    int k = size(s), c = 0;
    rep(i,k) c += (s[i] == '1');
    c %= 2;
    foru(i,1,m-k)
        if (c == 0) s += '0';
        else {
            s += '1';
            c = 0;
        }
    //cout << "           " << s << endl;
    k = size(s);
    if (s.substr(k-m,m) == b) return true;
    return false;
}

string solve() {
    if (all0(b)) return "YES";
    if (all0(a)) return "NO";
    rep(pos,n-1) {
        string s = a.substr(pos,n-pos);
        if (check(s)) return "YES";
    }
    if (check("1")) return "YES";
    return "NO";
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("297A.in", "r", stdin);
    freopen("297A.out", "w", stdout);
#endif
    getline(cin,a);
    getline(cin,b);
    n = size(a);
    m = size(b);
    cout << solve();
    return 0;
}
