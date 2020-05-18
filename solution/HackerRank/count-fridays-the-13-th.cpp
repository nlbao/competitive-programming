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
#define pb push_back
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }


const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int months[12] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
const int months_leap[12] = {6, 2, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};

int d[2], m[2], y[2];


inline bool isLeap(int y) {
	return (y%4==0 && y%100!=0) || y%400==0;
}

int getNDay(int y, int m) {
	return days[m-1] + (m==2 && isLeap(y));
}

int dayInWeek(int y, int m, int d) {
	int r = (y/100)%4, c = r==0 ? 6 : r==1 ? 4 : r==2 ? 2 : 0;
	m = isLeap(y) ? months_leap[m-1] : months[m-1];
	y %= 100;
	return (d+m+y+(y/4)+c)%7;	// 0 = Sunday
}

int main() {
#ifdef DEBUG
	freopen("count-fridays-the-13-th.in", "r", stdin);
	freopen("count-fridays-the-13-th.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	string s;
	getline(cin, s);
	fori(testid,1,nTest) {
		getline(cin, s);
		stringstream ss;
		ss << s;
		fori(i,0,1) ss >> d[i] >> m[i] >> y[i];
		int ans=0;
		fori(i,y[0],y[1]) {
			fori(j,1,12) {
				if (i==y[0] && j<m[0]) continue;
				if (i==y[1] && j>m[1]) continue;
				int limit=getNDay(i, j);
				if (limit<13) continue;
				if (i==y[0] && j==m[0] && 13<d[0]) continue;
				if (i==y[1] && j==m[1] && 13>d[1]) continue;
				ans += (dayInWeek(i,j,13)==5);
			}
		}
		cout << ans << endl;
	}

	return 0;
}