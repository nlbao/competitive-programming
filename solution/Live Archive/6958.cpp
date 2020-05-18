#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>
#include <unordered_set>

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


const int MAX_N = 15;
const int MAX_F = 1<<MAX_N;


int n, id[MAX_N];
ll L, w[MAX_N][MAX_N];
unordered_set<ll> s;
vector<int> a;


bool solve() {
	if (n==1) return L==0;
	if (n==2) return 2LL*w[1][2]==L;
	fori(i,1,n) id[i]=1<<(i-1);
	int nMask=(1<<n)-1, half=(n-2)/2;

	fori(mid,2,n) {
		fori(mask,0,nMask) {
			if (mask&id[1]) continue;
			if (mask&id[mid]) continue;
			if (__builtin_popcount(mask) != half) continue;

			s.clear();
			fori(k,0,1) {
				a.clear();
				a.pb(1);
				fori(i,2,n) if (i!=mid) {
					if ((k==0) == ((mask & id[i])>0))
						a.pb(i);
				}
				a.pb(mid);

				do {
					ll sum=0;
					fori(i,1,sz(a)-1) sum += w[a[i-1]][a[i]];
					if (sum>L) continue;
					if (k==0) s.insert(sum);
					else if (s.find(L-sum)!=s.end()) return 1;
				} while (next_permutation(a.begin()+1, a.end()-1));
			}
		}
	}
	return 0;
}


int main() {
#ifdef DEBUG
	freopen("6958.in", "r", stdin);
	// freopen("test.in", "r", stdin);
	freopen("6958.out", "w", stdout);
#endif
	while (scanf("%d%lld", &n, &L) != EOF) {
		fori(i,1,n) fori(j,1,n) scanf("%lld", &w[i][j]);
		if (solve()) printf("possible\n");
		else printf("impossible\n");
	}

	return 0;
}