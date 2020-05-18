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


namespace FFT {
#define M_PI acos(-1)
typedef vector<ll> vi;

struct base {
	typedef double T;
	T re, im;
	base() : re(0), im(0) {}
	base(T re) : re(re), im(0) {}
	base(T re, T im) : re(re), im(im) {}
	base operator + (const base& o) const { return base(re + o.re, im + o.im); }
	base operator - (const base& o) const { return base(re - o.re, im - o.im); }
	base operator * (const base& o) const { return base(re * o.re - im * o.im, re * o.im + im * o.re); }
	base operator * (ld k) const { return base(re * k, im * k) ;}
	base conj() const { return base(re, -im); }
};

const int N = 21;
const int MAXN = (1<<N);
base w[MAXN];
base f1[MAXN];
int rev[MAXN];

void build_rev(int k) {
	static int rk = -1;
	if (k == rk) return;
	rk = k;
	for (int i = 1; i <= (1<<k); ++i) {
		int j = rev[i-1], t = k-1;
		while (t >= 0 && ((j>>t)&1)) j ^= 1<<t, --t;
		if (t >= 0) j ^= 1<<t, --t;
		rev[i] = j;
	}
}

void fft(base *a, int k) {
	build_rev(k);
	int n = 1 << k;
	for (int i = 0; i < n; ++i)
		if (rev[i] > i) swap(a[i], a[rev[i]]);
	for (int t = 2, tt = 1; t <= n; t += t, tt += tt) {
		if (w[tt].re == 0 && w[tt].im == 0) {
			ld angle = M_PI / tt;
			base ww(cosl(angle), sinl(angle));
			if (tt > 1)
				for (int j = 0; j < tt; ++j) {
					if (j&1) w[tt + j] = w[(tt+j)/2] * ww;
					else w[tt + j] = w[(tt+j)/2];
				}
			else w[tt] = base(1, 0);
		}
		for (int i = 0; i < n; i += t)
			for (int j = 0; j < tt; ++j) {
				base v = a[i + j], u = a[i + j + tt] * w[tt + j];
				a[i + j] = v + u;
				a[i + j + tt] = v - u;
			}
	}
}

vi mul(const vi& a, const vi& b) {
	int k = 1, na = a.size(), nb = b.size();
	while((1<<k) < na + nb) ++k;
	int n = (1<<k);
	for (int i = 0; i < n; ++i) f1[i] = base(0, 0);
	for (int i = 0; i < na; ++i) f1[i] = f1[i] + base(a[i], 0);
	for (int i = 0; i < nb; ++i) f1[i] = f1[i] + base(0, b[i]);
	fft(f1, k);
	for (int i = 0; i < 1 + n/2; ++i) {
		base p = f1[i] + f1[(n-i)%n].conj();
		base t = f1[(n-i)%n] - f1[i].conj();
		base q(t.im, t.re);
		f1[i] = (p * q) * 0.25;
		if(i > 0) f1[(n - i)] = f1[i].conj();
	}
	for (int i = 0; i < n; ++i) f1[i] = f1[i].conj();
	fft(f1, k);
	vi r(na + nb);
	for (int i = 0; i < (int)r.size(); ++i)
		r[i] = ll(f1[i].re / n + 0.5);
	return r;
}
}


const int MAX_N = 510;
const int MAX_F = 4*sqr(MAX_N)+111;


int nR, nC, nX, nY, n, m;
int a[MAX_N][MAX_N], b[MAX_N][MAX_N], idA[MAX_N][MAX_N], idB[MAX_N][MAX_N];
int f[2][MAX_F];
string s;
vector<ll> x, y, t;


void cal(int turn) {
	x.assign(n+1, 0);
	y.assign(m+1, 0);
	fori(i,1,nR) fori(j,1,nC) if (a[i][j]==turn) x[idA[i][j]]=1;
	fori(i,1,nX) fori(j,1,nY) if (b[i][j]==turn) y[idB[i][j]]=1;
	t=FFT::mul(x, y);
	int k=min(sz(t)-1, MAX_F-1);
	fori(i,0,k) f[turn][i]=t[i];
}


int main() {
#ifdef DEBUG
	freopen("6808.in", "r", stdin);
	freopen("6808.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> nR >> nC;
	fori(i,1,nR) {
		cin >> s;
		fori(j,1,nC) a[i][j]=int(s[j-1]=='L');
	}
	n=0;
	fori(i,1,nR) fori(j,1,nC) idA[i][j]=n++;
	--n;

	int nQ=read(), nTest=0;
	while (nQ--) {
		++nTest;
		cin >> nX >> nY;
		fori(i,1,nX) {
			cin >> s;
			fori(j,1,nY) b[i][j]=int(s[j-1]=='L');
		}
		m=0;
		ford(i,nX,1) {
			ford(j,nY,1) idB[i][j]=m++;
			if (i>1) fori(j,1,nC-nY) ++m;
		}
		--m;

		cal(0);
		cal(1);

		int x, y, s0=-1, s1=-1;
		fori(i,1,nR-nX+1) fori(j,1,nC-nY+1) {
			int t0=f[0][idA[i][j]+m];
			int t1=f[1][idA[i][j]+m];
			if (t0+t1>s0+s1) {
				s0=t0;
				s1=t1;
				x=i, y=j;
			}
		}
		cout << "Case #" << nTest << ": " << x << " " << y << " " << s0 << " " << s1 << endl;
	}

	return 0;
}