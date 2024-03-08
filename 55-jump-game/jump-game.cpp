class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, false);
        dp[n-1]=true;
        for(int i=n-2;i>=0;i--){
            for(int jump=1;jump<=nums[i] && i+jump<n; jump++){
                if(dp[i+jump]==true){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[0];
    }
};