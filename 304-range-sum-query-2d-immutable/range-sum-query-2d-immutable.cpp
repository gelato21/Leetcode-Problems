class NumMatrix {
public:
    vector<vector<int>> preSum;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        preSum.assign(n, vector<int>(m, 0));
        preSum[0]=matrix[0];
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                preSum[i][j] = preSum[i-1][j]+matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=0;
        if(row1==0){
            for(int j=col1;j<=col2;j++){
                ans+=preSum[row2][j];
            }
            return ans;
        }
        for(int j=col1;j<=col2;j++){
            ans+=(preSum[row2][j]-preSum[row1-1][j]);
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */