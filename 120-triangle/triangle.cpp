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
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        // return f(0, 0, n, triangle);

        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f2(0, 0, n, triangle, dp);
    }
};