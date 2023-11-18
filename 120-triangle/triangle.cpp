class Solution {
public:
    //Recursion
    int f(int i, int j, int n, vector<vector<int>>& triangle){
        if(i==n-1){
            return triangle[i][j];
        }
        int down=triangle[i][j]+f(i+1, j, n, triangle);
        int right=triangle[i][j]+f(i+1, j+1, n, triangle);

        return min(down, right);
    }
    //Recursion with Memoization
    int f2(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(i==n-1) return triangle[i][j];

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down=triangle[i][j]+f2(i+1, j, n, triangle, dp);
        int right=triangle[i][j]+f2(i+1, j+1, n, triangle, dp);

        return dp[i][j]=min(down, right);
    }
    //tabulation
    int tabulation(vector<vector<int>>& triangle){
        int n=triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+dp[i+1][j];
                int right=triangle[i][j]+dp[i+1][j+1];
                
                dp[i][j]=min(down, right);
            }
        }
        return dp[0][0];

    }
    //Space Optimization
    int SpaceOpti(vector<vector<int>>& triangle){
        int n=triangle.size();
        vector<int> prev(n, 0), curr(n, 0);

        for(int j=0;j<n;j++){
            prev[j]=triangle[n-1][j];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+prev[j];
                int right=triangle[i][j]+prev[j+1];
                curr[j]=min(down, right);
            }
            prev=curr;
        }
        return prev[0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        // return f(0, 0, n, triangle);

        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return f2(0, 0, n, triangle, dp);

        // return tabulation(triangle);

        return SpaceOpti(triangle);
    }
};