class Solution {
public:
    int mod=1e9+7;
    int numberOfSchemes(int ind, int people, int currProfit, int minProfit, int n, vector<int>& group, vector<int>& profit, vector<vector<vector<int>>>& dp){
        if(people>n){
            //do something
            return 0;
        }
        if(ind==group.size()){
            if(currProfit>=minProfit){
                return 1;
            }else return 0;
        }

        if(dp[ind][people][currProfit]!=-1) return dp[ind][people][currProfit];
        

        int pick = numberOfSchemes(ind+1, people+group[ind], min(currProfit+profit[ind], minProfit), minProfit, n, group, profit, dp);
        int notPick = numberOfSchemes(ind+1, people, currProfit, minProfit, n, group, profit, dp);

        return dp[ind][people][currProfit] = ( pick%mod + notPick%mod )%mod;
        

    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int maxSum = 0;
        for(int i=0;i<profit.size();i++){
            maxSum+=profit[i];
        }
        vector<vector<vector<int>>> dp(group.size()+1, vector<vector<int>>(107, vector<int>(minProfit+1, -1)));
        return numberOfSchemes(0, 0, 0, minProfit, n, group, profit, dp);
    }
};