/*
    ID: storm59061
    LANG: C++
    TASK: dualpal
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
int readln(int &x) {   scanf("%d\n",&x);   return x;   }

string toBase(int num, int base) {
    string s = "";
    while (num > 0) {
        s = char(num%base + int('0')) + s;
        num /= base;
    }
    return s;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);
#endif
    int n = read(), a = read()+1;
    rep(turn,n)
        for(bool stop = false; !stop; ++a)
            for(int i = 2, c = 0; i < 11 && c < 2; ++i) {
                string s = toBase(a,i), t = s;
                reverse(all(t));
                if (s == t) {
                    ++c;
                    if (c == 2) {
                        printf("%d\n",a);
                        stop = true;
                    }
                }
            }
    return 0;
}
