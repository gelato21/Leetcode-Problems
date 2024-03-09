class Solution {
public:
    int mod= 1e9+7;
    long long numberOfPossibleAtt(int ind, int remAbsent, int remLate, int n, vector<vector<vector<int>>>& dp){
        if(ind>n){
            return 1;
        }
        if(dp[ind][remAbsent][remLate]!=-1) return dp[ind][remAbsent][remLate];

        long long int present = 0, absent = 0, late = 0;

        present = numberOfPossibleAtt(ind+1, remAbsent, 2, n, dp)%mod;

        if(remAbsent){
            absent = numberOfPossibleAtt(ind+1, remAbsent-1, 2, n, dp)%mod;
        }
        if(remLate == 2 || remLate == 1){
            late = numberOfPossibleAtt(ind+1, remAbsent, remLate-1, n, dp)%mod;
        }
        long long int ans = (present + absent + late)%mod;

        return dp[ind][remAbsent][remLate] = ans;
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(4, -1)));
        return numberOfPossibleAtt(1, 1, 2, n, dp)%mod;
    }
};