/*
    ID: storm59061
    LANG: C++
    TASK: lamps
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

const int MAX_N = 102;

struct lamps {
    int len, c;
    int list[MAX_N];

    lamps (int l) {
        len = l;
        c = 0;
        rep(i,l) list[i] = 1;
    }
    bool operator<(const lamps &other) const {
        rep(i,len)
            if (list[i] != other.list[i])
                return list[i] < other.list[i];
        return false;
    }

    void press_buttons(int mask) {
        rep(i,4) c += (mask>>i)&1;
        rep(i,len) {
            if (mask&1) list[i] ^= 1;
            if ((mask&2) && i%2 == 0) list[i] ^= 1;
            if ((mask&4) && i%2 == 1) list[i] ^= 1;
            if ((mask&8) && i%3 == 0) list[i] ^= 1;
        }
    }
    void print() {
        rep(i,len) printf("%d",list[i]);
        printf("\n");
    }
};

int n, counter;
int final_conf[MAX_N];
vector<lamps> res;

void read_input(int v) {
    for(int x = read(); x != -1; read(x))
        final_conf[x-1] = v;
}

bool check(lamps a) {
    if (counter < a.c || (counter-a.c)%2 == 1) return false;
    rep(i,a.len)
        if (final_conf[i] != -1 && final_conf[i] != a.list[i])
            return false;
    return true;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w", stdout);
#endif
    scanf("%d%d",&n,&counter);
    rep(i,n) final_conf[i] = -1;
    read_input(1);
    read_input(0);

    rep(mask,1<<4) {
        lamps a(n);
        a.press_buttons(mask);
        if (check(a)) res.pb(a);
    }
    sort(all(res));
    int nRes = size(res);
    rep(i,nRes) res[i].print();
    if (nRes == 0) printf("IMPOSSIBLE\n");
    return 0;
}
