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

const int MAX_N = 111;
const int MAX_BIT = 64;

vector< bitset<MAX_N> > a;
vector<int> id;
ll value[MAX_N];


void print(vector< bitset<MAX_N> > &a) {
	// int n = a.size();
	int n = 5;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 5; ++j)
			cout << a[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}


int gauss(vector< bitset<MAX_N> > &a, int n, int m, vector<int> &id) {
	// for (int col = m-1, row = 0; col >= 0 && row < n; --col) {
	for (int col = 0, row = 0; col < m && row < n; ++col) {
		for (int i = row; i < n; ++i)
			if (a[i][col]) {
				swap(a[i], a[row]);
				swap(id[i], id[row]);
				break;
			}
		if (!a[row][col]) continue;
		for (int i = 0; i < n; ++i)
			if (i != row && a[i][col])
				a[i] ^= a[row];
		++row;
	}
	return -1;
}


int main() {
#ifdef DEBUG
	freopen("1272.in", "r", stdin);
	freopen("1272.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);

	int nTest, n;
	cin >> nTest;
	for (int test_id = 1; test_id <= nTest; ++test_id) {
		cin >> n;
		a.clear();
		a.resize(MAX_BIT);
		for (int i = 0; i < n; ++i) {
			cin >> value[i];
			for (int j = 0; j < MAX_BIT; ++j)
				a[j][i] = (value[i]>>j)&1;
		}

		id.clear();
		id.resize(MAX_BIT);
		for (int i = 0; i < MAX_BIT; ++i)
			id[i] = i;
		print(a);
		gauss(a, MAX_BIT, n, id);
		print(a);

		ll ans = 0;
		for (int i = 0; i < MAX_BIT; ++i)
			for (int j = 0; j < n; ++j)
				if (a[i][j]&1) {
					cout << "		" << id[i] << " " << j << " " << value[j] << endl;
					// ans ^= (1<<id[i]);
					ans ^= value[j];
					break;
				}
		cout << "Case " << test_id << ": " << ans << '\n';
	}
	return 0;
}