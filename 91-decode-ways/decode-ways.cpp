class Solution {
public:
    int numberOfWays(int ind, string s, int n, vector<int>& dp){
        if(ind>=n){
            return 1;
        }

        if(dp[ind]!=-1) return dp[ind];

        int first = 0, withSecond = 0;
        if(s[ind] == '0'){
            return 0;
        }
        first = numberOfWays(ind+1, s, n, dp);
        if(ind+1<n){
            if(s[ind]=='1'){
                withSecond = numberOfWays(ind+2, s, n, dp);
            }
            else if(s[ind]=='2' && s[ind+1]<='6' && s[ind+1]>='0'){
                withSecond = numberOfWays(ind+2, s, n, dp);
            }
        }

        return dp[ind] = first+withSecond;

    }
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n+1, -1);
        return numberOfWays(0, s, n, dp);

    }

     // we have 2 different ways to choose number
        // 1. choose first(alone) 
        // 2. chosse with next (pair) 
        //     for choosing this we have some corner case
        //     currIndexNumber == 1 or 2
        //      if(currIndexNumber === 1) second number any thig [0, 9]
        //      if(currIndexNumber === 2) second number must be [0, 6]
        // if(we get === 0 ) retur 0; not possible
};