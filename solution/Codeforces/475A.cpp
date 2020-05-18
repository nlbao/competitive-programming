#include <cstdio>
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
typedef pair<int, int> pii;

#define filla(a,x) memset(a, (x), sizeof(a))
#define for_each(it, X) for(typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = 44;

bool a[MAX_N][MAX_N];


int main() {
#ifdef DEBUG
	freopen("475A.in", "r", stdin);
	freopen("475A.out", "w", stdout);
#endif
	int k = read();
	for (int i = 0; i < 11; ++i) {
		for (int j = 0; j < 4; ++j)
			if (k > 0) {
				if (i == 0 || j != 2) {
					--k;
					a[i][j] = true;
				}
			}
			else a[i][j] = false;
	}

	printf("+------------------------+\n");
	printf("|");
	for (int i = 0; i < 11; ++i)
		if (a[i][0]) printf("O.");
		else printf("#.");
	printf("|D|)\n");
	printf("|");
	for (int i = 0; i < 11; ++i)
		if (a[i][1]) printf("O.");
		else printf("#.");
	printf("|.|\n");
	printf("|");
	if (a[0][2]) printf("O.");
	else printf("#.");
	for (int i = 0; i < 10; ++i)
		printf("..");
	printf("..|\n");
	printf("|");
	for (int i = 0; i < 11; ++i)
		if (a[i][3]) printf("O.");
		else printf("#.");
	printf("|.|)\n");
	printf("+------------------------+");
	return 0;
}