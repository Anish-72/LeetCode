class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i = 0; i<nums.size(); i++){

            if(i>0 && nums[i] == nums[i-1]) continue;

            int target = -nums[i];
            int si = i + 1;
            int ei = nums.size()-1;

            while(si<ei){

                if(nums[si] + nums[ei] == target){

                    ans.push_back({nums[i], nums[si], nums[ei]});
                    si++;
                    ei--;
                    while( si < ei && nums[si] == nums[si - 1]) si++;
                    while(ei > si && nums[ei] == nums[ei + 1]) ei--;

                }else if(nums[si] + nums[ei] > target){
                        ei--;
                        while(ei > si && nums[ei] == nums[ei + 1]) ei--; 
                }else{
                    si++;
                    while( si < ei && nums[si] == nums[si - 1]) si++;
                }
            }           
        }
        return ans;
    }
};