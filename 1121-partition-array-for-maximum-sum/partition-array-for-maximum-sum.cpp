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
        int n=arr.size();
        vector<int> dp(n+1, 0);

        for(int ind=n-1;ind>=0;ind--){
            int maxi=-1;
            int ans=-1;
            for(int i=ind;i<ind+k && i<n;i++){
                maxi=max(maxi, arr[i]);
                int len=maxi*(i-ind+1);
                ans=max(ans, len+dp[i+1]);
            }
            dp[ind]=ans;
        }
        return dp[0];
    }
};