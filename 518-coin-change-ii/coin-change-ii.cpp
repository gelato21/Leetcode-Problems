class Solution {
public:
    int change(int amount, vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(amount+1, 0);
        dp[0]=1;

        for(int i=0;i<n;i++){
            for(int j=arr[i];j<=amount;j++){
                if(dp[j-arr[i]]>0){
                    dp[j]+=dp[j-arr[i]];
                }
            }
        }
        return dp[amount];
    }
};