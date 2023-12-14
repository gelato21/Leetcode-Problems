class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<pair<int, int>> row(n), col(m);
        for(int i=0;i<n;i++){
            int zeros=0;
            int ones=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    zeros++;
                }
                else ones++;
            }
            row[i]= {zeros, ones};
        }
        for(int j=0;j<m;j++){
            int zeros=0;
            int ones=0;
            for(int i=0;i<n;i++){
                if(grid[i][j]==0){
                    zeros++;
                }
                else ones++;
            }
            col[j]={zeros, ones};
        }
        
        vector<vector<int>> ans(n, vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=(row[i].second+col[j].second-row[i].first-col[j].first);
            }
        }
        return ans;
    }
        
};