#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

const int64 TEMP = 0;

int main() {

	// freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int64 x, y; cin >> x >> y; ) {
		if (x <= y) {
			y *= TEMP;
			int64 incr[11];
			for (int i = 1; i <= x; i++)
				incr[i] = x * TEMP / i;
			int64 result = 0;
			int64 _y = incr[1];
			for (int _x = 1; _x <= x; _x++) {
				if (_x < x) result++;
				if (_y < y) {
					int64 t = (y + (TEMP-1) - _y) / incr[_x];
					_y += t * incr[_x];
					result += t;
				}
			}
			cout << result << "\n";
		} else {
			cout << -1 << "\n";
		}

	}

	return 0;
}