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

const char* name[5] = {"S", "M", "L", "XL", "XXL"};


int main() {
#ifndef ONLINE_JUDGE
    freopen("46B.in", "r", stdin);
    freopen("46B.out", "w", stdout);
#endif
    int c[5];
    rep(i, 5) read(c[i]);
    int n = read();
    char s[4];
    gets(s);
    rep(i, n) {
        gets(s);
        int x = 0;
        while (strcmp(s, name[x])) ++x;
        //cout << s << " " << x << " " << name[x] << endl;
        rep(d, 6)
            if (x+d < 5 && c[x+d]) {
                printf("%s\n", name[x+d]);
                --c[x+d];
                break;
            }
            else if (x-d >= 0 && c[x-d]) {
                printf("%s\n", name[x-d]);
                --c[x-d];
                break;
            }
    }
    return 0;
}
