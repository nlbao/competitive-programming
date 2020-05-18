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
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = int(1e5)+5;
const int oo = int(1e9)+100;


struct Treap {
	int prior, cnt;
	int value, maxValue;
	Treap *l, *r;

	Treap(int _value = -oo) {
		value = maxValue = _value;
		prior = rand();
		cnt = 1;
		l = r = NULL;
	}
};
typedef Treap* pTreap;

inline int getCnt(pTreap p) {	return p ? p->cnt : 0;	}
inline int getMax(pTreap p) {	return p ? p->maxValue : -oo;	}
inline void upNode(pTreap p) {
	if (!p) return;
	p->cnt = 1 + getCnt(p->l) + getCnt(p->r);
	p->maxValue = max(p->value, max(getMax(p->l), getMax(p->r)));
}


void merge(pTreap &p, pTreap u, pTreap v) {
	if (!u || !v)
		p = u ? u : v;
	else if (u->prior > v->prior)
		merge(u->r, u->r, v), p = u;
	else
		merge(v->l, u, v->l), p = v;
	upNode(p);
}


void split(pTreap p, pTreap &u, pTreap &v, int key, int add = 0) {
	if (!p) u = v = NULL;
	else {
		int pKey = getCnt(p->l) + add;
		if (key <= pKey)
			split(p->l, u, p->l, key, add), v = p;
		else
			split(p->r, p->r, v, key, pKey+1), u = p;
	}
	upNode(u);
	upNode(v);
}


void insert(pTreap &p, int key, int value) {
	pTreap u, v, q = new Treap(value);
	split(p, u, v, key);
	merge(p, u, q);
	merge(p, p, v);
}


int findMax(pTreap p, int x, int y) {
	pTreap t1, t2, t3;
	split(p, t1, t2, x);
	split(t2, t2, t3, y-x+1);
	int ans = getMax(t2);
	merge(p, t1, t2);
	merge(p, p, t3);
	return ans;
}



int INP,AM;
char CH;
#define BUFSIZE (1<<10)
char BUF[BUFSIZE+1], *inp=BUF;
#define GETCHAR(INP) {				\
	if(!*inp) {					\
		fread(BUF,1,BUFSIZE,stdin);	\
		inp=BUF;				\
	}						\
	INP=*inp++;				\
}
#define DIG(a) (((a)>='0')&&((a)<='9'))
#define GETNUM(j) {					\
	GETCHAR(INP); while(!DIG(INP)) GETCHAR(INP);\
	j=INP-'0'; GETCHAR(INP);				\
	while(DIG(INP)){j=10*j+(INP-'0');GETCHAR(INP);}\
}

inline char get_char() {
	char ch = ' ';
	while (ch == '\n' || ch == '\r' || ch == '\t' || ch == ' ') {
		if(!*inp) {
			fread(BUF,1,BUFSIZE,stdin);
			inp=BUF;
		}
		while (*inp && (ch == '\n' || ch == '\r' || ch == '\t' || ch == ' '))
			ch =*inp++;
	}
	return ch;
}


int main() {
#ifdef DEBUG
	freopen("QMAX3VN.in", "r", stdin);
	freopen("QMAX3VN.out", "w", stdout);
#endif
	srand(time(NULL));
	pTreap root = NULL;

	int nQ = readln();
	for (int i = 1; i <= nQ; ++i) {
		char ch;
		int x, y;
		// scanf("%c %d %d\n", &ch, &x, &y);

		// GETCHAR(ch);
		ch = get_char();
		GETNUM(x);	GETNUM(y);
		// cout << ch << " " << x << " " << y << endl;

		if (ch == 'A') {
			insert(root, y-1, x);
		}
		else {
			printf("%d\n", findMax(root, x-1, y-1));
		}
	}
	return 0;
}