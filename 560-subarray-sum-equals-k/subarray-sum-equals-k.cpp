class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>udm;
        udm[0] = 1;
        int count = 0;
        int preSum = 0;

        for(int i = 0; i<nums.size(); i++){
            preSum += nums[i];
            int remove = preSum - k;
            count += udm[remove];
            udm[preSum] += 1;  
        }

        return count;
    }
};