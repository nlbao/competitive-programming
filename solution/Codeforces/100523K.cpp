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
// typedef long double ld;
typedef double ld;
typedef pair<int, int> pii;

#define filla(a,x) memset(a, (x), sizeof(a))
#define foreach(it, X) for(typeof((X).begin()) it = (X).begin(); (it) != (X).end(); (it)++)
#define sqr(x) ((x)*(x))

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = int(1e5)+5;
const ld EPS = 1e-2;


inline ld xabs(ld x) {
	return x < 0 ? -x : x;
}


// int calRank(ld a[5][5], int n, int m) {
// 	int rank = max(n,m);
// 	vector<char> line_used(n);
// 	for (int i = 0; i < m; ++i) {
// 		int j;
// 		for (j=0; j<n; ++j)
// 			if (!line_used[j] && fabs(a[j][i]) > EPS)
// 				break;
// 		if (j == n)
// 			--rank;
// 		else {
// 			line_used[j] = true;
// 			for (int p=i+1; p<m; ++p)
// 				a[j][p] /= a[j][i];
// 			for (int k=0; k<n; ++k)
// 				if (k != j && fabs(a[k][i]) > EPS)
// 					for (int p=i+1; p<m; ++p)
// 						a[k][p] -= a[j][p] * a[k][i];
// 		}
// 	}
// 	return rank;
// }


int calRank(ld a[5][5], int n, int m) {
    for (int col = 0, row = 0; col < m && row < n; ++col) {
        int k = row;
        for (int i = row+1; i < n; ++i)
            if (fabs(a[i][col]) > fabs(a[k][col]))
                k = i;
        if (fabs(a[k][col]) < EPS) continue;

        for (int i = col; i < m; ++i)
            swap(a[k][i], a[row][i]);
        for (int i = 0; i < n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j = col+1; j < m; ++j)
                    a[i][j] -= a[row][j] * c;
                a[i][col] = 0;
            }
        ++row;
    }
    int rank = 0;
    for (int i = 0, j = 0; i < n && j < m; ++j)
        if (fabs(a[i][j]) >= EPS) {
            ++i;
            ++rank;
        }
    return rank;
}



bool check() {
	int n = read();
	if (n < 4) return true;
	n -= 3;
	ld a[5][5];
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			a[i][j] = read();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j)
			a[3][j] = read();
		int rank = calRank(a, 4, 3);
		if (rank > 2) return false;
	}
	return true;
}


int main() {
#ifdef DEBUG
	freopen("100523K.in", "r", stdin);
	freopen("100523K.out", "w", stdout);
#endif
	if (check()) cout << "TAK";
	else cout << "NIE";
	return 0;
}