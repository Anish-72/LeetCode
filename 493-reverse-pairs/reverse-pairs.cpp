class Solution {
public:
    

    void merge(vector<int>&nums,int si, int ei, int mid){
        vector<int> temp;
        int i = si, j=mid+1;
        while(i<=mid && j<=ei){
            if(nums[i]<nums[j]){
                temp.push_back(nums[i++]);
            }else{
                temp.push_back(nums[j++]);
            }
        }

        while(i<=mid){
            temp.push_back(nums[i++]);
        }
        while(j<=ei){
            temp.push_back(nums[j++]);
        }
        for(int k = si; k<=ei; k++){
            nums[k] = temp[k - si];
        }
        
    }
    int fun(vector<int>&nums,int si, int ei, int mid){
        int right = mid + 1;
        int count = 0;

        for(int i = si; i<=mid;i++){
            while(right<=ei && (long long)nums[i] > 2LL*nums[right]){
                right++;
            }
            count += right - (mid +1);
        }
        return count;
    }
    int mergesort(vector<int>& nums,int si, int ei){
        if(si>=ei){
            return 0;
        }

        int mid = si + (ei - si)/2;
        int count = 0;

        count += mergesort(nums,si,mid);
        count += mergesort(nums,mid+1,ei);
        count += fun(nums,si,ei,mid);
        merge(nums,si,ei,mid);
        return count;
       
    }
    int callfn(vector<int>& nums){
        int si = 0;
        int ei = nums.size()-1;
       return mergesort(nums, si,ei);
    }
    int reversePairs(vector<int>& nums) {
        return callfn(nums);
    }
};