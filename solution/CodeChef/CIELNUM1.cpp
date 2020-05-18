#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <deque>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PI;

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define all(a) a.begin(),a.end()
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

vector< string > res;

bool cmp(string i, string j) {
   int n = i.size(), m = j.size();
   if (n < m) return true;
   if (n > m) return false;
   return i < j;
}

void print_res() {
   //sort(res.begin(), res.end(), cmp);
   fab(i, 0, int(res.size())-1) cout << res[i] << endl;
}

int main() {
	freopen("CIELNUM1.out", "w", stdout);
	int count = 0;
	int f[100];
	fab(n, 1, 100) {
		fab(c, 0, n)
			fab(b, 0, c)
				if (b+c > n) break;
				else fab(a, n-b-c, b) {
					fab(i, 1, a) f[i] = 3;
					fab(i, a+1, a+b) f[i] = 5;
					fab(i, a+b+1, n) f[i] = 8;
					//res.clear();
					do {
						string s;
						fab(i, 1, n)
							if (f[i] == 3) s += '3';
							else if (f[i] == 5) s += '5';
							else s += '8';
						//res.pb(s);
						cout << s << endl;
						if (++count == 500) {
						   //print_res();
							return 0;
						}
						int j = 0, k, t;
						fba(i, n, 2)
							if (f[i] > f[i-1]) {
								j = i-1;
								break;
							}
						if (!j) break;
						fba(i, n, j)
							if (f[i] > f[j]) {
								t = f[i];	f[i] = f[j];	f[j] = t;
								break;
							}
						sort(f+j+1, f+n);
					}
					while (1);
					//print_res();
				}
	}
 	return 0;
}

