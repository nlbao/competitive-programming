#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <utility>
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

int a[20004];

int main() {
#ifndef ONLINE_JUDGE
    freopen("H.in", "r", stdin);
    freopen("H.out", "w", stdout);
#endif
    int nTest = read();
    rep(test_id, nTest) {
    	int n = read(), m = n/3, res = 0;
    	foru(i,1,n) scanf("%d", &a[i]);
    	sort(a+1, a+1+n);
    	ford(i,n,1)
    		if ((n-i+1)%3 == 0)
    			res += a[i];
    	printf("%d\n", res);
    }
    return 0;
}