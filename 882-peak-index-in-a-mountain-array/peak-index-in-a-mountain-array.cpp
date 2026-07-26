class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int si = 1;
        int ei = arr.size()-2;

        while(si<=ei){
            int mid = si + (ei - si)/2;

            if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]){
                return mid;
            }else if(arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1]){
                si = mid + 1;
            }else{
                ei = mid - 1;
            }
        }
        return -1;
    }
};