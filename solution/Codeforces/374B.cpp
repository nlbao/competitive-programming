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

const int MAX_N = int(1e5)+5;

char s[MAX_N];

int num(char x) {
	return x - '0';
}

int main() {
#ifdef DEBUG
	freopen("374B.in", "r", stdin);
	freopen("374B.out", "w", stdout);
#endif
	scanf("%s", &s);
	int n = strlen(s);

	ll res = 1;
	for (int i = 0, j = 0; i < n; i = ++j) {
		while (j < n-1 && num(s[j+1]) + num(s[j]) == 9)
			++j;
		ll len = j-i+1;
		if (len > 2 && len%2 != 0)
			res *= (len+1)/2;
	}
	cout << res << endl;
	return 0;
}