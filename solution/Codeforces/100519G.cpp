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

#define filla(a,x) memset(a, (x), sizeof(a))
#define foreach(it, X) for(typeof((X).begin()) it = (X).begin(); (it) != (X).end(); (it)++)
#define sqr(x) ((x)*(x))

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 2*int(1e5) + 5;


int n;
int p[MAX_N];
map<string, int> id;


int get(const string &s) {
	map<string, int>::iterator it = id.find(s);
	if (it == id.end()) {
		id[s] = ++n;
		return n;
	}
	return it->second;
}


int main() {
#ifdef DEBUG
	freopen("100519G.in", "r", stdin);
	freopen("100519G.out", "w", stdout);
#endif
	filla(p, -1);
	id.clear();
	n = 0;

	int m;
	cin >> m;
	while (m--) {
		string first, last, tmp, father;
		cin >> first >> last >> tmp >> tmp >> father;
		cout << first << ", " << last << ", " << father << endl;
		int u = get(first + " " + last);
		int v = get(father + " " + last);
	}

	return 0;
}