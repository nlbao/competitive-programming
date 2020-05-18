#include <cstdio>
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
typedef pair<int, int> pii;

#define filla(a,x) memset(a, (x), sizeof(a))
#define for_each(it, X) for(typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int LIMIT = 2*int(1e7);


struct Node {
	bool isNum;
	Node *nexts[10];
	Node() {
		isNum = false;
		for (int i = 0; i < 10; ++i)
			nexts[i] = NULL;
	}
};
typedef Node* pNode;

pNode root0, root1;


inline void insert(pNode &root, ll value) {
	pNode p = root;
	while (value > 0) {
		ll x = value%10LL;
		value /= 10LL;
		if (p->nexts[x] == NULL)
			p->nexts[x] = new Node();
		p = p->nexts[x];
	}
	p->isNum = true;
}


inline bool find(pNode &root, ll value) {
	pNode p = root;
	while (value > 0) {
		ll x = value%10LL;
		value /= 10LL;
		if (p->nexts[x] == NULL)
			return false;
		p = p->nexts[x];
	}
	return p->isNum;
}


int main() {
#ifdef DEBUG
	freopen("100503D.in", "r", stdin);
	freopen("100503D.out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll a, b, c, x = 1;
	cin >> a >> b >> c;

	root0 = new Node();
	root1 = new Node();

	int ans = -1;
	insert(root1, 1);
	for (int i = 1; i <= LIMIT; ++i) {
		x = (a*x + (x%b))%c;
		if (x == 0) {
			ans = i+1;
			break;
		}
		else if (x < 0) {
			if (find(root0, -x)) {
				ans = i;
				break;
			}
			insert(root0, -x);
		}
		else {
			if (find(root1, x)) {
				ans = i;
				break;
			}
			insert(root1, x);
		}
	}
	cout << ans;
	return 0;
}