class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for(int i=0;i<n;i++){
            if(matrix[i][m-1]=='1'){
                dp[i][m-1]=1;
            }else{
                dp[i][m-1]=0;
            }
        }
        for(int j=0;j<m;j++){
            if(matrix[n-1][j]=='1'){
                dp[n-1][j]=1;
            }else{
                dp[n-1][j]=0;
            }
        }

        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                if(matrix[i][j]=='1'){
                    dp[i][j]=min(dp[i][j+1], min(dp[i+1][j], dp[i+1][j+1]))+1;
                }else{
                    dp[i][j]=0;
                }
            }
        }
        int area=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                area=max(dp[i][j]*dp[i][j], area);
            }
        }

        return area;

    }
};