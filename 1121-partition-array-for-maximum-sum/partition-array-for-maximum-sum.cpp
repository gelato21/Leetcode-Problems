class Solution {
public:
    int f(int start, vector<int>& arr, int k, vector<int>& dp){
        if(start>=arr.size()){
            return 0;
        }
        if(dp[start]!=-1) return dp[start];

        int maxi=-1;
        int ans=-1;
        for(int i=start;i<start+k && i<arr.size();i++){
            maxi=max(maxi, arr[i]);
            int len=maxi*(i-start+1);
            ans=max(ans, len+f(i+1, arr, k, dp));
        }
        return dp[start]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), -1);
        return f(0, arr, k, dp);
    }
};