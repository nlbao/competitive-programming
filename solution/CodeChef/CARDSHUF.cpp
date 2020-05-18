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


namespace fastIO {
    const size_t amount = 16;
    static char buffer[1<<16];
    static char* dataEnd = buffer + sizeof(buffer);
    static const char* pos = dataEnd;

    inline void readAhead() {
        size_t remaining = dataEnd - pos;
        if (remaining < amount) {
            memmove(buffer, pos, remaining);
            size_t sz = fread(buffer + remaining, 1, sizeof(buffer) - remaining, stdin);
            pos = buffer;
            dataEnd = buffer + remaining + sz;
            if (dataEnd != buffer + sizeof(buffer))
                *dataEnd = 0;
        }
    }

    inline int readInt() {
        readAhead();
        int x = 0;
        bool neg = false;
        if (*pos == '-') {
            ++pos;
            neg = true;
        }
        while (*pos < '0' || *pos > '9') ++pos;
        while (*pos >= '0' && *pos <= '9') {
            x *= 10;
            x += *pos - '0';
            ++pos;
        }
        return neg ? -x : x;
    }
};


const int MAX_N = int(1e5)+5;

struct Treap {
	int prior, cnt;
	int value;
	bool rev;
	Treap *l, *r;

	Treap(int _value = 0) {
		value = _value;
		prior = rand();
		cnt = 1;
		rev = false;
		l = r = NULL;
	}
};
typedef Treap* pTreap;

inline int getCnt(pTreap p) {	return p ? p->cnt : 0;	}
inline void upCnt(pTreap p) {
	if (p) p->cnt = 1 + getCnt(p->l) + getCnt(p->r);
}

inline void push(pTreap p) {
	if (p && p->rev) {
		p->rev = false;
		swap(p->l, p->r);
		if (p->l) p->l->rev ^= true;
		if (p->r) p->r->rev ^= true;
	}
}


void merge(pTreap &p, pTreap u, pTreap v) {
	push(u);
	push(v);
	if (!u || !v)
		p = u ? u : v;
	else if (u->prior > v->prior)
		merge(u->r, u->r, v), p = u;
	else
		merge(v->l, u, v->l), p = v;
	upCnt(p);
}


void split(pTreap p, pTreap &u, pTreap &v, int key, int add = 0) {
	push(p);
	if (!p) u = v = NULL;
	else {
		int pKey = getCnt(p->l) + add;
		if (key <= pKey)
			split(p->l, u, p->l, key, add), v = p;
		else
			split(p->r, p->r, v, key, pKey+1), u = p;
	}
	upCnt(u);
	upCnt(v);
}


void insert(pTreap &p, int key, int value) {
	pTreap u, v, q = new Treap(value);
	split(p, u, v, key);
	merge(p, u, q);
	merge(p, p, v);
}


void query(pTreap p, int a, int b, int c) {
	pTreap t1, t2, t3;
	split(p, t1, t2, a);
	split(t2, t2, t3, b);
	merge(p, t1, t3);
	split(p, t1, t3, c);
	t2->rev ^= true;
	merge(p, t2, t3);
	merge(p, t1, p);
}


void printTree(pTreap p) {
	if (!p) return;
	push(p);
	printTree(p->l);
	printf("%d ", p->value);
	printTree(p->r);
}


int main() {
#ifdef DEBUG
	freopen("CARDSHUF.in", "r", stdin);
	freopen("CARDSHUF.out", "w", stdout);
#endif
	srand(time(NULL));
	pTreap root = NULL;

	int n = fastIO::readInt();
	for (int i = 1; i <= n; ++i)
		insert(root, i-1, i);

	int nQ = fastIO::readInt();
	for (int i = 1; i <= nQ; ++i) {
		int a = fastIO::readInt(), b = fastIO::readInt(), c = fastIO::readInt();
		// scanf("%d %d %d\n", &a, &b, &c);
		query(root, a, b, c);
	}
	printTree(root);
	return 0;
}