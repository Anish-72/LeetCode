class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

       if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int n = matrix[0].size();
        int m = matrix.size();
        int row = 0, col = 0;
        int si = 0, ei = n*m - 1;

        while(si<=ei){
            int mid = si + (ei - si)/2;
            row = mid%n;
            col = mid/n;

            if(matrix[col][row] == target){
                return true;
            }else if(matrix[col][row] > target){
                ei = mid - 1;
            }else{
                si = mid + 1;
            }
        }
        return false;

    }
};