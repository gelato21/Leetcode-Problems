class Solution {
public:

    int f(int ind, int target, vector<int>& perfectSquares, vector<vector<int>>& dp, int end){
        if(target==0){
            return 0;
        }
        if(ind>=end+1){
            return 1e5;
        }

        if(dp[ind][target]!=-1) return dp[ind][target];

        int notPick = f(ind+1, target, perfectSquares, dp, end);
        int pick=1e5;
        if(perfectSquares[ind]<=target){
           pick=1+f(ind, target-perfectSquares[ind], perfectSquares, dp, end);
        }

        return dp[ind][target]=min(pick, notPick);
    }
    int numSquares(int n) {
        int end=sqrt(n);
        vector<int> perfectSquares(end+1, 0);
        for(int i=1;i<=end;i++){
            perfectSquares[i]=i*i;
        }
        vector<vector<int>> dp(end+1, vector<int>(n+1, -1));
        return f(1, n, perfectSquares, dp, end);
    }
};