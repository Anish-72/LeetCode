class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int left = 0;
        int right = nums.size()-1;
        int lzor = 0;
        int rzor = 0;
        while(left<=right){
            if(left == right){
                lzor = lzor ^ nums[left++];
            }else{
                 lzor = lzor ^ nums[left++];
                  rzor = rzor ^ nums[right--];
            }
            
           
        }

        return lzor ^ rzor;
    }
};