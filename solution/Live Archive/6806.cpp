#pragma comment(linker, "/STACK:1024000000")
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
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 104;
const int MAX_COST = 204;
const int MAX_A = 28;
const int MAX_ID = 50*MAX_N;


int nA, nW, crrTurn, nID;


struct Node {
	bool inDict;
	int c, score, id;
	Node *parent, *fail, *nexts[MAX_A];
	Node(int x=-1) {
		id=++nID;
		c=x;
		score=inDict=0;
		fail=parent=0;
		fori(i,0,MAX_A-1) nexts[i]=0;
	}

	bool hasNext(int x) {
		return nexts[x]!=0;
	}

	void newNext(int x) {
		nexts[x]=new Node(x);
		nexts[x]->parent=this;
	}
};


int cost[MAX_A], score[MAX_N];
int f[MAX_ID][MAX_COST], turn[MAX_ID][MAX_COST];
string w[MAX_N];
Node *root;


void add(const string &s, int score) {
	Node *p=root;
	int n=sz(s);
	fori(i,0,n-1) {
		int x=s[i]-'A';
		if (!p->hasNext(x)) p->newNext(x);
		p=p->nexts[x];
	}
	p->inDict=1;
	p->score+=score;
}


void trieUpdate() {
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node *p=q.front();	q.pop();
		fori(i,0,MAX_A-1) if (p->hasNext(i)) {
			q.push(p->nexts[i]);
		}
		if (p==root) continue;

		// update fail
		Node *t=p->parent->fail;
		int x=p->c;
		while (t!=root && !t->hasNext(x)) t=t->fail;
		t=t->nexts[x];
		if (!t || t==p) t=root;
		p->fail=t;

		// update score
		t=p->fail;
		while (t!=root && !t->inDict) t=t->fail;
		p->score+=t->score;	// t = dictionary link of p. ref: https://en.wikipedia.org/wiki/Aho%E2%80%93Corasick_algorithm
	}
}


inline Node* getNext(Node* p, int x) {
	while (p!=root && !p->hasNext(x)) p=p->fail;
	return p->nexts[x];
}


void remove(Node* &p) {
	if (!p) return;
	fori(i,0,MAX_A-1) remove(p->nexts[i]);
	delete p;
}


int solve(Node *p, int limit) {
	if (limit<0) return 0;
	int id=p->id;
	if (turn[id][limit]==crrTurn)
		return f[id][limit];
	int tmp=0;
	fori(i,0,MAX_A-1) {
		Node *q=getNext(p, i);
		if (!q) continue;
		tmp=max(tmp, solve(q, limit-cost[i]));
	}
	turn[id][limit]=crrTurn;
	return f[id][limit]=tmp+p->score;
}


int main() {
#ifdef DEBUG
	freopen("6806.in", "r", stdin);
	freopen("6806.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	crrTurn=0;
	filla(turn, 0);
	string s;
	int nTest=read(), limit;
	fori(testid,1,nTest) {
		nID=0;
		root=new Node();
		root->fail=root;

		cin >> nA >> nW >> limit;
		filla(cost, 0);
		fori(i,1,nA) {
			int x;
			cin >> s >> x;
			cost[s[0]-'A']=x;
		}
		fori(i,1,nW) {
			cin >> w[i] >> score[i];
			add(w[i], score[i]);
		}

		trieUpdate();

		++crrTurn;
		int ans=solve(root, limit);
		cout << "Case #" << testid << ": " << ans << endl;
		remove(root);
	}

	return 0;
}