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

const int MAX_N = 22;
const int MAX_M = MAX_N*MAX_N;
const int dx[4] = {-1, 0, +1, 0};
const int dy[4] = {0, +1, 0, -1};


int n, m, nMove, nVisited, l, r;
int a[MAX_N][MAX_N], cMove[MAX_M];
pii lst[MAX_M], tmp[MAX_M], q[MAX_M];
bool ok[MAX_N][MAX_N];

bool on_board(int x, int y) {
	return !(x < 0 || y < 0 || x > n || y > n);
}


void bfs(int color) {
	l = 1;	r = nVisited;
	fill(ok, true);
	foru(i, 1, nVisited) {
		q[i] = lst[i];
		ok[q[i].fr][q[i].sc] = false;
	}

	while (l <= r) {
		int x = q[l].fr, y = q[l++].sc;
		rep(k, 4) {
			int i = x+dx[k], j = y+dy[k];
			if (on_board(i, j) && ok[i][j] && a[i][j] == color) {
				q[++r] = mp(i, j);
				ok[i][j] = false;
			}
		}
	}
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("I.in", "r", stdin);
    //freopen("output.out", "w", stdout);
#endif
    int nTest = read();
    foru(test_id, 1, nTest) {
    	scanf("%d", &n);
    	foru(i, 1, n) {
    		char ch;
    		scanf("%c", &ch);
    		foru(j, 1, n) {
    			scanf("%c", &ch);
    			a[i][j] = ch-'0';
    		}
    	}

    	m = n*n;
    	nMove = 0;
    	fill(cMove, 0);
    	nVisited = 1;
    	lst[1] = mp(1, 1);

    	bfs(a[1][1]);
    	nVisited = r;
    	foru(i, 1, r) lst[i] = q[i];

    	while (nVisited < m) {
    		int maxR = 0, maxColor;
    		foru(color, 1, 6) {
    			bfs(color);
    			if (r > maxR) {
    				maxR = r;
    				maxColor = color;
    				foru(i, 1, r) tmp[i] = q[i];
    			}
    		}
    		++nMove;
    		++cMove[maxColor];
    		nVisited = maxR;
    		foru(i, 1, maxR) {
    			lst[i] = tmp[i];
    			a[lst[i].fr][lst[i].sc] = maxColor;
    		}
    	}

    	printf("%d\n", nMove);
    	foru(i, 1, 6) printf("%d ", cMove[i]);
    	printf("\n");
    }
    return 0;
}
