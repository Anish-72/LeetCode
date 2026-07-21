class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> ans;
        int strow = 0;
        int stcol = 0;
        int edrow = r - 1;
        int edcol = c - 1;

        while (strow <= edrow && stcol <= edcol) {

            for(int  j = stcol; j<=edcol; j++){
                ans.push_back(matrix[strow][j]);
            }

            for(int i = strow+1; i<=edrow; i++){

                ans.push_back(matrix[i][edcol]);
            }
            
            for(int j = edcol-1; j>=stcol; j--){
                if(strow == edrow) {
                    break;
                }
                ans.push_back(matrix[edrow][j]);
            }
            for(int i = edrow-1; i>strow; i--){
                if(stcol == edcol){
                    break;
                }
                ans.push_back(matrix[i][stcol]);
            }
            strow++;edrow--;
            stcol++;edcol--;
        }
        return ans;
    }
};