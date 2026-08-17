class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(stoneValue, prefix, dp, 0, n - 1);
    }

private:
    int solve(const vector<int>& stoneValue, const vector<int>& prefix, vector<vector<int>>& dp, int i, int j) {
        if (i == j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int max_score = 0;
        for (int k = i; k < j; ++k) {
            int left_sum = prefix[k + 1] - prefix[i];
            int right_sum = prefix[j + 1] - prefix[k + 1];

            if (left_sum < right_sum) {
                max_score = max(max_score, left_sum + solve(stoneValue, prefix, dp, i, k));
            } else if (left_sum > right_sum) {
                max_score = max(max_score, right_sum + solve(stoneValue, prefix, dp, k + 1, j));
            } else {
                max_score = max({max_score, 
                                 left_sum + solve(stoneValue, prefix, dp, i, k), 
                                 right_sum + solve(stoneValue, prefix, dp, k + 1, j)});
            }
        }
        return dp[i][j] = max_score;
    }
};