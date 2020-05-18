#include <bits/stdc++.h>
 
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define ford1(i, n) for(int i = (int)(n); i>=1; --i)
#define fored(i, a, b) for(int i = (int)(b); i >= (int)(a); --i)
#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
 
#define op operator
 
using namespace std;
 
typedef long long i64;
 
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpi;
 
typedef long double ld;
 
template<class T> bool uax(T&a, const T& b) { if( a < b ) { a = b; return true; } return false; }
template<class T> bool uin(T&a, const T& b) { if( a > b ) { a = b; return true; } return false; }
 
#ifdef HOME
#define dbg(v) do {cerr << __PRETTY_FUNCTION__ << ":" <<  __LINE__ << "|" << v << '\n';}while(0)
#else
#define dbg(v) do {;}while(0)
#endif
 
 
const int N = 100500;
 
int a[N];
int b[N];
 
namespace FFT {
struct base {
   typedef double T; T re, im;
   base() :re(0), im(0) {}
   base(T re) :re(re), im(0) {}
   base(T re, T im) :re(re), im(im) {}
   base op + (const base& o) const { return base(re + o.re, im + o.im); }
   base op - (const base& o) const { return base(re - o.re, im - o.im); }
   base op * (const base& o) const { return base(re * o.re - im * o.im, re * o.im + im * o.re); }
   base op * (ld k) const { return base(re * k, im * k) ;}
   base conj() const { return base(re, -im); }
};
const int N = 21;
const int MAXN = (1<<N);
base w[MAXN];
base f1[MAXN];
int rev[MAXN];
void build_rev(int k) {
   static int rk = -1;
   if( k == rk )return ; rk = k;
   fore(i, 1, (1<<k) ) {
       int j = rev[i-1], t = k-1;
       while( t >= 0 && ((j>>t)&1) ) { j ^= 1 << t; --t; }
       if( t >= 0 ) { j ^= 1 << t; --t; }
       rev[i] = j;
   }
}
void fft(base *a, int k) {
   build_rev(k); int n = 1 << k;
   forn(i, n) if( rev[i] > i ) swap(a[i], a[rev[i]]);
   for(int l = 2, ll = 1; l <= n; l += l, ll += ll) {
       if( w[ll].re == 0 && w[ll].im == 0 ) {
           ld angle = M_PI / ll;
           base ww( cosl(angle), sinl(angle) );
           if( ll > 1 ) for(int j = 0; j < ll; ++j) {
               if( j & 1 ) w[ll + j] = w[(ll+j)/2] * ww;
               else w[ll + j] = w[(ll+j)/2];
           } else w[ll] = base(1, 0);
       }
       for(int i = 0; i < n; i += l) forn(j, ll) {
           base v = a[i + j], u = a[i + j + ll] * w[ll + j];
           a[i + j] = v + u; a[i + j + ll] = v - u;
       }
   }
}
vi mul(const vi& a, const vi& b) {
   int k = 1;
   while( (1<<k) < (a.size() + b.size()) ) ++k;
   int n = (1<<k);
   forn(i, n) f1[i] = base(0,0);
   forn(i, a.size()) f1[i] = f1[i] + base(a[i], 0);
   forn(i, b.size()) f1[i] = f1[i] + base(0, b[i]);
   fft(f1, k);
   forn(i, 1 + n/2) {
       base p = f1[i] + f1[(n-i)%n].conj();
       base _q = f1[(n-i)%n] - f1[i].conj();
       base q(_q.im, _q.re);
       f1[i] = (p * q) * 0.25;
       if( i > 0 ) f1[(n - i)] = f1[i].conj();
   }
   forn(i, n) f1[i] = f1[i].conj();
   fft(f1, k);
   vi r(sz(a) + sz(b));
   //i64 c = 0;
   forn(i, sz(r) ) {
       r[i] = (i64) (f1[i].re / n + 0.5);
       /*c += (i64) (f1[i].re / n + 0.5); r[i] = c % BS; c /= BS;*/
   } //upz(r);
   return r;
}
} // end of FFT namespace
 
void solve() {
  int n;
  cin >> n;
  a[0] = 0;
  forn(i, n) cin >> a[i + 1];
  fore(i, 1, n) b[i] = 0;
  fore(i, 1, n) if(a[i] == 0) ++b[0];
 
  fore(i, 1, n) a[i] ^= a[i-1];
 
  map<int, vector<int> > M;
  fore(i, 0, n) M[a[i]].pb(i);
 
  for(auto& e: M) {
    vi& v = e.se;
    if (v.size() < 2000) {
      forn(i, v.size()) forn(j, i)
        b[v[i] - v[j]] += 1;
    } else {
      int mx = v.back() + 1;
      vi p(mx, 0);
      vi q(mx, 0);
      for(int x: v) {
        p[x] += 1;
        q[mx - 1 - x] += 1;
      }
      vi r = FFT::mul(p, q);
      fore(i, mx, r.size() - 1) {
        b[i + 1 - mx] += r[i];
      }
    }
  }
 
  // fore(i, 1, n) forn(j, i) if(a[j] == a[i])
  //   b[i-j-1] += 1;
  fore(i, 1, n) cout << b[i] << " \n"[i == n];
}
 
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed; cout.precision(15);
  cerr << fixed; cerr.precision(15);
#ifdef HOME
  freopen("input.txt", "r", stdin);
#endif
 
  int T;
  cin >> T;
  fore(t, 1, T) {
    solve();
  }
  return 0;
}