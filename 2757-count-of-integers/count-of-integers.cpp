class Solution {
public:
    long long MOD=1e9+7;

    // s="3452"
    // 9*22=198
    long long dp[25][401][2];
    long long G(string &s, int pos, int sum, int tight, int &min_sum, int &max_sum){
        if(pos==s.length()){
            if(min_sum<=sum && sum<=max_sum){
                return 1;
            }
            else return 0;
        }
        if(dp[pos][sum][tight]!=-1) return dp[pos][sum][tight];

        if(tight==1){
            long long res=0;
            for(int i=0;i<=s[pos]-'0';i++){
                if(i==(s[pos]-'0')){
                    res=(res+G(s, pos+1, sum+i, 1, min_sum, max_sum)%MOD)%MOD;
                }
                else{
                    res=(res+G(s, pos+1, sum+i, 0, min_sum, max_sum)%MOD)%MOD;
                }
            }
            return dp[pos][sum][tight]=res;
        }
        else{
            long long res=0;
            for(int i=0;i<=9;i++){
                res=(res+G(s, pos+1, sum+i, 0, min_sum, max_sum)%MOD)%MOD;
            }
            return dp[pos][sum][tight]=res;
        }
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        
        memset(dp, -1, sizeof(dp));
        long long res1=(G(num2, 0, 0, 1, min_sum, max_sum))%MOD;
        memset(dp, -1, sizeof(dp));
        long long res2=(G(num1, 0, 0, 1, min_sum, max_sum))%MOD;
        int temp=0;
        for(int i=0;i<num1.length();i++){
            temp+=(num1[i]-'0');
        }
        
        if(min_sum<=temp && temp<=max_sum){
           res2--;
        }
        return ((res1-res2)+MOD)%MOD;
        
    }
};