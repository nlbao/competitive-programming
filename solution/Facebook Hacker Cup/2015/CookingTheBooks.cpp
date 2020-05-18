#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <bitset>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 111;

char s[MAX_N], t[MAX_N];


int main() {
#ifdef DEBUG
	freopen("CookingTheBooks.in", "r", stdin);
	freopen("CookingTheBooks.out", "w", stdout);
#endif
	int nTest;
	scanf("%d\n", &nTest);
	for (int testid = 1; testid <= nTest; ++testid) {
		scanf("%s", s);
		int n = strlen(s);


		printf("Case #%d: ", testid);
        for (int i = 0; i < n; ++i) t[i] = s[i];
        for (int p = 0; p < n; ++p) {
            int pos = p;
            for (int i = p+1; i < n; ++i)
                if (t[i] != '0' && t[i] < t[pos])
                    pos = i;
            if (pos != p) {
                swap(t[0], t[pos]);
                break;
            }
        }
		for (int i = 0; i < n; ++i) printf("%c", t[i]);
		
		printf(" ");
		
        for (int i = 0; i < n; ++i) t[i] = s[i];
        for (int p = 0; p < n; ++p) {
            int pos = p;
            for (int i = p+1; i < n; ++i)
                if (t[i] > t[pos])
                    pos = i;
            if (pos != p) {
                swap(t[0], t[pos]);
                break;
            }
        }
		for (int i = 0; i < n; ++i) printf("%c", t[i]);
		printf("\n");
	}
	return 0;
}
