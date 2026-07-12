class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int maxans = 0;
        int width = 0;
        int wall = 0;

        while(left<right){
            width = right - left;
            wall = min(height[left], height[right]);
            int ans = width * wall;
            maxans = max(maxans, ans);

            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }

        }
        return maxans;
    }
};