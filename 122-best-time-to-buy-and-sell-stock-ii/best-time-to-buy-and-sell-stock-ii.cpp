class Solution {
public:
    int f(int i, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(i==prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            return dp[i][buy]=max(-prices[i]+f(i+1, 0, prices, dp), 0+f(i+1, 1, prices, dp));
        }
        else{
            return dp[i][buy]=max(prices[i]+f(i+1, 1, prices, dp), f(i+1, 0, prices, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>> dp(n+1, vector<int>(2, 0));
        // for(int i=0;i<2;i++){
        //     dp[n][i]=0;
        // }

        vector<int> prev(2, 0);
        vector<int> curr(2, 0);

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                if(buy){
                    curr[buy]=max(-prices[i]+prev[0], prev[1]);
                }
                else{
                    curr[buy]=max(prices[i]+prev[1], prev[0]);
                }
            }
            prev=curr;
        }
        return prev[1];


        // return f(0, 1, prices, dp);
    }
};