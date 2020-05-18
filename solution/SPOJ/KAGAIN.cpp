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

const int MAX_N = 30004;

int a[MAX_N];
int pleft[MAX_N];



int main() {
#ifdef DEBUG
	freopen("KAGAIN.inp", "r", stdin);
	freopen("KAGAIN.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);

		// cal left
		deque<int> q;
		for (int i = 0; i < n; ++i) {
			pleft[i] = i;
			while (!q.empty() && a[q.back()] >= a[i]) {
				pleft[i] = q.back();
				q.pop_back();
			}
			// if (!q.empty())
			// 	pleft[i] = q.back();
			q.push_back(i);
		}

		// cal right and result
		int res_value = -1, res_left = -1, res_right = -1;
		q.clear();
		for (int i = n-1; i >= 0; --i) {
			int right = i;
		// 	while (!q.empty() && a[q.back()] > a[i])
		// 		q.pop_back();
		// 	if (!q.empty())
		// 		right = q.back();
		// 	q.push_back(i);


			int tmp = a[i]*(right-pleft[i]+1);
			cout << "			" << a[i] << endl;
			cout << "!!! 	" << i << "		" << pleft[i] << " " << right << "			" << tmp << endl;

			if (tmp > res_value) {
				res_value = tmp;
				res_left = pleft[i];
				res_right = right;
			}
		}

		// print result
		printf("%d %d %d\n", res_value, res_left+1, res_right+1);
	}
	return 0;
}