class Solution {
public:
    int f(int count, int n, int prevCopied, vector<vector<int>>& dp){
        if(count>n){
            return 1e5;
        }
        if(count==n){
            return 0;
        }
        if(dp[count][prevCopied]!=-1) return dp[count][prevCopied];

        int paste = 1 + f(count+prevCopied, n, prevCopied, dp);
        int copyAndpaste = 2 + f(count*2, n, count, dp);

        return dp[count][prevCopied]=min(paste, copyAndpaste);

    }
    int minSteps(int n) {
        if(n==1) return 0;
        vector<vector<int>> dp(n+3, vector<int>(n+5, -1));
        return 1 + f(1, n, 1, dp);
    }
};