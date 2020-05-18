#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 1e5 + 5;


int n;
int a[MAX_N];
vector<char> ans;


inline char ch(int value) {
	if (value == 0) return '0';
	return '1';
}


void pushTo(int r) {
	for (int i = 0; i <= r; ++i) {
		ans.push_back(ch(a[i]));
		ans.push_back('-');
		ans.push_back('>');
	}
}


bool check(int pos, int value) {
	if (pos < 0) return true;
	if (pos == 0) {
		if (a[pos] != value) return false;
		ans.push_back(ch(value));
		return true;
	}

	bool ck = true;
	if (value == 0) {
		if (a[pos] == 1) return false;
		ck = check(pos-1, 1);
		if (!ck) return false;
		ans.push_back('-');
		ans.push_back('>');
		ans.push_back(ch(a[pos]));
	}
	else {
		if (a[pos] == 1) {
			pushTo(pos-1);
			ans.push_back(ch(a[pos]));
		}
		else if (a[pos] == 0 && a[pos-1] == 0) {
			pushTo(pos-2);
			ans.push_back('(');
			ans.push_back('0');
			ans.push_back('-');
			ans.push_back('>');
			ans.push_back('0');
			ans.push_back(')');
		}
		else {	// 1->0
			int i = pos-1;
			while (i >= 0 && a[i] == 1) --i;
			if (i < 0) return false;
			pushTo(i-1);
			ans.push_back('(');
			ans.push_back('0');
			ans.push_back('-');
			ans.push_back('>');
			ans.push_back('(');
			for (int k = i+1; k < pos; ++k) {
				ans.push_back(ch(a[k]));
				ans.push_back('-');
				ans.push_back('>');
			}
			ans.push_back(ch(a[pos]));
			ans.push_back(')');
			ans.push_back(')');
		}
	}
	return ck;
}


bool solve() {
	if (n == 1) {
		if (a[0] == 1) return false;
		printf("YES\n0");
		return true;
	}
	ans.clear();
	bool ck = check(n-1, 0);
	if (ck) {
		printf("YES\n");
		foreach(it, ans)
			printf("%c", *it);
	}
	return ck;
}


int main() {
#ifdef DEBUG
	freopen("550E.in", "r", stdin);
	freopen("550E.out", "w", stdout);
#endif
	n = read();
	for (int i = 0; i < n; ++i)
		a[i] = read();
	if (!solve()) printf("NO");
	return 0;
}