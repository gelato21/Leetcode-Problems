class Solution {
public:
    int MOD=1e9+7;
    int f(int n, int target, int k, vector<vector<int>>& dp){
        if(n==0){
            if(target==0){
                return 1;
            }
            else return 0;
        }
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        long long ans=0;
        for(int i=1;i<=k;i++){
            if(i<=target)
            ans+=f(n-1, target-i, k, dp)%MOD;
        }
        return dp[n][target]=ans%MOD;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                long long ans=0;
                for(int l=1;l<=k;l++){
                    if(l<=j)
                    ans+=dp[i-1][j-l]%MOD;
                }
                dp[i][j]=ans%MOD;
            }
        }
        return dp[n][target];
    }
};