class Solution {
public:
    int maxProfit(int ind, vector<int>& arr, vector<int>& dp){
        if(ind>=arr.size()){
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];

        int pick = arr[ind] + maxProfit(ind+2, arr, dp);
        int notPick = maxProfit(ind+1, arr, dp);

        return dp[ind] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> includeFirst(n-1), notFirst(n-1);
        for(int i=0;i<n-1;i++){
            includeFirst[i]=nums[i];
            notFirst[i]=nums[i+1];
        }
        vector<int> dp(n+1, -1);
        int ans1 = maxProfit(0, includeFirst, dp);
        fill(dp.begin(), dp.end(), -1);
        int ans2 = maxProfit(0, notFirst, dp);
        return max(ans1, ans2);
    }
};