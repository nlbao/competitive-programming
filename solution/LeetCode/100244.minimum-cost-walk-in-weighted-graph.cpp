typedef pair<int, int> pii;

class Solution {
public:
    // The more edges you travel, the smaller total weight, because of AND operator.
    // This means the minimum weight path between any two nodes in the same CONNECTED component is the same,
    // which is equal to the AND of all the edges in that component.
    // Weight of two nodes in different components is -1.
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        int nComp = 0;
        vector<int> comp(n+1, -1);
        vector<int> compWeight(n, -1);
        
        vector<vector<pii>> adj(n+1);
        int nEdge = edges.size();
        for (int i = 0; i < nEdge; ++i) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
        
        queue<int> q;
        for (int s = 1; s <= n; ++s) {
            if (comp[s] > -1) continue;
            int weight = -1;          
            q.push(s);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (comp[u] > -1) {
                    assert(comp[u] == nComp);
                    continue;
                }
                comp[u] = nComp;  
                for (int i = 0; i < adj[u].size(); ++i) {
                    q.push(adj[u][i].first);
                    int w = adj[u][i].second;
                    if (weight == -1) weight = w;
                    else weight &= w;
                }
            }
            compWeight[nComp] = weight;
            ++nComp;
        }
        
        vector<int> ans;
        int nQuery = query.size();
        for (int i = 0; i < nQuery; ++i) {
            int s = query[i][0];
            int t = query[i][1];
            if (s == t) ans.push_back(0);   // the problem statement does not mention this.
            else if (comp[s] != comp[t]) ans.push_back(-1);
            else ans.push_back(compWeight[comp[s]]);
        }
        return ans;
    }
};