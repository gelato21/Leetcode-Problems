class Solution {
public:
    int f(int i, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1) return dp[i][buy];

        if(buy){
            return dp[i][buy]=max(-prices[i]+f(i+1, 0, prices, dp), f(i+1, 1, prices, dp));
        }
        else{
            return dp[i][buy]=max(prices[i]+f(i+2, 1, prices, dp), f(i+1, 0, prices, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // return f(0, 1, prices, dp);
        vector<vector<int>> dp(n+2, vector<int>(2, 0));

        // i>=n
        for(int i=n;i<n+2;i++){
            for(int buy=1;buy>=0;buy--){
                dp[i][buy]=0;
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    dp[i][buy]=max(-prices[i]+dp[i+1][0], dp[i+1][1]);
                }
                else{
                    dp[i][buy]=max(prices[i]+dp[i+2][1], dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
        
    }
};