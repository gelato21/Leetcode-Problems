class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> onceRow(n, 0), onceCol(m, 0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                onceRow[i]+=grid[i][j];
                onceCol[j]+=grid[i][j];
            }
        }
        vector<vector<int>> diff(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                diff[i][j]=(onceRow[i]+onceCol[j]-(n-onceRow[i])-(m-onceCol[j]));
            }
        }
        return diff;
    }
};