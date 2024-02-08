class Solution {
public:

    int f(int ind, int target, vector<int>& perfectSquares, vector<vector<int>>& dp){
        if(target==0){
            return 0;
        }
        if(ind>=101){
            return 1e5;
        }

        if(dp[ind][target]!=-1) return dp[ind][target];

        int notPick = f(ind+1, target, perfectSquares, dp);
        int pick=1e5;
        if(perfectSquares[ind]<=target){
           pick=1+f(ind, target-perfectSquares[ind], perfectSquares, dp);
        }

        return dp[ind][target]=min(pick, notPick);
    }
    int numSquares(int n) {
        vector<int> perfectSquares(101, 0);
        for(int i=1;i<=100;i++){
            perfectSquares[i]=i*i;
        }
        vector<vector<int>> dp(101, vector<int>(n+1, -1));
        return f(1, n, perfectSquares, dp);
    }
};