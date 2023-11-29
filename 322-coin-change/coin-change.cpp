class Solution {
public:
    int f(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
        if(ind==0){
            if(target%arr[0]==0){
                return target/arr[0];
            }
            else return 1e9;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }

        int notTake=0 + f(ind-1, target, arr, dp);
        int take=INT_MAX;
        if(arr[ind]<=target)
        take= 1 + f(ind, target-arr[ind], arr, dp);

        return dp[ind][target]=min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        // int ans=f(coins.size()-1, amount, coins, dp);
        int ans=0;
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        for(int target=0;target<=amount;target++){
            if(target%coins[0]==0){
                dp[0][target]=target/coins[0];
            }
            else dp[0][target]=1e9;
        }

        for(int i=1;i<n;i++){
            for(int target=1;target<=amount;target++){
                int notTake=0 + dp[i-1][target];
                int take=INT_MAX;
                if(coins[i]<=target)
                take= 1 + dp[i][target-coins[i]];

                dp[i][target]=min(take, notTake);
            }
        }

        ans=dp[n-1][amount];


        if(ans>=1e9) return -1;
        else return ans;
    }
};