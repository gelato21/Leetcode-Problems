class Solution {
public:
    int longestChain(int ind, vector<vector<int>>& arr, int pickedIndex, vector<vector<int>>& dp){

        if(ind==arr.size()){
            return 0;
        }

        if(dp[ind][pickedIndex+1]!=-1) return dp[ind][pickedIndex+1];

        int pick = 0, notPick = 0;
        if( pickedIndex == -1 || arr[pickedIndex][1]<arr[ind][0]){
            pick = 1 + longestChain(ind+1, arr, ind, dp);
        }

        notPick = longestChain(ind+1, arr, pickedIndex, dp);

        return dp[ind][pickedIndex+1] = max(pick, notPick);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<vector<int>> dp(n+1, vector<int>(n+2, -1));
        return longestChain(0, pairs, -1, dp);
    }
};