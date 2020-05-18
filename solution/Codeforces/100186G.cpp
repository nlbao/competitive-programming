#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fori(i,a,b) for(int i=(a); i<=(b); ++i)
#define ford(i,a,b) for(int i=(a); i>=(b); --i)
#define forix(i,a,b,x) for(int i=(a); i<=(b); i+=(x))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }


struct node {
	node* nexts[2];
	node() {
		nexts[0]=nexts[1]=NULL;
	}
	bool hasNext(int i) {	return nexts[i] != NULL;	}
};


const int MAX_N = 3e5+5;


int n;
node *root;
int a[MAX_N], b[MAX_N];



#define num(x) (x-'0')
#define getBit(x, i) ((x>>i)&1)


int find(int val) {
	int ans=0;
	node *p=root;
	ford(i,30,0) {
		int x=0^getBit(val, i);
		if (!p->hasNext(x)) {
			x^=1;
			if (!p->hasNext(x)) return -1;
		}
		p=p->nexts[x];
		if (x) ans |= (1<<i);
	}
	if (!p) return -1;
	return ans;
}


void add(int val) {
	node *p=root;
	ford(i,30,0) {
		int x=getBit(val, i);
		if (!p->hasNext(x))
			p->nexts[x] = new node();
		p=p->nexts[x];
	}
}


inline bool cmp(int x, int y) {
	ford(i,30,0) {
		int a=getBit(x,i), b=getBit(y,i);
		if (a!=b) return a<b;
	}
	return 0;
}


int main() {
#ifdef DEBUG
	freopen("100186G.in", "r", stdin);
	freopen("100186G.out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	root=new node();
	int ansX=-1, ansY=-1, ans=0;
	fori(i,0,30) ans |= (1<<i);

	cin >> n;
	fori(i,1,n) {
		cin >> a[i];
		b[i]=a[i];
	}
	sort(a+1,a+1+n);

	fori(i,1,n) {
		int x=a[i];
		int y=find(x);
		if (y>-1 && cmp(x^y, ans)) {
			ans=x^y;
			ansX=x;
			ansY=y;
		}
		add(x);
	}
	int i=1, j=1;
	while (b[i]!=ansX) ++i;
	while (j==i || b[j]!=ansY) ++j;
	cout << i << " " << j << endl;

	return 0;
}