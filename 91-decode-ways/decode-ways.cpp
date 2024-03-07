class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n, 0);
        if(s[0]!='0')
        dp[0]=1;
        for(int i=1;i<n;i++){
            int num = s[i]-'0';
            int prev = s[i-1]-'0';
            if(num == 0 && prev==0){
                dp[i]=0;
            }else if(num==0 && prev!=0){
                if(prev*10+num<=26){
                    if(i-2>=0){
                        dp[i]=dp[i-2];
                    }else dp[i]=1;
                }
            }
            else if(num!=0 && prev==0){
                dp[i]=dp[i-1];
            }else{
                if(prev*10+num <=26){
                    if(i-2>=0)
                    dp[i]=dp[i-1]+dp[i-2];
                    else dp[i]=dp[i-1]+1;
                }else{
                    dp[i]=dp[i-1];
                }
                
            }
        }
        return dp[n-1];

    }
};