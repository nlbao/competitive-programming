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

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vecint;
typedef pair<int, int> ppi;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }


const int MAX_N = int(1e2+2);
const int MAX_C = int(1e3+3);


int find2(int n) {
	// int res = ln(n)/ln(2);
	// res = 1<<res;
	int res = 1;
	while (res < n)
		res <<= 1;
	return res;
}


void pushToMap(map<int, int> &q, int value) {
	if (q.find(value) == q.end())
		q[value] = 1;
	else
		++q[value];
}


int popFromMap(map<int, int> &q) {
	map<int, int>::iterator it = q.begin();
	if (it->second == 1)
		q.erase(it);
	else
		--(it->second);
	return it->first;
}


class BoxesDiv2 {
public:
	int findSize(vector<int> a) {
		map<int, int> q;
		int n = a.size();
		for (int i = 0; i < n; ++i)
			pushToMap(q, find2(a[i]));

		while (n > 1) {
			int a = popFromMap(q);
			int b = popFromMap(q);
			n -= 2;
			pushToMap(q, find2(a+b));
			++n;
		}
		return q.begin()->first;
	}
};


int main() {
#ifdef DEBUG
	freopen("BoxesDiv2.in", "r", stdin);
	freopen("BoxesDiv2.out", "w", stdout);
#endif
	int nTest = read();
	BoxesDiv2 main_class;
	for (int test_id = 0; test_id < nTest; ++test_id) {
		vector<int> v;
		int n = read();
		for (int i = 0; i < n; ++i)
			v.push_back(read());
		printf("%d\n", main_class.findSize(v));
	}
	return 0;
}