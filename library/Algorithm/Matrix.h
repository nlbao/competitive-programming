// for double


// Matrix Determinant
double determinant(vector< vector<double> > a) {
	int n = a.size();
	double det = 1.0;
	for (int i = 0; i < n; i++) {
		int k = i;
		for (int j = i; j < n; j++)
			if (fabs(a[j][i]) > fabs(a[k][i]))
				k = j;
		if (fabs(a[k][i]) < EPS) {det = 0; break;}
		swap(a[i], a[k]);
		if (i != k) det *= -1;
		det *= a[i][i];
		for (int j = i + 1; j < n; j++)
			a[i][j] /= a[i][i];
		for (int j = 0; j < n; j++)
			if (j != i && fabs(a[j][i]) > EPS)
				for (int k = i + 1; k < n; k++)
					a[j][k] -= a[i][k] * a[j][i];
	}
	return det;
}
///////////////////////////////////////////////////////////////////////////////////////



// Matrix Rank
int rank = max(n,m);
vector<char> line_used (n);
for (int i=0; i<m; ++i) {
	int j;
	for (j=0; j<n; ++j)
		if (!line_used[j] && abs(a[j][i]) > EPS)
			break;
	if (j == n)
		--rank;
	else {
		line_used[j] = true;
		for (int p=i+1; p<m; ++p)
			a[j][p] /= a[j][i];
		for (int k=0; k<n; ++k)
			if (k != j && abs (a[k][i]) > EPS)
				for (int p=i+1; p<m; ++p)
					a[k][p] -= a[j][p] * a[k][i];
	}
}
///////////////////////////////////////////////////////////////////////////////////////

// invert matrix
void invertMatrix(int* arr, int m_arr, int n_arr)
{
	if (m_arr != n_arr) {
		printf("Input matrix must be a square matrix.\n");
		return;
	}
	if (hasZeroDeterminant(arr, m_arr, n_arr)) {
		printf("Input matrix has determiant = 0.\n");
		return;
	}
	printf("invertMatrix():\n");

	// Gauss-Jordan Elimination
	// http://mathworld.wolfram.com/Gauss-JordanElimination.html
	// construct temporary matrix b
	int m = m_arr;
	int n = 2*n_arr;
	double *b = new double[m*n], *p = b;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j) {
			if (j < n_arr) *p = *(arr + i*n_arr + j);
			else {
				if (j == n_arr+i) *p = 1;
				else *p = 0;
			}
			++p;
		}

	/* using gauss-jordan elimination */
	for (int j = 0; j < m; j++) {
		int temp = j;
		/* finding maximum jth column element in last (dimension-j) rows */
		for (int i = j + 1; i < m; i++)
			if (*(b + i*n + j) > *(b + temp*n + j))
				temp = i;

		if (fabs(*(b + temp*n + j)) < EPS) {
			printf("\n Elements are too small to deal with !!!");
			return;
		}
		/* swapping row which has maximum jth column element */
		if (temp != j)
			for (int k = 0; k < n; k++) {
				double t = *(b + j*n + k);
				*(b + j*n + k) = *(b + temp*n + k);
				*(b + temp*n + k) = t;
			}
		/* performing row operations to form required identity matrix out 
		   of the input matrix */
		for (int i = 0; i < m; i++)
			if (i != j) {
				double r = *(b + i*n + j);
				for (int k = 0; k < n; k++)
					*(b + i*n + k) -= *(b + j*n + k) * r / *(b + j*n + j);
			} else {
				double r = *(b + i*n + j);
				for (int k = 0; k < n; k++)
					*(b + i*n + k) /= r;
			}
	}

	// get ans
	double *ans = new double[m_arr*n_arr];
	p = ans;
	for (int i = 0; i < m_arr; ++i)
		for (int j = 0; j < n_arr; ++j) {
			*p = *(b + i*n + j + n_arr);
			++p;
		}
	printMatrix(ans, m_arr, n_arr);
	delete[] b;
	delete[] ans;
}





///////////////////////////////////////////////////////////////////////////////////////



// Matrix Exponentiation
typedef vector < vector<ll> > Matrix;
const ll MOD = 1E15 + 7;

ll add(ll a, ll b) {
	return (a + b) % MOD;
}

ll mul(ll a, ll b) {
	if (b == 0) return 0;
	ll t = mul(a, b / 2);
	t = add(t, t);
	if (b & 1) t = add(t, a);
	return t;
}

Matrix create(int m, int n) {
	return Matrix(m, vector<ll>(n, 0));
}

Matrix mul(const Matrix &a, const Matrix &b) {
	Matrix c = create(a.size(), b[0].size());
	for (int i = 0; i < (int)a.size(); ++i)
		for (int j = 0; j < (int)b[0].size(); ++j)
			for (int k = 0; k < (int)a[i].size(); ++k)
				c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
	return c;
}

Matrix pow(const Matrix &a, ll n) {
	if (n == 1) return a;
	Matrix t = pow(a, n / 2);
	t = mul(t, t);
	if (n & 1) return mul(t, a);
	return t;
}
///////////////////////////////////////////////////////////////////////////////////////


// for fraction
ll determinant(vector< vector<Fraction> > a) {
	int n = a.size();
	Fraction det(1, 1);
	for (int i = 0; i < n; i++) {
		int k = i;
		for (int j = i; j < n; j++)
			if (abs(a[j][i]) > abs(a[k][i]))
				k = j;
		if (a[k][i].a == 0) {
			det = Fraction(0, 1);
			break;
		}
		swap(a[i], a[k]);
		if (i != k)
			det.a = -det.a;
		det = det * a[i][i];
		for (int j = i + 1; j < n; j++)
			a[i][j] = a[i][j] / a[i][i];
		for (int j = 0; j < n; j++)
			if (j != i && a[j][i].a != 0)
				for (int k = i + 1; k < n; k++)
					a[j][k] = a[j][k] - (a[i][k] * a[j][i]);
	}
	return det.a;
}
