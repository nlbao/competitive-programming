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
	Treap *l, *r;

	Treap(int _value = -1) {
		value = _value;
		prior = rand();
		cnt = 1;
		l = r = NULL;
	}
};
typedef Treap* pTreap;


int n, nQ;
int a[MAX_N], f[MAX_N];


inline int getCnt(pTreap p) {	return p ? p->cnt : 0;	}
inline void upNode(pTreap p) {
	if (!p) return;
	p->cnt = 1 + getCnt(p->l) + getCnt(p->r);
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


int remove(pTreap &p, int key, int add = 0) {
	int ans = -1, pKey = add + getCnt(p->l);
	if (key == pKey) {
		ans = p->value;
		pTreap q = p;
		merge(p, p->l, p->r);
		delete q;
	}
	else if (key < pKey)
		ans = remove(p->l, key, add);
	else
		ans = remove(p->r, key, pKey+1);
	upNode(p);
	return ans;
}


void printTreap(pTreap &p, int add = 0) {
	if (!p) return;
	int pKey = add + getCnt(p->l);
	printTreap(p->l, add);
	a[pKey+1] = p->value;
	printTreap(p->r, pKey+1);
}


void update(int i, int value) {
	if (i > n) return;
	f[i] = max(f[i], value);
	update(i + (i & (-i)), value);
}


int get(int i) {
	if (i < 1) return 0;
	return max(f[i], get(i - (i & (-i))));
}


int main() {
#ifdef DEBUG
	freopen("CARDSHUF.in", "r", stdin);
	freopen("CARDSHUF.out", "w", stdout);
#endif
	srand(time(NULL));
	pTreap root = NULL;

	n = fastIO::readInt();
	for (int i = 1; i <= n; ++i)
		insert(root, i-1, i);

	nQ = fastIO::readInt();
	for (int i = 1; i <= nQ; ++i) {
		int x, y;
		x = fastIO::readInt();
		y = fastIO::readInt();
		int value = remove(root, x-1);
		insert(root, y-1, value);
	}

	printTreap(root);
	// for (int i = 1; i <= n; ++i)
	// 	printf("%d ", a[i]);
	// cout << endl;

	int ans = 0;
	filla(f, 0);
	for (int i = 1; i <= n; ++i) {
		int t = get(a[i]-1) + 1;
		ans = max(ans, t);
		update(a[i], t);
	}
	printf("%d\n", n-ans);
	return 0;
}