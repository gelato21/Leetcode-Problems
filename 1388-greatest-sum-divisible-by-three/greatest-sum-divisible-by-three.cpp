class Solution {
public:
    int maxPossibleSum(int ind, int currSum, vector<int>& arr, vector<vector<int>>& dp){
        if(ind>=arr.size()){
            if(currSum==0){
                return 0;
            }else return INT_MIN;
        } 

        if(dp[ind][currSum]!=-1) return dp[ind][currSum];

        int pick = arr[ind] + maxPossibleSum(ind+1, (currSum+arr[ind])%3, arr, dp);
        int notPick = maxPossibleSum(ind+1, currSum, arr, dp);

        return dp[ind][currSum] = max(pick, notPick);
    }
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(4, -1));
        return maxPossibleSum(0, 0, nums, dp);
    }
};