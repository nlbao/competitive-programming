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

int read() {   int x;   scanf("%d",&x);   return x;   }
void read(int &x) {  scanf("%d",&x);    }
void readln(int &x) {   scanf("%d\n",&x);   }

bool check(int n) {
    bool ok[10];
    fill(ok,true);
    while (n > 0) {
        int r = n%10;
        if (!ok[r]) return false;
        ok[r] = false;
        n = n/10;
    }
    return true;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("271A.in", "r", stdin);
    freopen("271A.out", "w", stdout);
#endif
    int n = read();
    foru(i,n+1,9999)
        if (check(i)) {
            cout << i << endl;
            break;
        }

    return 0;
}
