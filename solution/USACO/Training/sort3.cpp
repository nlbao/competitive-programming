/*
    ID: storm59061
    LANG: C++
    TASK: sort3
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

const int MAX_N = 1003;

int n, res;
int a[MAX_N], head[MAX_N];


void swap(int &x, int &y) {
    int t = x;
    x = y;
    y = t;
}

bool check(int value, int i) {
    return head[value]+1 <= i && i <= head[value+1];
}

bool find(int l, int r, int i) {
    foru(j, l, r)
        if (check(a[j], i) && !check(a[j], j)) {
            //cout << i << " " << j << "         " << a[i] << " " << a[j]  << "           " << head[a[j]]+1 << endl;
            swap(a[i],a[j]);
            ++res;
            return true;
        }
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);
#endif
    read(n);
    fill(head,0);
    foru(i,1,n) {
        scanf("%d",&a[i]);
        ++head[a[i]];
    }
    foru(i,2,4) head[i] += head[i-1];
    foru(i,1,n) --head[a[i]];
    head[n+1] = n;

    res = 0;
    foru(i,1,n) {
        int l = head[a[i]]+1, r = head[a[i]+1];
        if (l <= i && i <= r) continue;
        if (find(l,r,i)) continue;
        if (find(1,l-1,i)) continue;
        find(r+1,n,i);
    }
    cout << res << endl;
    return 0;
}
