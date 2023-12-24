class Solution {
public:
    vector<pair<int, int>> moves={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1) return 0;
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        int result=max(grid[0][0], grid[n-1][n-1]);
        minHeap.push({result, 0, 0});
        visited[0][0]=true;
        
        while(minHeap.empty()==false){
            vector<int> curr=minHeap.top();
            minHeap.pop();
            int r=curr[1], c=curr[2], cost=curr[0];

            result=max(cost, result);
            
            
            for(int i=0;i<4;i++){
                int newRow=r+moves[i].first;
                int newCol=c+moves[i].second;

                if(newRow<n && newCol<n && newCol>=0 && newRow>=0 && visited[newRow][newCol]==false){
                    
                    if(newRow==n-1 && newCol==n-1){
                        return result;
                    }
                    minHeap.push({grid[newRow][newCol], newRow, newCol});
                    visited[r][c]=true;
                    
                }
            }
        }
        return -1;
    }
};

