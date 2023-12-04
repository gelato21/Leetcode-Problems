class Solution {
public:
    int f(int i, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(cap==0 || i==prices.size()){
            return 0;
        }

        if(dp[i][buy][cap]!=-1){
            return dp[i][buy][cap];
        }

        if(buy==1){
            return dp[i][buy][cap]=max(-prices[i]+f(i+1, 0, cap, prices, dp), f(i+1, 1, cap, prices, dp));
        }
        else return dp[i][buy][cap]=max(prices[i]+f(i+1, 1, cap-1, prices, dp), f(i+1, 0, cap, prices, dp));

    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return f(0, 1, k, prices, dp);
    }
};