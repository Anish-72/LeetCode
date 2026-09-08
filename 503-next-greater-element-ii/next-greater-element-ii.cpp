class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk;
        vector<int> ans(n,-1);

        stk.push(n - 1);
        ans[n - 1] = -1;
        

        for (int i = 2 * n - 2; i >= 0; i--) {
           
            int idx = i%n;

            int curr = nums[idx];
            while (!stk.empty() && curr >= nums[stk.top()]) {

                stk.pop();
            }
            if (stk.empty()) {
                ans[idx] = -1;
            } else {
                ans[idx] = nums[stk.top()];
            }
            stk.push(idx);
        }
        return ans;
    }
};