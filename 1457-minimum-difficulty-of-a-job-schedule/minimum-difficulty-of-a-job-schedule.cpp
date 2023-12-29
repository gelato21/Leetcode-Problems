class Solution {
public:
    int f(int ind, int d, vector<int>& job, int maxi, vector<vector<vector<int>>>& dp){
        if(d==1){
            return *max_element(job.begin()+ind, job.end());
        }

        if(ind+d >job.size()){
            return 1e9;
        }

        if(dp[ind][d][maxi]!=-1){
            return dp[ind][d][maxi];
        }

        
        maxi=max(job[ind], maxi);
        
        int notCut=f(ind+1, d, job, maxi, dp);

        int cut=maxi+f(ind+1, d-1, job, 0, dp);

        return dp[ind][d][maxi]=min(cut, notCut);

    }
    int minDifficulty(vector<int>& job, int d) {
        int n=job.size();
        if(d>n){
            return -1;
        }
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(d+1, vector<int>(1001, -1)));
        return f(0, d, job, 0, dp);
    }
};