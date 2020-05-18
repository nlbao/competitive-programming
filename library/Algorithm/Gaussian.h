// for double
const double EPS = 1e-9;

// n = number of equations
// m = number of unknowns
// n may be != m
// number of arbitrary constants = m - rank
int gauss(vector< vector<double> > &a, vector<double> &ans) {
	int n = (int)a.size();
	int m = (int)a[0].size() - 1;
	for (int col = 0, row = 0; col < m && row < n; ++col) {
		int k = row;
		for (int i = row+1; i < n; ++i)
			if (fabs(a[i][col]) > fabs(a[k][col]))
				k = i;
		if (fabs(a[k][col]) < EPS) continue;

		for (int i = col; i <= m; ++i)
			swap(a[k][i], a[row][i]);
		for (int i = 0; i < n; ++i)
			if (i != row) {
				double c = a[i][col] / a[row][col];
				for (int j = col+1; j <= m; ++j)
					a[i][j] -= a[row][j] * c;
				a[i][col] = 0;
			}
		++row;
	}

	// check no solution
	for (int i = 0; i < n; ++i) {
		bool zero = true;
		for (int j = 0; j < m; ++j)
			if (fabs(a[i][j]) >= EPS) {
				zero = false;
				break;
			}
		if (zero && fabs(a[i][m]) >= EPS)
			return 0;
	}

	int rank = 0;
	ans.assign(m, 0);
	for (int i = 0, j = 0; i < n && j < m; ++j)
		if (fabs(a[i][j]) >= EPS) {
			ans[j] = a[i][m] / a[i][j];
			++i, ++rank;
		}
	if (rank < m) return oo;
	return 1;
}
///////////////////////////////////////////////////////////////////////////////////////



// for fraction
const Fraction ZERO = Fraction(0, 1);

int gauss(vector< vector<Fraction> > &a, vector<Fraction> &ans) {
	int n = (int)a.size();
	int m = (int)a[0].size() - 1;
	for (int col = 0, row = 0; col < m && row < n; ++col) {
		int k = row;
		for (int i = row+1; i < n; ++i)
			if (abs(a[i][col]) > abs(a[k][col]))
				k = i;
		if (a[k][col].a == 0) continue;

		for (int i = col; i <= m; ++i)
			swap(a[k][i], a[row][i]);
		for (int i = 0; i < n; ++i)
			if (i != row) {
				Fraction c = a[i][col] / a[row][col];
				for (int j = col+1; j <= m; ++j)
					a[i][j] = a[i][j] - (a[row][j] * c);
				a[i][col] = ZERO;
			}
		++row;
	}

	// check no solution
	for (int i = 0; i < n; ++i) {
		bool zero = true;
		for (int j = 0; j < m; ++j)
			if (a[i][j].a != 0) {
				zero = false;
				break;
			}
		if (zero && a[i][m].a != 0)
			return 0;
	}

	int rank = 0;
	ans.assign(m, ZERO);
	for (int i = 0, j = 0; i < n && j < m; ++j)
		if (a[i][j].a != 0) {
			ans[j] = a[i][m] / a[i][j];
			++i, ++rank;
		}
	if (rank < m) return oo;   // number of arbitrary constants = m - rank
	return 1;
}
///////////////////////////////////////////////////////////////////////////////////////



// for bitset (modulo 2)
int gauss(vector< bitset<MAX_N> > &a, int m, int &rank) {
	int n = a.size();
	for (int row = 0, col = 0; row < n && col < m; ++col) {
		for (int i = row; i < n; ++i)
			if (a[i][col]) {
				swap(a[row], a[i]);
				break;
			}
		if (!a[row][col]) continue;
		for (int i = 0; i < n; ++i)
			if (i != row && a[i][col])
				a[i] ^= a[row];
		++row;
	}

	for (int i = 0; i < n; ++i) {
		bool zero = true;
		for (int j = 0; j < m; ++j)
			if (a[i][j]) {
				zero = false;
				break;
			}
		if (zero && a[i][m])
			return 0;
	}
	rank = 0;
	for (int i = 0, j = 0; i < n && j < m; ++j)
		if (a[i][j]) {
			++rank;
			++i;
		}
	if (rank < m) return oo;
	return 1;
}
///////////////////////////////////////////////////////////////////////////////////////