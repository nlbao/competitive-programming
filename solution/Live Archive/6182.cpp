#include <sstream>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <utility>
#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector< pair<int, int> > vii;

#define foru(i,a,b) for(int i = int(a); i <= int(b); ++i)
#define ford(i,b,a) for(int i = int(b); i >= int(a); --i)
#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define all(a) a.begin(),a.end()
#define sz(a) int(a.size())
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln() {  int x;  scanf("%d\n",&x);   return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }

const int MAX_N = 150;
const int MAX_S = 20001;

bool is_prime[2*MAX_N][2*MAX_N];
vector<pair<int, pii> > a;
pii prime[MAX_S];

bool check_prime(int i, int j) {
	if (abs(i) + abs(j) < 2) return false;
	return is_prime[i+MAX_N][j+MAX_N];
}

void check(int x, int y, int i, int j) {
	int xx = x*i - y*j, yy = x*j + y*i;
	if (xx*xx + yy*yy < MAX_S)
		is_prime[xx+MAX_N][yy+MAX_N] = false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("6182.in", "r", stdin);
    freopen("6182.out", "w", stdout);
#endif
    foru(i,-141,141)
    	foru(j,-141,141) {
    		int tmp = i*i+j*j;
    		if (tmp < 2 || tmp >= MAX_S) continue;
    		a.pb(mp(tmp, mp(i, j)));
    	}
    sort(all(a));

    int n = sz(a), m = 0;
    fill(is_prime, true);
	rep(id, n) {
		int w = a[id].fr, x = a[id].sc.fr, y = a[id].sc.sc;

		/*rep(k, m) {
			int i = prime[k].fr, j = prime[k].sc;
			int tmp = i*i+j*j;
			if (tmp < 2 || tmp >= MAX_S) continue;
			int xx = x*i - y*j, yy = x*j + y*i;
			if (xx*xx + yy*yy < MAX_S)
				is_prime[xx+MAX_N][yy+MAX_N] = false;
		}*/

		if (!check_prime(x, y)) continue;
		//prime[m++] = a[id].sc;
		foru(i,0, 65) {
			int t1 = i*i;
			foru(j, 0, 65) {
				int t2 = t1 + j*j;
				if (t2 < 2 || t2 >= MAX_S) continue;
				check(x, y, i, j);
				check(x, y, i, -j);
				check(x, y, -i, j);
				check(x, y, -i, -j);
			}
		}
	}

	//cout << m << endl;

    int nTest = read();
	rep(test_id, nTest) {
		int m = read(), n = read();
		if (check_prime(m, n)) printf("P\n");
		else printf("C\n");
    }
    return 0;
}