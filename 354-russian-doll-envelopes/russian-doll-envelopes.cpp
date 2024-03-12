class Solution {
public:
    bool static myComp(const vector<int>& a, const vector<int>& b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        else return a[0]<b[0];
    }
    int maxPossibleEnv(int ind, int prevIndex, vector<vector<int>>& env, vector<vector<int>>& dp){

        if(ind>=env.size()){
            return 0;
        }

        if(dp[ind][prevIndex+1]!=-1) return dp[ind][prevIndex+1];

        int pick = 0, notPick = 0;
        if(prevIndex==-1 || (env[prevIndex][0]>env[ind][0] && env[prevIndex][1]>env[ind][1])){
            pick = 1 + maxPossibleEnv(ind+1, ind, env, dp);
        }
        notPick = maxPossibleEnv(ind+1, prevIndex, env, dp);

        return dp[ind][prevIndex+1] = max(pick, notPick);
    }
    int maxEnvelopes(vector<vector<int>>& env) {
        int n = env.size();
        sort(env.begin(), env.end(), myComp);
        
        // vector<vector<int>> dp(n+1, vector<int>(n+2, -1) );
        // return maxPossibleEnv(0, -1, env, dp);
        vector<int> ans;
        ans.push_back(env[0][1]);

        for(int i=1;i<env.size();i++){
            if(env[i][1] > ans.back()){
                ans.push_back(env[i][1]);
            }else{
                int index = lower_bound(ans.begin(), ans.end(), env[i][1])-ans.begin();
                ans[index]=env[i][1];
            }
        }
        return ans.size();
        
    }
};