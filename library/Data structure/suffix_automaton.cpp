// New Version
struct SAM {
	static const int MAX_A = 29;
	static const int MAX_N = 1e5+5;
	static const int MAX_SAM = 2*MAX_N;

	struct State {	// a node in the "directed acyclic word graph" (or simply "DAWG")
		int len;	// length of the path from root to this node (number of edges)
		int link;	// link to a node which is a suffix of this state
		int nexts[MAX_A];	// the node which is adjanced with this node by an edge ('a'..'z', '0'..'9', ...)

		State() {
			len=0;	link=-1;
			filla(nexts, -1);
		}

		void operator = (const State &o) {
			len=o.len;		link=o.link;
			fori(i,0,MAX_A-1) nexts[i]=o.nexts[i];
		}

		bool hasNext(int x) {	return nexts[x]>-1;		}
	};

	int nSAM, last, id[MAX_SAM], c[MAX_N];
	State sam[MAX_SAM];
	ll f[MAX_SAM];

	void init() {
		nSAM = 1;	// number of nodes
		last = 0;	// id of last node (start from 0)
		sam[0] = State();	// root node
		f[0] = 0;			// for some applications
	}

	void add(int x) {
		int cur = nSAM++;	// id of new node
		sam[cur] = State();
		sam[cur].len = sam[last].len + 1;
		f[cur] = 1;

		int p = last;
		for (; p != -1 && !sam[p].hasNext(x); p = sam[p].link)
			sam[p].nexts[x] = cur;

		if (p == -1) sam[cur].link = 0;
		else {
			int q = sam[p].nexts[x];
			if (sam[q].len != sam[p].len + 1) {
				int clone = nSAM++;		// create a clone node of q
				sam[clone] = sam[q];
				sam[clone].len = sam[p].len + 1;
				f[clone] = 0;
				for (; p != -1 && sam[p].nexts[x] == q; p = sam[p].link)
					sam[p].nexts[x] = clone;
				sam[cur].link = sam[q].link = clone;
			}
			else sam[cur].link = q;
		}
		last = cur;
	}
};


/*------------------------------------------------------------------------------------------------*/

// APLICATIONS

// we should do the topo sort (by length) before implement other features
for (int i = 0; i <= n; ++i) c[i] = 0;
for (int i = 0; i < nSAM; ++i) ++c[sam[i].len];
for (int i = 1; i <= n; ++i) c[i] += c[i-1];
for (int i = 0; i < nSAM; ++i) id[--c[sam[i].len]] = i;

// number of occurrents of state u, which corresponding to
// number of occurrents of each substrings from root to u
for (int i = nSAM-1; i >= 0; --i) {
	int u = id[i];
	f[sam[u].link] += f[u];
}

// number of ways to go from root to state u, which corresponding to number of different substrings end at u.
// If we sort these strings increasing by their lengths, then the i-th string is a suffix of the (i+1)-th string.
fill(g, 0);
g[0] = 1;
for (int i = 0; i < nSAM; ++i) {
	int u = id[i];
	foreach(it, sam[u].nexts)	// if sam[u].nexts is a map
		g[it->second] += g[u];
}

// number of substrings which have state u as their prefixes
for (int i = nSAM-1; i >= 0; --i) {
	int u = id[i];
	f[u] = 1;
	foreach(it, sam[u].nexts)	// // if sam[u].nexts is a map
		f[u] += f[it->second];
}