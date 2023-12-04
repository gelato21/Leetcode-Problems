class Solution {
public:
    int f(int i, int buy, int fee, vector<int>& prices, vector<vector<int>>& dp){
        if(i==prices.size()) return 0;

        if(dp[i][buy]!=-1) return dp[i][buy];

        if(buy){
            return dp[i][buy]=max(-prices[i]+f(i+1, 0, fee, prices, dp), f(i+1, 1, fee, prices, dp));
        }
        else{
            return dp[i][buy]=max(prices[i]-fee+f(i+1, 1, fee, prices, dp), f(i+1, 0, fee, prices, dp));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        // vector<vector<int>> dp(n+1, vector<int>(2, 0));
        vector<int> prev(2, 0);
        vector<int> curr(2, 0);

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    curr[buy]=max(-prices[i]+prev[0], prev[1]);
                }
                else{
                    curr[buy]=max(prices[i]-fee+prev[1], prev[0]);
                }
            }
            prev=curr;
        }
        return prev[1];
    }
};