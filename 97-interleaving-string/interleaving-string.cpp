class Solution {
public:
    bool isPossible(int i1, int i2, int i3, string& s1, string& s2, string& s3, vector<vector<int>>& dp){
        if(i3>=s3.length()){
            return true;
        }

        if(dp[i1][i2]!=-1) return dp[i1][i2];

        bool pick1 = false, pick2 = false;
        if(i1<s1.length() && s3[i3]==s1[i1]){
            pick1 = isPossible(i1+1, i2, i3+1, s1, s2, s3, dp);
        }
        if(i2<s2.length() && s3[i3]==s2[i2]){
            pick2 = isPossible(i1, i2+1, i3+1, s1, s2, s3, dp);
        }
        return dp[i1][i2] = (pick1 | pick2);

    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length()) return false;
        vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, -1));
        return isPossible(0, 0, 0, s1, s2, s3, dp);   
    }
};