class Solution {
public:
    int f(int ind, vector<int>& nums, int isIndexFirstTaken, vector<vector<int>>& dp){
        if(ind==nums.size()-1){
            if(isIndexFirstTaken==true){
                return 0;
            }else{
                return nums[ind];
            }
        }
        if(ind>=nums.size()){
            return 0;
        }

        if(dp[ind][isIndexFirstTaken]!=-1) return dp[ind][isIndexFirstTaken];

        int pick = nums[ind]+f(ind+2, nums, ind==0 ? true: isIndexFirstTaken, dp);
        int notPick = f(ind+1, nums, isIndexFirstTaken, dp);

        return dp[ind][isIndexFirstTaken]=max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(2, -1));
        return f(0, nums, false, dp);
    }
};