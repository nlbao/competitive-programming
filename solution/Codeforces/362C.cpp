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

const int MAX_N = 5004;

int a[MAX_N];
int f[MAX_N][MAX_N];


int get_g(int x, int i, int j) {
	if (i > j) return 0;
	if (i == j) return a[i] < a[x];
	return (j-i+1) - (f[x][j] - f[x][i-1]);
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("362C.in", "r", stdin);
	freopen("362C.out", "w", stdout);
#endif
	int n = read(), sum = 0;
	foru(i, 1, n) scanf("%d", &a[i]);
	foru(i, 1, n) {
		f[i][0] = 0;
		foru(j, 1, n)
			f[i][j] = f[i][j-1] + (a[j] > a[i]);
		sum += f[i][i];
	}

	int minRes = sum, cRes = 0;
	foru(i, 1, n)
		foru(j, i+1, n) {
			int s = sum - f[i][i] - f[j][j] + f[i][j] + f[j][i-1];
			s -= get_g(i, i+1, j-1);
			s += get_g(j, i+1, j-1);
			if (s < minRes) {
				minRes = s;
				cRes = 1;
			}
			else if (s == minRes)
				++cRes;
		}
	cout << minRes << " " << cRes << endl;
	return 0;
}