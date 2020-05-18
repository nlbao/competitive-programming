#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <queue>
#include <deque>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector< pair<int, int> > vii;

#define foru(i,a,b) for(int i = int(a); i <= int(b); ++i)
#define ford(i,b,a) for(int i = int(b); i >= int(a); --i)
#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define all(a) a.begin(),a.end()
#define size(a) int(a.size())
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

const int LIMIT = 1200;
const double eps = 1e-8;
const double max_b = 50000;
const int max_payments = 1200;

double R, B, M;

int main() {
#ifndef ONLINE_JUDGE
    freopen("E.in", "r", stdin);
    freopen("E.out", "w", stdout);
#endif
    int nTest = read();
    foru(test_id, 1, nTest) {
    	cin >> R >> B >> M;

    	int res = 0;
    	double maxB = B+1;
        R /= 100.0;
    	while (B > 0 && res++ <= LIMIT && B < maxB) {
            maxB = B;
            B += B*R;
            B = int(B*100.0 + 0.5 + eps)/100.0;
            B -= M;
    	}

    	if (res > LIMIT || B >= maxB) printf("impossible\n");
    	else printf("%d\n", res);
    }
    return 0;
}
