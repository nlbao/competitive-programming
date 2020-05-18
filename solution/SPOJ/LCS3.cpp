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

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }

// const int MAX_N = int(1e6)+6;
const int MAX_M = 7;
const int MAX_STATE = 1<<MAX_M;
const int MAX_A = int(1e4)+4;


int n, m, nState;
int b[MAX_M], state[MAX_STATE];
vector<int> pos[MAX_A];


bool cmp(int x, int y) {
	int i = 0, j = 0;
	while (i < m || j < m) {
		while (i < m && !(x & (1<<i))) ++i;
		while (j < m && !(y & (1<<j))) ++j;
		if (i >= m) return true;
		if (j >= m) return false;
		if (b[i] != b[j])
			return b[i] < b[j];
		++i;	++j;
	}
	return true;
}


int find(int value, int start) {
	int l = 0, r = (int)pos[value].size() - 1, t = -1;
	while (l <= r) {
		int mid = (l+r)>>1;
		if (pos[value][mid] < start)
			l = mid+1;
		else {
			t = pos[value][mid];
			r = mid-1;
		}
	}
	return t;
}


int main() {
#ifdef DEBUG
	freopen("LCS3.in", "r", stdin);
	freopen("LCS3.out", "w", stdout);
#endif
	n = read();
	for (int i = 0; i < MAX_A; ++i) pos[i].clear();
	for (int i = 0; i < n; ++i) {
		int a = read();
		pos[a].push_back(i);
	}

	int nQ = read();
	while (nQ--) {
		m = read();
		for (int i = 0; i < m; ++i)
			b[i] = read();
		nState = (1<<m);
		for (int i = 0; i < nState; ++i)
			state[i] = i;

		sort(state, state + nState, cmp);

		int ans = 0, len = 0;
		for (int id = 0; id < nState; ++id) {
			int c = 0, start = 0;
			bool found = true;
			for (int i = 0; i < m; ++i) if (state[id] & (1<<i)) {
				++c;
				int t = find(b[i], start);
				if (t == -1) {
					found = false;
					break;
				}
				start = t+1;
			}
			if (found && c > len) {
				len = c;
				ans = state[id];
			}
		}

		printf("%d ", len);
		for (int i = 0; i < m; ++i) if (ans & (1<<i))
			printf("%d ", b[i]);
		printf("\n");
	}
	return 0;
}