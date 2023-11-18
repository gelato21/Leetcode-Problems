class Solution {
public:
    //Recursion
    int f(int i, int j, int n, vector<vector<int>>& matrix){
        if(j<0 || j>=n) return 1e9;
        if(i==n-1) return matrix[i][j];
        
        int below=f(i+1, j, n, matrix);
        int left=f(i+1, j-1, n, matrix);
        int right=f(i+1, j+1, n, matrix);

        return matrix[i][j]+min(below, min(left, right));
    }

    // Memoization
    int f2(int i, int j, int n, vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(j<0 || j>=n) return 1e9;
        if(i==n-1) return matrix[i][j];

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int down=f2(i+1, j, n, matrix, dp);
        int left=f2(i+1, j-1, n, matrix, dp);
        int right=f2(i+1, j+1, n, matrix, dp);

        return dp[i][j]=matrix[i][j]+min(down, min(left, right));
    }
    //Tabulation

    vector<vector<int>> tabulation(vector<vector<int>>& matrix){
        int n=matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));

        dp[n-1]=matrix[n-1];

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int down=1e9, left=1e9, right=1e9;
                down=dp[i+1][j];
                if(j-1>=0){
                    left=dp[i+1][j-1];
                }
                if(j+1<n){
                    right=dp[i+1][j+1];
                }

                dp[i][j]=matrix[i][j]+min(down, min(right, left));
            }
        }
        return dp;
    }

    //Space Optimization

    int sapceOpti(vector<vector<int>>& matrix){
        int n=matrix.size();

        vector<int> prev;
        prev=matrix[n-1];

        for(int i=n-2;i>=0;i--){
            vector<int > temp(n);
            for(int j=0;j<n;j++){
                int down=1e9, left=1e9, right=1e9;
                down=prev[j];
                if(j-1>=0){
                    left=prev[j-1];
                }
                if(j+1<n){
                    right=prev[j+1];
                }

                temp[j]=matrix[i][j]+min(down, min(right, left));
            }
            prev=temp;
        }
        int ans=INT_MAX;
        for(int i=0;i<prev.size();i++){
            ans=min(ans, prev[i]);
        }
        return ans;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();

        // int ans=1e9;
        // for(int j=0;j<n;j++){
        //     ans=min(ans, f(0, j, n, matrix));
        // }
        // return ans;    

        // int ans=1e9;
        // for(int j=0;j<n;j++){
        //     vector<vector<int>> dp(n, vector<int>(n, -1));
        //     ans=min(ans, f(0, j, n, matrix));
        // }
        // return ans;


        // int ans=INT_MAX;
        // vector<vector<int>>dp=tabulation(matrix);
        // for(int j=0;j<n;j++){
        //     ans=min(ans, dp[0][j]);
        // }
        // return ans;

        return sapceOpti(matrix);
    }
};