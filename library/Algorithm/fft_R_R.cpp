typedef long double DOUBLE;
typedef complex<DOUBLE> COMPLEX;
typedef vector<DOUBLE> VD;
typedef vector<COMPLEX> VC;

const double PI = acos(-1.0);

struct FFT {
	VC A;
	int n, L;

	int ReverseBits(int k) {
		int ret = 0;
		for (int i = 0; i < L; i++) {
			ret = (ret << 1) | (k & 1);
			k >>= 1;
		}
		return ret;
	}

	void BitReverseCopy(const VC &a) {
		for (n = 1, L = 0; n < (int)a.size(); n <<= 1, L++);
		A.resize(n);
		for (int k = 0; k < n; k++)
			A[ReverseBits(k)] = a[k];
	}

	VC DFT(const VC &a, bool inverse) {
		BitReverseCopy(a);
		for (int s = 1; s <= L; s++) {
			int m = 1 << s;
			COMPLEX wm = exp(COMPLEX(0, 2.0 * PI / m));
			if (inverse) wm = COMPLEX(1, 0) / wm;
			for (int k = 0; k < n; k += m) {
				COMPLEX w = 1;
				for (int j = 0; j < m / 2; j++) {
					COMPLEX t = A[k + j + m/2] * w;
					COMPLEX u = A[k + j];
					A[k + j] = u + t;
					A[k + j + m/2] = u - t;
					w = w * wm;
				}
			}
		}
		if (inverse) for (int i = 0; i < n; i++) A[i] /= n;
		return A;
	}

	VD Convolution(const VD &a, const VD &b) {
		int na = a.size(), nb = b.size();
		int L = 1;
		while ((1 << L) < na) L++;
		while ((1 << L) < nb) L++;
		int n = 1 << (L + 1);

		VC aa, bb;
		for (int i = 0; i < n; i++) aa.push_back(i < na ? COMPLEX(a[i], 0) : 0);
		for (int i = 0; i < n; i++) bb.push_back(i < nb ? COMPLEX(b[i], 0) : 0);

		VC AA = DFT(aa, false);
		VC BB = DFT(bb, false);
		VC CC;

		for (int i = 0; i < (int)AA.size(); i++) CC.push_back(AA[i] * BB[i]);
		VC cc = DFT(CC, true);

		VD c;
		for (int i = 0; i < na + nb - 1; i++) c.push_back(cc[i].real());
		return c;
	}

	vector<ll> mul(const vector<ll> &a, const vector<ll> &b) {
		VD fa(a.begin(), a.end());
		VD fb(b.begin(), b.end());
		VD tmp = Convolution(fa, fb);
		int n = tmp.size();
		vector<ll> ans(n, 0);
		for (int i = 0; i < n; ++i)
			ans[i] = tmp[i] + 0.5;
		return ans;
	}
};





////////////////////////////////////////////////////////////////////////////////
/*Optimize*/
////////////////////////////////////////////////////////////////////////////////




typedef long double DOUBLE;
typedef complex<DOUBLE> COMPLEX;
typedef vector<DOUBLE> VD;
typedef vector<COMPLEX> VC;

const double PI = acos(-1.0);

struct FFT {
	VC A;
	int n, L;

	int ReverseBits(int k) {
		int ret = 0;
		for (int i = 0; i < L; i++) {
			ret = (ret << 1) | (k & 1);
			k >>= 1;
		}
		return ret;
	}

	void BitReverseCopy(const VC &a) {
		for (n = 1, L = 0; n < (int)a.size(); n <<= 1, L++);
		A.resize(n);
		for (int k = 0; k < n; k++)
			A[ReverseBits(k)] = a[k];
	}

	void DFT(const VC &a, bool inverse, VC &ans) {
		BitReverseCopy(a);
		for (int s = 1; s <= L; s++) {
			int m = 1 << s;
			COMPLEX wm = exp(COMPLEX(0, 2.0 * PI / m));
			if (inverse) wm = COMPLEX(1, 0) / wm;
			for (int k = 0; k < n; k += m) {
				COMPLEX w = 1;
				for (int j = 0; j < m / 2; j++) {
					COMPLEX t = A[k + j + m/2] * w;
					COMPLEX u = A[k + j];
					A[k + j] = u + t;
					A[k + j + m/2] = u - t;
					w = w * wm;
				}
			}
		}
		if (inverse) for (int i = 0; i < n; i++) A[i] /= n;
		ans.resize(n);
		for (int i = 0; i < n; ++i)
			ans[i] = A[i];
	}

	void Convolution(const VD &a, const VD &b, VD &c) {
		int na = a.size(), nb = b.size();
		int L = 1;
		while ((1 << L) < na) L++;
		while ((1 << L) < nb) L++;
		int n = 1 << (L + 1);

		VC aa, bb;
		for (int i = 0; i < n; i++) aa.push_back(i < na ? COMPLEX(a[i], 0) : 0);
		for (int i = 0; i < n; i++) bb.push_back(i < nb ? COMPLEX(b[i], 0) : 0);

		VC AA, BB;
		DFT(aa, false, AA);
		DFT(bb, false, BB);

		VC CC, cc;
		for (int i = 0; i < (int)AA.size(); i++) CC.push_back(AA[i] * BB[i]);
		DFT(CC, true, cc);

		c.clear();
		for (int i = 0; i < na + nb - 1; i++) c.push_back(cc[i].real());
	}

	void mul(const vector<ll> &a, const vector<ll> &b, vector<ll> &ans) {
		VD fa(a.begin(), a.end());
		VD fb(b.begin(), b.end());
		VD tmp;
		Convolution(fa, fb, tmp);
		int n = tmp.size();
		ans.resize(n, 0);
		for (int i = 0; i < n; ++i)
			ans[i] = tmp[i] + 0.5;
	}
};