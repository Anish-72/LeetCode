class Solution {
public:
    int getGold(vector<vector<int>>& grid, int n, int m, int &maxGold, int currGold, int i, int j){
        if(i>n-1 || j>m-1 || i<0 || j<0){
            return 0;
        }
        if(grid[i][j] == 0){
            return 0;
        }
        currGold += grid[i][j];
        int goldinSlot = grid[i][j];
        grid[i][j] = 0;
        

        getGold(grid,n,m,maxGold,currGold,i+1,j);
        getGold(grid,n,m,maxGold,currGold,i-1,j);
        getGold(grid,n,m,maxGold,currGold,i,j+1);
        getGold(grid,n,m,maxGold,currGold,i,j-1);
    
        if(currGold > maxGold) {
            maxGold = currGold;
        }
        
        grid[i][j] = goldinSlot;
        return maxGold;

    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int overallMaxGold = 0;
        


        for(int i = 0; i<n; i++){
            for( int  j = 0; j<m; j++){
                if(grid[i][j] != 0){
                     getGold(grid, n, m, overallMaxGold,0,i,j);
                }
            }
        }
        return overallMaxGold;
    }
};