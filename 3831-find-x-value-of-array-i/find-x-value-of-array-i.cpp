class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);
        
        for (int num : nums) {
            vector<long long> next_dp(k, 0);
            int mod_val = num % k;
            next_dp[mod_val] = 1;
            
            for (int i = 0; i < k; ++i) {
                if (dp[i] > 0) {
                    next_dp[(1LL * i * mod_val) % k] += dp[i];
                }
            }
            
            for (int i = 0; i < k; ++i) {
                ans[i] += next_dp[i];
                dp[i] = next_dp[i];
            }
        }
        
        return ans;
    }
};