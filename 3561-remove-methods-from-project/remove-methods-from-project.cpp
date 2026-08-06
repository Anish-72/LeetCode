class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (const auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }
        
        vector<bool> susp(n, false);
        queue<int> q;
        
        q.push(k);
        susp[k] = true;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int nxt : adj[curr]) {
                if (!susp[nxt]) {
                    susp[nxt] = true;
                    q.push(nxt);
                }
            }
        }
        
        for (const auto& inv : invocations) {
            if (!susp[inv[0]] && susp[inv[1]]) {
                vector<int> res(n);
                for (int i = 0; i < n; ++i) {
                    res[i] = i;
                }
                return res;
            }
        }
        
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (!susp[i]) {
                res.push_back(i);
            }
        }
        
        return res;
    }
};