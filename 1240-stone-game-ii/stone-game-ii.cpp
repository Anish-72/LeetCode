class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        vector<int> suffix(n + 1, 0);
        
        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + piles[i];
        }
        
        return solve(0, 1, piles, suffix, dp);
    }
    
private:
    int solve(int i, int m, vector<int>& piles, vector<int>& suffix, vector<vector<int>>& dp) {
        int n = piles.size();
        if (i >= n) return 0;
        if (2 * m >= n - i) return suffix[i];
        if (dp[i][m] != -1) return dp[i][m];
        
        int res = 0;
        for (int x = 1; x <= 2 * m; ++x) {
            res = max(res, suffix[i] - solve(i + x, max(m, x), piles, suffix, dp));
        }
        
        return dp[i][m] = res;
    }
};