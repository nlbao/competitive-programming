#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

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

const int MAX_N = 13;
const int MAX_M = 10003;

char name[MAX_M][103];
pair<double, int> a[MAX_N];
char s[103];

int main() {
    freopen("bad.in", "r", stdin);
    freopen("bad.out", "w", stdout);

    int n, m;
    scanf("%d%d\n", &n, &m);
    rep(i, n) {
    	gets(name[i]);
    	a[i] = mp(0, -i);
    }

    int nInvaild = 0;
    rep(id, m) {
    	gets(s);
    	int c = 0, vote = -1;
    	rep(i, n)
    		if (s[i] == 'X') {
    			++c;
    			vote = i;
    		}
    	if (c > 1 || vote < 0) {
    		++nInvaild;
    		continue;
    	}
    	++a[vote].fr;
    }

    rep(i, n) a[i].fr = a[i].fr*100.0/m;
    sort(a, a+n);
    ford(i, n-1, 0) {
    	printf("%s %.2lf", name[-a[i].sc], a[i].fr);
    	cout << "%" << endl;
    }
    printf("Invaild %.2lf", nInvaild*100.0/m);
    cout << "%" << endl;
    return 0;
}