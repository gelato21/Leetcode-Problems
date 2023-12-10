class Solution {
public:
    int f(int i, vector<int>& nums, vector<int>& dp){
        if(i>=nums.size()){
            return 1e9;
        }
        if(i==nums.size()-1){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];

        int ans=1e9;
        for(int k=1;k<=nums[i];k++){
            ans=min(ans, 1+f(i+k, nums, dp));
        }
        return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, 0);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--){
            int ans=1e9;
            for(int k=1;k<=nums[i];k++){
                if(i+k<n)
                ans=min(ans, 1+dp[i+k]);
            }
            dp[i]=ans;
        }
        return dp[0];
    }
};