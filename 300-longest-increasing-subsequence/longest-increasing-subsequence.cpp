class Solution {
public:
    int f(int i, int prev, vector<int>& nums, vector<vector<int>>& dp){
        if(i==nums.size()){
            return 0;
        }

        if(dp[i][prev+1]!=-1) return dp[i][prev+1];

        int take=0, notTake;
        if(prev==-1 || nums[prev]<nums[i]){
            take=1+f(i+1, i, nums, dp);
        }
        notTake=f(i+1, prev, nums, dp);
        return dp[i][prev+1]=max(notTake, take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        // return f(0, -1, nums, dp);
        for(int prev=0;prev<=n;prev++){
            dp[n][prev]=0;
        }
        for(int i=n-1;i>=0;i--){
            for(int prev=i-1;prev>=-1;prev--){
                int take=0, notTake;
                if(prev==-1 || nums[prev]<nums[i]){
                    take=1+dp[i+1][i+1];
                }
                notTake=dp[i+1][prev+1];
                dp[i][prev+1]=max(notTake, take);
            }
        }
        return dp[0][-1+1];
















        // vector<int> temp;
        // temp.push_back(nums[0]);

        // for(int i=1;i<nums.size();i++){
        //     if(nums[i]>temp.back()){
        //         temp.push_back(nums[i]);
        //     }
        //     else{
        //         int ind=lower_bound(temp.begin(), temp.end(), nums[i])-temp.begin();
        //         temp[ind]=nums[i];
        //     }
        // }
        // return temp.size();
    }
};