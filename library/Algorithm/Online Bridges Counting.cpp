namespace BridgesCounting {
	const int MAX_N = 5e5+15;
	int n, crrTurn;
	int cc[MAX_N], bcc[MAX_N], ccSize[MAX_N], bccSize[MAX_N], turn[MAX_N];
	ll sumCC, sumBCC;

	// return number of ordered pairs, can be changed to return other values
	inline ll cal(ll x) {	x=abs(x);	return x*(x-1);		}

	void init(int nn) {
		n = nn;
		crrTurn = sumCC = sumBCC = 0;
		fori(i,1,n) {
			cc[i] = bcc[i] = -1;
			sumCC  += cal(ccSize[i]  = 1);
			sumBCC += cal(bccSize[i] = 1);
		}
	}

	int getBCC(int u) {
		return (u<0) ? -1 : (bcc[u]<0) ? u : bcc[u] = getBCC(bcc[u]);
	}

	int getCC(int u) {
		u = getBCC(u);
		return (cc[u]<0) ? u : getCC(cc[u]);
	}

	int unionBCC(int r, int u) {
		r = getBCC(r), u = getBCC(u);
		int ans=0;
		while (u!=r) {
			++ans;
			sumBCC -= cal(bccSize[r]) + cal(bccSize[u]);
			bccSize[r] += bccSize[u];
			sumBCC += cal(bccSize[r]);
			bcc[u] = r;
			u = getBCC(cc[u]);
		}
		return ans;		// number of removed
	}

	void unionCC(int r, int u) {
		r = getBCC(r), u = getBCC(u);
		cc[u] = r;
		sumCC -= cal(ccSize[u]);
		int last;
		while (r>0) {
			last = ccSize[r];
			ccSize[r] += ccSize[u];
			r = getBCC(cc[r]);
		}
		sumCC += cal(ccSize[getCC(u)]) - cal(last);
	}

	int lcaBCC(int u, int v) {
		u = getBCC(u), v = getBCC(v);
		++crrTurn;
		while (u>0) {
			turn[u]=crrTurn;
			u = getBCC(cc[u]);
		}
		while (v>0) {
			if (turn[v]==crrTurn) return v;
			v = getBCC(cc[v]);
		}
		return -1;
	}

	void reversePath(int u, int pre) {
		ccSize[u] -= pre;
		if (cc[u]<0) return;
		int r = getBCC(cc[u]);
		reversePath(r, pre + ccSize[u]);
		ccSize[u] += ccSize[r];
		cc[r] = u;
	}

	int addEdge(int x, int y) {	  // return number of added / removed bridges
		int u=getCC(x), v=getCC(y);
		x=getBCC(x), y=getBCC(y);
		if (x==y) return 0;
		if (u!=v) {
			if (ccSize[v] > ccSize[u]) swap(x, y);
			reversePath(y, 0);
			unionCC(x, y);
			return 1;	// add 1 bridge
		}
		int r = lcaBCC(x, y), c=0;
		c += unionBCC(r, x);
		c += unionBCC(r, y);
		return -c;		// remove c bridges
	}
};