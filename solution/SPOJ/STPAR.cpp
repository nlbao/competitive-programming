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
#include <stack>

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

const int MAX_N = 1003;


int n;
int a[MAX_N];
stack<int> stk;


string solve() {
	int x = 1;
	while (!stk.empty()) stk.pop();
	for (int i = 0; i < n; ++i)
		if (a[i] != x)
			stk.push(a[i]);
		else {
			++x;
			while (!stk.empty() && stk.top() == x) {
				stk.pop();
				++x;
			}
		}

	if (stk.empty())
		return "yes";
	return "no";
}



int main() {
#ifdef DEBUG
	freopen("STPAR.in", "r", stdin);
	freopen("STPAR.out", "w", stdout);
#endif
	while(true) {
		scanf("%d", &n);
		if (n <= 0) break;
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		cout << solve() << endl;
	}
	return 0;
}