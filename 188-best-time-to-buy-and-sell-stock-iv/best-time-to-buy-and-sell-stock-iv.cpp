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
        // return f(0, 1, k, prices, dp);
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        //cap==0
        // for(int i=0;i<=n;i++){
        //     for(int buy=0;buy<2;buy++){
        //         dp[i][buy][0]=0;
        //     }
        // }        
        // //i==n
        // for(int buy=0;buy<2;buy++){
        //     for(int cap=0;cap<3;cap++){
        //         dp[n][buy][cap]=0;
        //     }
        // }
        vector<vector<int>> prev(2, vector<int>(k+1, 0));
        vector<vector<int>> curr(2, vector<int>(k+1, 0));

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
                    if(buy==1){
                        curr[buy][cap]=max(-prices[i]+prev[0][cap], prev[1][cap]);
                    }
                    else curr[buy][cap]=max(prices[i]+prev[1][cap-1], prev[0][cap]);
                }
            }
            prev=curr;
        }
        return prev[1][k];
    }
};