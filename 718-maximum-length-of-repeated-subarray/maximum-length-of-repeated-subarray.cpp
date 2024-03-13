class Solution {
public:
    // int maxLenOf(int i1, int i2, vector<int>& nums1, vector<int>& nums2, int len, vector<vector<int>>& dp){
    //     if(i1>=nums1.size() || i2>=nums2.size()){
    //         return len;
    //     }

    //     if(dp[i1][i2]!=-1) return dp[i1][i2];

    //     int skipFirst = 0, skipSecond= 0;
    //     if(nums1[i1]==nums2[i2]){
    //         len = maxLenOf(i1+1, i2+1, nums1, nums2, len+1, dp); 
    //     }
    //     skipFirst = maxLenOf(i1+1, i2, nums1, nums2, 0, dp);
    //     skipSecond = maxLenOf(i1, i2+1, nums1, nums2, 0, dp);

    //     return  dp[i1][i2] = max({len, skipFirst, skipSecond});
    // }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        // vector<vector<int>> dp(n+1, vector<int>(m, -1));
        // return maxLenOf(0, 0, nums1, nums2, 0, dp);

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
};