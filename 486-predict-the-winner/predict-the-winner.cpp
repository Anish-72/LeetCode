class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        return helperFn(nums, 0, nums.size() - 1) >= 0;
    }

private:
    int helperFn(const vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }
        
        int pickLeft = nums[left] - helperFn(nums, left + 1, right);
        int pickRight = nums[right] - helperFn(nums, left, right - 1);
        
        return max(pickLeft, pickRight);
    }
};