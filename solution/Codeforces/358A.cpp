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

const int MAX_N = int(1e3)+3;

int x[MAX_N];

int main() {
#ifdef DEBUG
	freopen("358A.in", "r", stdin);
	freopen("358A.out", "w", stdout);
#endif
	int n = read();
	rep(i, n) read(x[i]);
	rep(i, n-1)
		rep(j, n-1) {
			int a = min(x[i], x[i+1]), b = max(x[i], x[i+1]);
			int c = min(x[j], x[j+1]), d = max(x[j], x[j+1]);
			if (a < c && c < b && b < d) {
				cout << "yes";
				return false;
			}
		}
	cout << "no";
	return 0;
}