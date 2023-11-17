class Solution {
public:
    //Recursion
    int f(int i, int j, vector<vector<int>>& grid){
        if(i==0 && j==0){
            return grid[i][j];
        }
        if(i<0 || j<0) return 9000000;

        int up=grid[i][j]+f(i-1, j, grid);
        int left=grid[i][j]+f(i, j-1, grid);

        return min(up, left);
    }

    //Recursion with Memoization

    int RecwithMemo(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i==0 && j==0) return grid[i][j];
        if(i<0 || j<0) return 9000000;

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up=grid[i][j]+RecwithMemo(i-1, j, grid, dp);
        int left=grid[i][j]+RecwithMemo(i, j-1, grid, dp);

        return dp[i][j]=min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        // return f(grid.size()-1, grid[0].size()-1, grid);
        
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return RecwithMemo(grid.size()-1, grid[0].size()-1, grid, dp);
    }
};