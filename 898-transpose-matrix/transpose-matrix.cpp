class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        int m=matrix[0].size();
        int n=matrix.size();
        vector<vector<int>> temp(m);
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                temp[j].push_back(matrix[i][j]);
            }
        }
        return temp;
    }
};