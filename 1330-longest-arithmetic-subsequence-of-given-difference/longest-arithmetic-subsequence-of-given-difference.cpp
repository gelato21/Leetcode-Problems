class Solution {
public:
    int longestArithemeticDiff(int ind, int prevIndex, vector<int>& arr, int diff, vector<vector<int>>& dp){
        if(ind>=arr.size()){
            return 0;
        }
        if(dp[ind][prevIndex+1]!=-1) return dp[ind][prevIndex+1];

        int pick = 0, notPick = 0;
        if(prevIndex==-1 || arr[ind]-arr[prevIndex] == diff){
            pick = 1 + longestArithemeticDiff(ind+1, ind, arr, diff, dp);
        }
        notPick = longestArithemeticDiff(ind+1, prevIndex, arr, diff, dp);

        return dp[ind][prevIndex+1] = max(pick, notPick);
    }
    int longestSubsequence(vector<int>& arr, int diff) {
        int n = arr.size();
        unordered_map<int, int> mp;
        int ans = 1;

        for(auto &num: arr){
            if(mp.find(num-diff)!=mp.end()){
                mp[num] = mp[num-diff] + 1; 
            }else{
                mp[num]=1;
            }
            ans = max(ans, mp[num]);
        }
        return ans;
    }
};