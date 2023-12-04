class Solution {
public:
    int f(int i, int buy, int count, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(count==2) return 0;
        if(i==prices.size()) return 0;

        if(dp[i][buy][count]!=-1){
            return dp[i][buy][count];
        }

        if(buy){
            return dp[i][buy][count]=max(-prices[i]+f(i+1, 0, count, prices, dp), f(i+1, 1, count, prices, dp));
        }
        else{
            return dp[i][buy][count]=max(prices[i]+f(i+1, 1, count+1, prices, dp), f(i+1, 0, count, prices, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, 0, prices, dp);
    }
};