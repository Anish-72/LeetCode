class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxInt = -1;
        for(int i = 0; i<nums.size(); i++){
            maxInt = max(maxInt, nums[i]);
        }
        int result = 0;

        for(int i = 0; i<nums.size(); i++){
            int count = maxInt - nums[i];
            result += count;
        }
        return result;
    }
};