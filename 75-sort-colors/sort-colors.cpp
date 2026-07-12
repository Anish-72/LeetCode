class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int> udm;

        for(int i  = 0; i<nums.size(); i++){
            udm[nums[i]]++;
        }

        for(int i = 0, j = 0; i<3; i++){
            while(udm[i] > 0){
                nums[j++] = i;
                udm[i]--;
            }
        }

    }
};