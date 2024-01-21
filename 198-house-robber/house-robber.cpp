class Solution {
public:
    int count(vector<int>& nums, int i, int n){
        if(i>=n){
            return 0;
        }

        int include=count(nums, i+2, n)+nums[i];
        int exclude=count(nums, i+1, n);

        return max(include, exclude);
    }

    int recursionWithMemo(vector<int>& nums, int i, vector<int>& dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=0){
            return dp[i];
        }

        int include=recursionWithMemo(nums, i+2, dp)+nums[i];
        int exclude=recursionWithMemo(nums, i+1, dp);

        return dp[i]=max(include, exclude);
    }

    int tabulation(vector<int>& nums){
        int n=nums.size();
        vector<int> dp(n+2);

        for(int i=n-1;i>=0;i--){
            int include=dp[i+2]+nums[i];
            int exclude=dp[i+1];

            dp[i]=max(include, exclude);
        }
        return dp[0];
    }

    int rob(vector<int>& nums) {
        // 1. Recursion
        // return count(nums, 0, nums.size());

        // 2. Recursion With Memoization
        // vector<int > dp(nums.size()+1);
        // return recursionWithMemo(nums, 0, dp);

        // 3. tabulation method
        return tabulation(nums);
    }
};