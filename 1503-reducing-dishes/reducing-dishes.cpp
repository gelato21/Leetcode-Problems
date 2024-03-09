class Solution {
public:
    int maxLikeTimeCoff(int ind, int time, vector<int>& sat, vector<vector<int>>& dp){
        if(ind==sat.size()){
            return 0;
        }
        if(dp[ind][time]!=-1) return dp[ind][time];

        int pick = sat[ind]*(time) + maxLikeTimeCoff(ind+1, time+1, sat, dp);
        int notPick = maxLikeTimeCoff(ind+1, time, sat, dp);

        return dp[ind][time] = max(pick, notPick);
    }
    int maxSatisfaction(vector<int>& sat) {
        int n = sat.size();
        sort(sat.begin(), sat.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return maxLikeTimeCoff(0, 1, sat, dp);
    }
};