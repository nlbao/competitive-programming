#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <bitset>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = int(1e4) + 4;
const char CHARS[4] = {'1', 'i', 'j', 'k'};
const char MUL_CH[4][4] = {
	{'1', 'i', 'j', 'k'},
	{'i', '1', 'k', 'j'},
	{'j', 'k', '1', 'i'},
	{'k', 'j', 'i', '1'}
};
const int MUL_SIGN[4][4] = {
	{0, 0, 0, 0},
	{0, 1, 0, 1},
	{0, 1, 1, 0},
	{0, 0, 1, 1}
};


struct Node
{
	char ch;
	int sign;

	Node(char ch='?', int sign=-1): ch(ch), sign(sign) {}

	Node negative() {
		return Node(ch, (sign+1)%2);
	}

	int getChPos() const {
		for (int i = 0; i < 4; ++i)
			if (CHARS[i] == ch)
				return i;
		return -1;
	}

	Node mul(const Node &o) {
		int d = (sign + o.sign) % 2;
		if (d == 1)
			return Node(ch, 0).mul(Node(o.ch, 0)).negative();
		int i = getChPos();
		int j = o.getChPos();
		return Node(MUL_CH[i][j], MUL_SIGN[i][j]);
	}

	Node invMul(const Node &o) {
		int d = (sign + o.sign) % 2;
		if (d == 1)
			return Node(ch, 0).invMul(Node(o.ch, 0)).negative();
		Node ans = mul(o);
		if (ch == 'i' && (o.ch == 'j' || o.ch == 'k')) return ans.negative();
		if (ch == 'j' && (o.ch == 'i' || o.ch == 'k')) return ans.negative();
		if (ch == 'k' && (o.ch == 'i' || o.ch == 'j')) return ans.negative();
		return ans;
	}

	// Node divide(const Node &o) {
	// 	for (int i = 0; i < 4; ++i)
	// 		for (int k = 0; k < 1; ++k)
	// 			if (Node(CHARS[i], k).mul(o) == *this)
	// 				return Node(CHARS[i], k);
	// 	return Node(-1, -1);
	// }

	friend bool operator == (Node a, Node b) {
		return a.ch == b.ch && a.sign == b.sign;
	}

	string str() const {
		string ans = "";
		ans.push_back(ch);
		if (sign == 1) ans = "-" + ans;
		return ans;
	}
};


int n, m;
char s[MAX_N];
Node a[MAX_N], f[MAX_N], g[MAX_N];


string solve_0() {
	int len = 0;
	for (int i = 0; i < m; ++i)
		for (int k = 0; k < n; ++k) {
			a[len] = Node(s[len%n], 0);
			++len;
		}
	if (len < 3) return "NO";

	f[0] = a[0];
	for (int i = 1; i < len; ++i)
		f[i] = f[i-1].mul(a[i]);
	g[len-1] = a[len-1];
	for (int i = len-2; i >= 2; --i)
		g[i] = g[i+1].invMul(a[i]);

	Node all = f[len-1];
	Node tmpI = Node('i', 0);
	Node tmpJ = Node('j', 0);
	Node tmpK = Node('k', 0);
	if (!(tmpI.mul(tmpJ).mul(tmpK) == all))
		return "NO";

	for (int i = 0; i < len-2; ++i) if (f[i] == tmpI) {
		Node t = a[i+1];
		for (int j = i+2; j < len; ++j) {
			if (j > i+2) t = t.mul(a[j-1]);
			if (g[j] == tmpK && t == tmpJ)
				return "YES";
		}
	}
	return "NO";
}


int main() {
#ifdef DEBUG
	// freopen("C.in", "r", stdin);
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		scanf("%d%d", &n, &m);
		scanf("%s", s);
		string ans = solve_0();
		printf("Case #%d: %s\n", testid, ans.c_str());
	}
	return 0;
}