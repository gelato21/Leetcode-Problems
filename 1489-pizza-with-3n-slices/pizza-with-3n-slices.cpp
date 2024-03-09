class Solution {
public:
    int maxPizza(int ind, int totalPizzaForMe, vector<int>& arr, vector<vector<int>>& dp){
        if(totalPizzaForMe == 0) return 0;
        if(ind>=arr.size()){
            return 0;
        }

        if(dp[ind][totalPizzaForMe]!=-1) return dp[ind][totalPizzaForMe];

        int pick = arr[ind] + maxPizza(ind+2, totalPizzaForMe-1, arr, dp);
        int notPick = maxPizza(ind+1, totalPizzaForMe, arr, dp);

        return dp[ind][totalPizzaForMe] = max(pick, notPick);
    }
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<int> includeFirst(n-1), notFirst(n-1);
        for(int i=0;i<n-1;i++){
            includeFirst[i]=slices[i];
            notFirst[i]=slices[i+1];
        }
        vector<vector<int>> dp(n+1, vector<int>((n/3)+1, -1));
        int ans1 = maxPizza(0, n/3, includeFirst, dp);
        dp.assign(n+1, vector<int>((n/3)+1, -1));
        int ans2 = maxPizza(0, n/3, notFirst, dp);
        return max(ans1, ans2);
    }
};