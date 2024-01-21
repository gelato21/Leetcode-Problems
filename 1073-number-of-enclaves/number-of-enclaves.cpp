class Solution {
public:
    int n, m;
    vector<pair<int, int>> moves={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    void markVisitedForOnes(int i, int j, vector<vector<bool>>& markVisited, vector<vector<int>>& grid){

        for(int move=0;move<4;move++){
            int newRow=i+moves[move].first;
            int newCol=j+moves[move].second;

            if(newRow<n && newRow>=0 && newCol<m && newCol>=0 && grid[newRow][newCol]==1 && markVisited[newRow][newCol]==false){
                markVisited[newRow][newCol]=true;
                markVisitedForOnes(newRow, newCol, markVisited, grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int numberOfLands=0;
        n=grid.size();
        m=grid[0].size();

        vector<vector<bool>> markVisited(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && markVisited[i][0]==false){
                markVisited[i][0]=true;
                markVisitedForOnes(i, 0, markVisited, grid);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][m-1]==1 && markVisited[i][m-1]==false){
                markVisited[i][m-1]=true;
                markVisitedForOnes(i, m-1, markVisited, grid);
            }
        }
        for(int j=1;j<m-1;j++){
            if(grid[0][j]==1 && markVisited[0][j]==false){
                markVisited[0][j]=true;
                markVisitedForOnes(0, j, markVisited, grid);
            }
        }
        for(int j=1;j<m-1;j++){
            if(grid[n-1][j]==1 && markVisited[n-1][j]==false){
                markVisited[n-1][j]=true;
                markVisitedForOnes(n-1, j, markVisited, grid);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && markVisited[i][j]==false){
                    numberOfLands++;
                }
            }
        }

        return numberOfLands;
        
    }
};