class Solution {
public:
    pair<int,int> countZeroAndOne(string s){
        int count0=0, count1=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                count0++;
            }else count1++;
        }
        return {count0, count1};
    }
    int f(int ind, int m, int n, vector<string>& strs, vector<vector<vector<int>>>& dp){
        if(m<0 || n<0) return -1e5;
        if(ind>=strs.size()){
            if(m>=0 && n>=0){
                return 0;
            }else return -1e5;
        }

        if(dp[ind][m][n]!=-1) return dp[ind][m][n];

        auto [count0, count1] = countZeroAndOne(strs[ind]);

        int pick = 1 + f(ind+1, m-count0, n-count1, strs, dp);
        int notPick = f(ind+1, m, n, strs, dp);

        return dp[ind][m][n]=max(pick, notPick);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size()+1, vector<vector<int>>(102, vector<int>(102, -1)));
        return f(0, m, n, strs, dp);
    }
};