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

const int MAX_K = 55;

int k, X, n, m;
int a[MAX_K][2];
ll f[MAX_K];



char toChar(int x) {
	if (x == 0) return 'A';
	if (x == 1) return 'C';
	return 'B';
}



string print_res(int n, int first, int last, int c) {
	string res = "";
	res += toChar(first);
	n -= 2;
	if (n < 0) return res;
	if (n) {
		if (first == 0 && c) {
			res += "C";
			--n;
			--c;
		}
		while (n >= 2 && c) {
			res += "AC";
			n -= 2;
			--c;
		}
		if (c) res += "A";
		else
			rep(i, n) res += "B";
	}
	res += toChar(last);
	return res;
}



int getC(int n, int first, int last) {
	if (n < 2) return 0;
	if (n == 2) return (first == 0 && last == 1);
	if (n == 3) return (first == 0 || last == 1);
	int c = 0;
	if (first == 0) {
		++c;
		--n;
	}
	if (last == 1) {
		++c;
		--n;
	}
	return c + (n/2);
}



bool ok(int n, int first, int last, int t) {
	if (n < 2 && t > 0) return false;
	if (n == 2 && t > 1) return false;
	if (n == 2 && t == 1 && (first != 0 || last != 1)) return false;
	return true;
}



bool check_res(int n, int c, string &s) {
	if (sz(s) != n) return false;
	foru(i, 1, n-1)
		if (s[i-1] == 'A' && s[i] == 'C') --c;
	return (c == 0);
}



bool check(int first_1, int last_1, int c1, int first_2, int last_2, int c2) {
	rep(t1, c1+1) {
		if (t1 == 0 && n == 2 && first_1 == 0 && last_1 == 1) continue;
		if (!ok(n, first_1, last_1, t1)) continue;
		rep(t2, c1+2) {
			if (t2 == 0 && m == 2 && first_2 == 0 && last_2 == 1) continue;
			if (!ok(m, first_2, last_2, t2)) continue;
			f[1] = t1;
			f[2] = t2;
			a[1][0] = first_1;	a[1][1] = last_1;
			a[2][0] = first_2;	a[2][1] = last_2;
			foru(i, 3, k) {
				f[i] = f[i-1] + f[i-2] + (a[i-2][1] == 0 && a[i-1][0] == 1);
				if (f[i] > X) continue;
				a[i][0] = a[i-2][0];
				a[i][1] = a[i-1][1];
			}
			if (f[k] == X) {
				string s1 = print_res(n, first_1, last_1, t1);
				string s2 = print_res(m, first_2, last_2, t2);
				if (check_res(n, t1, s1) && check_res(m, t2, s2)) {
					cout << s1 << endl << s2 << endl;
					return true;
				}
			}
		}
	}
	return false;
}



void solve() {
	rep(first_1, 3)
		rep(last_1, 3)
			rep(first_2, 3)
				rep(last_2, 3) {
					if (n == 1 && first_1 != last_1) continue;
					if (m == 1 && first_2 != last_2) continue;
					int c1 = getC(n, first_1, last_1);
					int c2 = getC(m, first_2, last_2);
					if (check(first_1, last_1, c1, first_2, last_2, c2))
						return;
				}
	printf("Happy new year!");
}



int main() {
#ifdef DEBUG
	freopen("379D.in", "r", stdin);
	freopen("379D.out", "w", stdout);
#endif
	cin >> k >> X >> n >> m;
	solve();
	return 0;
}