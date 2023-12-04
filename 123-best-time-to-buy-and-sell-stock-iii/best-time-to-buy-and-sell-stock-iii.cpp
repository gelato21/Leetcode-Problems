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
        int n=prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        // for(int i=0;i<=n;i++){
        //     for(int buy=0;buy<2;buy++){
        //         dp[i][buy][2]=0;
        //     }
        // }
        // for(int buy=0;buy<2;buy++){
        //     for(int count=0;count<3;count++){
        //         dp[n][buy][count]=0;
        //     }
        // }

        vector<vector<int>> after(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));
        
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int count=2;count>0;count--){
                    if(buy){
                        curr[buy][count]=max(-prices[i]+after[0][count], after[1][count]);
                    }
                    else{
                        curr[buy][count]=max(prices[i]+after[1][count-1], after[0][count]);
                    }
                }
            }
            after=curr;
        }
        return after[1][2];
    }
};