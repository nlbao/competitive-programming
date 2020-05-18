// #pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fori(i,a,b) for (ll i=(a); i<=(b); ++i)
#define ford(i,a,b) for (ll i=(a); i>=(b); --i)
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define err(x) cout << __LINE__ << ": " << #x << " = " << (x) << endl;
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define has(a, x) (a.find(x) != a.end())
#define all(x) x.begin(), x.end()
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


class Solution {
public:
	static const int N_CHAR = 30;
	static const int MAX_N = 501;

    vector<int> partitionLabels(string S) {
        int n = S.size();
        vector<int> lastPos(N_CHAR, -1);
        vector<int> endPos(n);
        vector<int> ans;
        for (int i = n-1; i >= 0; --i) {
        	int x = S[i]-'a';
        	if (lastPos[x] < 0)
        		lastPos[x] = i;
        	endPos[i] = lastPos[x];
        }
        int start = 0, end = 0;
        for (int i = 0; i < n; ++i) {
        	end = max(end, endPos[i]);
        	if (end == i) {
        		ans.push_back(end-start+1);
        		start = end = i+1;
        	}
        }
        return ans;
    }
};


int main() {
#ifdef DEBUG
	// freopen("file_name.in", "r", stdin);
	freopen("tmp.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	Solution solutionObj;
	// assert(solution.partitionLabels(ababcbacadefegdehijhklij) == vector<int>(){9, 7, 8});
	// vector<int> tmp = vector<int>(){9, 7, 8};
	// for (int i = 0; i < (int)tmp.size(); ++i)
		// cout << tmp[i] << endl;
	vector<int> ans = solutionObj.partitionLabels("ababcbacadefegdehijhklij");
	for (int i = 0; i < (int)ans.size(); ++i)
		cout << ans[i] << " ";
	cout << endl;

	return 0;
}