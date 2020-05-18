/*****************************************************************************
 * Author: nlbao
 * Problem: https://leetcode.com/contest/leetcode-weekly-contest-16a/problems/find-permutation/
 *****************************************************************************/


#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)


class Solution {
public:
	vector<int> findPermutation(string s) {
		int n = (int)s.size() + 1;
		vector<int> ans(n, 0);
		vector<int> d(n, 0);
		vector<vector<int> > e(n, vector<int>());
		for (int i = 0; i < n-1; ++i) {
			int u = i, v = u+1;
			if (s[i] == 'I') e[u].push_back(v), ++d[v];
			else e[v].push_back(u), ++d[u];
		}

		set<int> heap;
		int cnt = 0;
		for (int i = 0; i < n; ++i)
			if (d[i] == 0)
				heap.insert(i);
		while (!heap.empty()) {
			int u = *heap.begin();
			heap.erase(heap.begin());
			ans[u] = ++cnt;
			foreach(it, e[u]) {
				int v = *it;
				--d[v];
				if (d[v] == 0)
					heap.insert(v);
			}
		}
		return ans;
	}
};