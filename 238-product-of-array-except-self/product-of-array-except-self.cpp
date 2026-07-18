class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int>ans(nums.size());
        int leftpd = 1;
        int rightpd = 1;

        for(int i = 0; i< nums.size(); i++){
            ans[i] = leftpd;
            leftpd = leftpd * nums[i];
        }

        for(int i = nums.size()-1; i>=0; i--){
            ans[i] = ans[i] * rightpd;
            rightpd = rightpd * nums[i];
        }

       return ans;
    }
};