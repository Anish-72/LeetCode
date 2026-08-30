class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        int minIdx = 0;
        int maxIdx = 0;

        for(int i = 0; i<nums.size(); i++){
            if(minVal>nums[i]){
                minIdx = i;
                minVal = nums[i];
            }
            if(maxVal<nums[i]){
                maxIdx = i;
                maxVal = nums[i];
            }
        }
        
        int distStr = min(minIdx, maxIdx) + 1;
        int distEnd = nums.size() - max(minIdx, maxIdx);
        int distMid = max(minIdx, maxIdx) + 1 - distStr;
        int ans = 0;
        if(distStr < distEnd){
            ans += distStr;
            ans += min(distEnd, distMid); 
        }else{
            ans += distEnd;
            ans += min(distStr, distMid);
        }
        return ans;
    }
};