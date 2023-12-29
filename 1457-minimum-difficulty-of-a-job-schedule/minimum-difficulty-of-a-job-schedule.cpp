class Solution {
public:
    int f(int ind, int d, vector<int>& job, vector<vector<int>>& dp){
        if(d==1){
            return *max_element(job.begin()+ind, job.end());
        }
        if(dp[ind][d]!=-1) return dp[ind][d];
        int val=-1e9;
        int ans=1e9;
        for(int i=ind; i<job.size()-d+1;i++){
            val=max(val, job[i]);
            ans=min(ans, val+f(i+1, d-1, job, dp));
        }
        return dp[ind][d]=ans;


    }
    int minDifficulty(vector<int>& job, int d) {
        int n=job.size();
        if(d>n){
            return -1;
        }
        vector<vector<int>> dp(301, vector<int>(11, -1));
        return f(0, d, job, dp);
    }
};