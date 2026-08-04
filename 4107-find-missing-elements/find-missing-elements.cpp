class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        if(!nums.size()){};

        vector<bool>freq(101,false);

        int maxInt = INT_MIN;
        int minInt = INT_MAX;

        for(int i = 0; i<nums.size(); i++){

            maxInt = max(maxInt, nums[i]);
            minInt = min(minInt, nums[i]);

            if(!freq[nums[i]]){
                freq[nums[i]] = true;
            }

        }

        vector<int>ans;

        for(int i = minInt; i<=maxInt; i++){

            if(!freq[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};