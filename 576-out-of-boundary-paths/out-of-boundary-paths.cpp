class Solution {
public:
    int mod=1e9+7;
    vector<pair<int, int>> moves={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dfs(int row, int col, int maxMove, int m, int n, vector<vector<vector<int>>>& dp){
        if(row>=m || col>=n || row<0 || col<0){
            return 1;
        }
        if(maxMove==0){
           return 0;
        }

        if(dp[row][col][maxMove]!=-1) return dp[row][col][maxMove];

        int ans=0;
        for(pair<int,int> move: moves){
            int newRow=row+move.first;
            int newCol=col+move.second;

            ans=(ans%mod+dfs(newRow, newCol, maxMove-1, m, n, dp)%mod)%mod;
        }
        return dp[row][col][maxMove]=ans%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(maxMove+1, -1)));
        return dfs(startRow, startColumn, maxMove, m, n, dp)%mod;
        
    }
};