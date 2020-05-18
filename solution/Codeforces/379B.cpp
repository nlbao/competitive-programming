#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
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

const int MAX_N = 333;

int a[MAX_N], b[MAX_N];



bool ok(int x) {
	return b[x] == a[x];
}



void putCoin(int x) {
	++b[x];
	printf("P");
}



int main() {
#ifdef DEBUG
	freopen("379B.in", "r", stdin);
	freopen("379B.out", "w", stdout);
#endif
	int n = read();
	foru(i, 1, n) read(a[i]);
	fill(b, 0);

	foru(i, 1, n) {
		if (!ok(i)) putCoin(i);
		while (!ok(i)) {
			if (i < n) {
				printf("R");
				printf("L");
			}
			else {
				printf("L");
				printf("R");
			}
			putCoin(i);
		}
		if (i < n) printf("R");
	}
	return 0;
}