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

using namespace std;

typedef long long ll;
typedef vector<int> vecint;
typedef pair<int, int> ppi;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }


const int MAX_N = 17;

int is_answer[MAX_N];


int main() {
#ifdef DEBUG
	freopen("A-small-attempt3.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif
	int nTest = read();
	for (int test_id = 1; test_id <= nTest; ++test_id) {
		fill(is_answer, 0);
		for (int id = 0; id < 2; ++id) {
			int row = read()-1;
			for (int i = 0; i < 4; ++i)
				for (int j = 0; j < 4; ++j) {
					int x = read();
					if (i == row)
						++is_answer[x];
				}
		}

		int c = 0, res = -1;
		for (int i = 1; i <= 16; ++i)
			if (is_answer[i] == 2) {
				++c;
				res = i;
			}

		printf("Case #%d: ", test_id);
		if (c == 0) printf("Volunteer cheated!\n");
		else if (c == 1) printf("%d\n", res);
		else printf("Bad magician!\n");
	}
	return 0;
}