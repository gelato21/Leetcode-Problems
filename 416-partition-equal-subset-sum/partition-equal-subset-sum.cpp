class Solution {
public:
    // Recursion
    bool f(int i, int target, vector<int>& arr){
        if(target==0){
            return true;
        }
        if(i==0){
            return (target==arr[0]);
        }

        bool include=false;
        if(target>=arr[i]){
            include=f(i-1, target-arr[i], arr);
        }
        bool exclude=f(i-1, target, arr);

        return include || exclude;
    }

    //Recursion with Memoization
    bool Memo(int i, int target, vector<int>& arr, vector<vector<int>>& dp){
        if(target==0) return 1;
        if(i==0){
            if(target==arr[0]) return 1;
            else return 0;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        bool include=false;
        if(target>=arr[i]){
            include=Memo(i-1, target-arr[i], arr, dp);
        }
        bool exclude=Memo(i-1, target, arr, dp);

        return dp[i][target]=include || exclude;
    }
    bool canPartition(vector<int>& nums) {
        int totalSum=0;
        for(int it: nums){
            totalSum+=it;
        }
        if(totalSum%2){
            return false;
        }
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(totalSum/2+1, -1));
        return Memo(n-1, totalSum/2, nums, dp);
    }
};