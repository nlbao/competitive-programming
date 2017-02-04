typedef pair<int, int> pii;

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int ans = W, n = Profits.size();
        vector<pii> capProPairs;
        for (int i = 0; i < n; ++i)
            capProPairs.push_back(pii(Capital[i], Profits[i]));
        sort(capProPairs.begin(), capProPairs.end());

        int i = 0;
        multiset<int> proHeap;
        while (k > 0) {
            while (i < n && capProPairs[i].first <= ans) {
                proHeap.insert(-capProPairs[i].second);
                ++i;
            }
            if (proHeap.empty()) break;
            ans += -*proHeap.begin();
            proHeap.erase(proHeap.begin());
            --k;
        }
        return ans;
    }
};