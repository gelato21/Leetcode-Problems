class Solution {
public:
    int maxProduct(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp){
        if(i>=nums1.size() || j>=nums2.size()){
            return -1e9;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        int pick = -1e9, skipFirst=-1e9, skipSecond=-1e9;
        pick = nums1[i]*nums2[j]+max(maxProduct(i+1, j+1, nums1, nums2, dp), 0);
        skipFirst = maxProduct(i+1, j, nums1, nums2, dp);
        skipSecond = maxProduct(i, j+1, nums1, nums2, dp);

        return dp[i][j] = max({pick, skipFirst, skipSecond});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(502, vector<int>(502, -1));
        return maxProduct(0, 0, nums1, nums2, dp);
    }
};