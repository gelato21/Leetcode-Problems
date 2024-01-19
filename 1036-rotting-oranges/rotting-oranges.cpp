class Solution {
public:
    vector<pair<int, int>> direction={{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i, j});
                    visited[i][j]=2;
                }
            }
        }
        int ans=-1;
        while(q.empty()==false){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto [x, y]=q.front();
                q.pop();
                
                for(int j=0;j<4;j++){
                    int dx=x+direction[j].first;
                    int dy=y+direction[j].second;

                    if(dx>=0 && dy>=0 && dx<n && dy<m && grid[dx][dy]!=0 && visited[dx][dy]==0){
                        visited[dx][dy]=2;
                        q.push({dx, dy});
                    }
                }
            }
            ans++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]!=2){
                    return -1;
                } 
            }
        }
        if(ans==-1) return 0;
        return ans;
       
    }
};