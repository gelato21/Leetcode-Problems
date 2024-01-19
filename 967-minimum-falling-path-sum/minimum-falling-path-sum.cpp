class Solution {
public:
    // int f(int i, int j, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp){

        

    //     if(j<0 || j>=n) return 1e9;
    //     if(i==0) return matrix[i][j];

    //     if(dp[i][j]!=-1) return dp[i][j];

    //     int below=matrix[i][j]+f(i-1, j, n, matrix, dp);
    //     int left=matrix[i][j]+f(i-1, j+1, n, matrix, dp);
    //     int right=matrix[i][j]+f(i-1, j-1, n, matrix, dp);

    //     return dp[i][j]=min(right, min(left, below));
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int j=0;j<n;j++){
            dp[0][j]=matrix[0][j];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){

                int below=matrix[i][j] + dp[i-1][j];
                int left=matrix[i][j]+ ((j+1>=n) ? 1e9 : dp[i-1][j+1]);
                int right=matrix[i][j]+ ((j-1<0)  ? 1e9 : dp[i-1][j-1]);

                dp[i][j]=min(right, min(left, below));
            }
        }

        int ans=1e9;
        for(int j=0;j<n;j++){
            ans=min(ans, dp[n-1][j]);
        }
        return ans;

    }
};