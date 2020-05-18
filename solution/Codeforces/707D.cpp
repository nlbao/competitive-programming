// #pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fori(i,a,b) for (ll i=(a); i<=(b); ++i)
#define ford(i,a,b) for (ll i=(a); i>=(b); --i)
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define err(x) cout << __LINE__ << ": " << #x << " = " << (x) << endl;
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define has(a, x) (a.find(x) != a.end())
#define all(x) x.begin(), x.end()
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e3+3;
const int MAX_M = 1e3+3;
const int MAX_Q = 1e5+5;
const int LEN = 64;


int n, m, nQ, nCell;

struct Row {
	int cnt;
	ll* cells;

	Row() {
		cnt = 0;
		cells = new ll[nCell];
		for (int i = 0; i < nCell; ++i)
			cells[i] = 0;
	}

	Row(const Row &other) {
		cnt = other.cnt;
		cells = new ll[nCell];
		for (int i = 0; i < nCell; ++i)
			cells[i] = other.cells[i];
	}

	inline int count() const {
		return cnt;
	}

	inline int getBit(int i, int j) const {
		return (cells[i]>>j)&1;
	}

	inline void setVal(int i, int j, int val) {
		if (val == 1) cells[i] |= (1LL<<j);
		else cells[i] &= ~(1LL<<j);
	}

	void set(int pos) {
		int i = pos / LEN, j = pos % LEN;
		if (!getBit(i, j)) ++cnt;
		setVal(i, j, 1);
	}

	void reset(int pos) {
		int i = pos / LEN, j = pos % LEN;
		if (getBit(i, j)) --cnt;
		setVal(i, j, 0);
	}

	void flip() {
		cnt = m - cnt;
		for (int i = 0; i < nCell; ++i)
			cells[i] = ~cells[i];
	}
};
typedef Row* pRow;


struct Table {
	pRow* rows;
	int cnt;

	Table(bool isNew = false) {
		cnt = 0;
		rows = new pRow[n+1];
		for (int i = 1; i <= n; ++i)
			if (isNew) rows[i] = new Row();
			else rows[i] = 0;
	}

	Table(const Table &other) {
		cnt = other.cnt;
		rows = new pRow[n+1];
		for (int i = 1; i <= n; ++i)
			rows[i] = new Row(*other.rows[i]);
	}
};


Table* tables[MAX_Q];


int main() {
#ifdef DEBUG
	freopen("707D.in", "r", stdin);
	freopen("707D.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> m >> nQ;
	nCell = m / LEN;
	if (m%LEN) ++nCell;

	tables[0] = new Table(true);
	for (int qid = 1; qid <= nQ; ++qid) {
		int tid, i, j, k;
		cin >> tid;
		if (tid < 4) {
			cin >> i;
			tables[qid] = new Table(*tables[qid-1]);
			tables[qid]->cnt -= tables[qid]->rows[i]->count();
			tables[qid]->rows[i] = new Row(*tables[qid]->rows[i]);
		}
		if (tid == 1) {
			cin >> j;
			tables[qid]->rows[i]->set(--j);
		}
		else if (tid == 2) {
			cin >> j;
			tables[qid]->rows[i]->reset(--j);
		}
		else if (tid == 3) {
			tables[qid]->rows[i]->flip();
		}
		else {
			cin >> k;
			tables[qid] = new Table(*tables[k]);
		}
		if (tid < 4)
			tables[qid]->cnt += tables[qid]->rows[i]->count();
		cout << tables[qid]->cnt << endl;
	}

	return 0;
}