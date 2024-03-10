class Solution {
public:
    int mod = 1e9+7;
    long long numberOfWays(int ind, string& s, int n, vector<int>& dp){
        if(ind>=n){
            return 1;
        }
        if(s[ind] == '0'){
            return 0;
        }

        if(dp[ind]!=-1) return dp[ind];

        long long first = 0, withSecond = 0;
        

        if(s[ind]=='*'){
            first = 9*numberOfWays(ind+1, s, n, dp);
            
        }
        else first = numberOfWays(ind+1, s, n, dp);

        if(ind+1<n){

            if(s[ind]=='*' && s[ind+1]=='*'){
                withSecond = 15*numberOfWays(ind+2, s, n, dp);
            }
            else if(s[ind]=='*'){
                if(s[ind+1]>='7' && s[ind+1]<='9'){
                    withSecond = numberOfWays(ind+2, s, n, dp);
                }else{
                    withSecond = 2*numberOfWays(ind+2, s, n, dp);
                }
            }else if(s[ind+1]=='*'){
                if(s[ind]=='1'){
                    withSecond = 9*numberOfWays(ind+2, s, n, dp);
                }else if(s[ind]=='2'){
                    withSecond = 6*numberOfWays(ind+2, s, n, dp);
                }
            }
            else{
                if(s[ind]=='1'){
                    withSecond = numberOfWays(ind+2, s, n, dp);
                }
                else if(s[ind]=='2' && s[ind+1]<='6' && s[ind+1]>='0'){
                    withSecond = numberOfWays(ind+2, s, n, dp);
                }
            }
        }
        long long int ans = (first%mod + withSecond%mod)%mod;

        return dp[ind] = ans;

    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1, -1);
        return numberOfWays(0, s, n, dp)%mod;
    }
        
};