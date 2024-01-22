class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1) return -1;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({1, 0, 0}); //{dist, x, y}
        vector<vector<int>> minDistanceFromSource(n, vector<int>(n, 1e9));

        minDistanceFromSource[0][0]=1;

        while(minHeap.empty()==false){
            auto top=minHeap.top();
            int dist=top[0];
            int x=top[1];
            int y=top[2];
            minHeap.pop();

            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    int newRow=x+delrow;
                    int newCol=y+delcol;
                    if(newRow==x && newCol==y){
                        continue;
                    }

                    if(newRow<n && newCol<n && newRow>=0 && newCol>=0 && grid[newRow][newCol]==0){
                        if(minDistanceFromSource[newRow][newCol]>dist+1){
                            minDistanceFromSource[newRow][newCol]=dist+1;
                            minHeap.push({minDistanceFromSource[newRow][newCol], newRow, newCol});
                        }
                    }
                }
            }
        }
        if(minDistanceFromSource[n-1][n-1]==1e9){
            return -1;
        }
        else return minDistanceFromSource[n-1][n-1];
    }
};