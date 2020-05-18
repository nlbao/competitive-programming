#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
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

const int MAX_N = 3*100005;

int a[MAX_N], mleft[MAX_N], mright[MAX_N], f[MAX_N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("359D.in", "r", stdin);
    freopen("359D.out", "w", stdout);
#endif
    int n = read();
   	foru(i, 1, n) read(a[i]);

   	foru(i, 1, n) {
   		mleft[i] = i;
   		for (int j = mleft[i]-1; j >= 1 && a[j]%a[i] == 0; j = mleft[i]-1)
   			mleft[i] = mleft[j];
   	}

   	ford(i, n, 1) {
   		mright[i] = i;
   		for (int j = mright[i]+1; j <= n && a[j]%a[i] == 0; j = mright[i]+1)
   			mright[i] = mright[j];
   	}

   	int maxL = 0, c = 0;
   	fill(f, 0);
   	foru(i, 1, n) {
   		int l = mright[i]-mleft[i];
   		maxL = max(maxL, l);
   		f[mleft[i]] = max(f[mleft[i]], l);
   	}
   	foru(i, 1, n) c += (f[i] == maxL);

   	printf("%d %d\n", c, maxL);
   	foru(i, 1, n)
   		if (f[i] == maxL)
   			printf("%d ", i);
    return 0;
}