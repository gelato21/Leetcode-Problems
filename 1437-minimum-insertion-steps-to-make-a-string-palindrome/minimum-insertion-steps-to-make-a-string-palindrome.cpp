class Solution {
public:
    int lcs(string s1, string s2){
        int n=s1.length();
        int m=s2.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[n][m];
    }
    int minInsertions(string s) {
        int n=s.length();
        string t=s;
        reverse(t.begin(), t.end());
        return n-lcs(t, s);
    }
};