class Solution {
public:
    int minDollorsToTravel(int ind, int maxDays, vector<int>& arr, vector<int>& costs, vector<vector<int>>& dp){
        if(ind>=arr.size()){
            return 0;
        }

        if(dp[ind][maxDays+1]!=-1) return dp[ind][maxDays+1];

        if(maxDays==-1  || maxDays<arr[ind]){
            int buyFirstPass = costs[0] + minDollorsToTravel(ind+1, arr[ind], arr, costs, dp);
            int buySecondPass  = costs[1] + minDollorsToTravel(ind+1, arr[ind]+6, arr, costs, dp);
            int buyThirdPass = costs[2] + minDollorsToTravel(ind+1, arr[ind]+29, arr, costs, dp);

            return min({buyFirstPass, buySecondPass, buyThirdPass});
        }else{
            return dp[ind][maxDays+1] = minDollorsToTravel(ind+1, maxDays, arr, costs, dp);
        }
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<int>> dp(400, vector<int>(1000, -1));
        return minDollorsToTravel(0, -1, days, costs, dp);
    }
};