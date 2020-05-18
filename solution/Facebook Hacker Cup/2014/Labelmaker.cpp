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

const int MAX_L = 30;

char s[MAX_L];
ll n;
ll sum[1111];
ll f[1111];



int main() {
#ifdef DEBUG
	freopen("Labelmaker.in", "r", stdin);
	freopen("Labelmaker.out", "w", stdout);
#endif
	int nTest = readln();
	foru(test_id, 1, nTest) {
		scanf("%s%lld\n", &s, &n);
		// cout << s << " " << n << endl;

		ll lenS = strlen(s), sum = lenS;
		int m = 1;
		f[0] = 1;
		f[1] = lenS;
		while (sum < n) {
			++m;
			f[m] = f[m-1]*lenS;
			sum += f[m]*lenS;
			cout << "     " << m << "     " << f[m] << "        " << sum << endl;
		}

		printf("Case #%d: %d\n", test_id, m);
	}
	return 0;
}