class Solution {
public:
    int OnlyRecursion(string& text1, string& text2, int i, int j){
        if(i>=text1.length() || j>=text2.length()){
            return 0;
        }
        int ans=0;
        if(text1[i]==text2[j]){
            ans=1+OnlyRecursion(text1, text2, i+1, j+1);
        }
        else{
            ans=max(OnlyRecursion(text1, text2, i+1, j), OnlyRecursion(text1, text2, i, j+1));
        }
        return ans;
    }
    int SolveMemo(string& t1, string& t2, int i, int j, vector<vector<int>>& dp){
        if(i>=t1.length() || j>=t2.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(t1[i]==t2[j]){
            ans=1+SolveMemo(t1, t2, i+1, j+1, dp);
        }
        else{
            ans=max(SolveMemo(t1, t2, i+1, j, dp), SolveMemo(t1, t2, i, j+1, dp));
        }
        return dp[i][j]=ans;

    }
    int solveTable(string& t1, string& t2){
        int n=t1.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=t1.length()-1;i>=0;i--){
            for(int j=t2.length()-1;j>=0;j--){
                int ans=0;
                if(t1[i]==t2[j]){
                    ans=1+dp[i+1][j+1];
                }
                else{
                    ans=max(dp[i+1][j], dp[i][j+1]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }
    int longestPalindromeSubseq(string s) {
        string s2=s;
        reverse(s2.begin(), s2.end());
        // return OnlyRecursion(s, s2, 0, 0);

        // vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
        // return SolveMemo(s, s2, 0, 0, dp);

        return solveTable(s, s2);
    }
};