class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                dp[i]=cost[i];
            }else{
                dp[i]=min(cost[i]+dp[i+1], cost[i]+dp[i+2]);
            }
        }
        return min(dp[0], dp[1]);
    }
};