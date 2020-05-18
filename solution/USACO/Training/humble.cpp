/*
    ID: storm59061
    LANG: C++
    TASK: humble
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
typedef pair<ll, int> heap_element;

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

const int MAX_M = 102;
const int MAX_N = 10004;

class heap_cmp {
public:
    bool operator() (const heap_element &a, const heap_element &b) const {
        return a.fr > b.fr;
    }
};

int n, m;
ll a[MAX_M];
priority_queue<heap_element, vector<heap_element>, heap_cmp> heap;

int main() {
#ifndef ONLINE_JUDGE
    freopen("humble.in", "r", stdin);
    freopen("humble.out", "w", stdout);
#endif
    scanf("%d%d",&m,&n);
    rep(i,m) a[i] = read();
    sort(a,a+m);
    rep(i,m) heap.push(mp(a[i],i));
    ll res = -1;
    rep(i,n-1) {
        if (heap.empty()) break;
        heap_element u = heap.top();
        heap.pop();
        ll x = u.fr;
        int k = u.sc;
        heap.push(mp(x*a[k],k));
        if (k < m-1)
            heap.push(mp(x*a[k+1],k+1));
        cout << x << " " << k << endl;
    }
    if (!heap.empty()) res = heap.top().fr;
    cout << res << endl;
    return 0;
}
