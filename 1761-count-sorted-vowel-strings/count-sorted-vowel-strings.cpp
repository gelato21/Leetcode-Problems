class Solution {
public:
    int f(int ind, int n, vector<vector<int>>& dp){
        if(n==0) return 1;
        if(ind>=5) return 0;

        if(dp[ind][n]!=-1) return dp[ind][n];
        //pick
        int pick=f(ind, n-1, dp);
        //notpick
        int notpick=f(ind+1, n, dp);

        return dp[ind][n]=pick+notpick;
    }
    int countVowelStrings(int n) {
        vector<vector<int>> dp(5, vector<int>(n+1, -1));
        return f(0, n, dp);
    }
};