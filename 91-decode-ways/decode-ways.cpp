class Solution {
public:
    // 1 2 3 ... 26
    int f(int i, string s, vector<int>& dp){
        if(i>=s.length()){
            return 1;
        }
        if(s[i]=='0') return 0;

        // first digit consider
        if(dp[i]!=-1){
            return dp[i];
        }
        int currVal=s[i]-48;
        int one=f(i+1, s, dp);
        int two=0;
        if(i+1<s.length()){
            int nextVal=s[i+1]-48;
            if(currVal==1){
                two=f(i+2, s, dp);
            }
            else if(currVal==2 && nextVal<=6){
                two=f(i+2, s, dp);
            }
        }
        return dp[i]=two+one;
    }
    int numDecodings(string s) {
        // vector<int> dp(s.length(), -1);
        // return f(0, s, dp);
        vector<int> dp(s.length()+1, 0);
        dp[s.length()]=1;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='0'){
                dp[i]=0;
                continue;
            }
            int currVal=s[i]-48;
            int one=dp[i+1];
            int two=0;
            if(i+1<s.length()){
                int nextVal=s[i+1]-48;
                if(currVal==1){
                    two=dp[i+2];
                }
                else if(currVal==2 && nextVal<=6){
                    two=dp[i+2];
                }
            }
            dp[i]=two+one;
        }
        return dp[0];

    }
};