class Solution {
public:
    int n, m;
    vector<pair<int, int>> direction={{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    void allZerosTraversal(int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& board){

        for(int count=0;count<4;count++){
            int dx=i+direction[count].first;
            int dy=j+direction[count].second;

            if(dx>=0 && dx<n && dy>=0 && dy<m && board[dx][dy]=='O' && visited[dx][dy]==false){
                visited[dx][dy]=true;
                allZerosTraversal(dx, dy, visited, board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && visited[i][0]==false){
                visited[i][0]=true;
                allZerosTraversal(i, 0, visited, board);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][m-1]=='O' && visited[i][m-1]==false){
                visited[i][m-1]=true;
                allZerosTraversal(i, m-1, visited, board);
            }
        }
        for(int j=1;j<m-1;j++){
            if(board[0][j]=='O' && visited[0][j]==false){
                visited[0][j]=true;
                allZerosTraversal(0, j, visited, board);
            }
        }
        for(int j=1;j<m-1;j++){
            if(board[n-1][j]=='O' && visited[n-1][j]==false){
                visited[n-1][j]=true;
                allZerosTraversal(n-1, j, visited, board);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && visited[i][j]==false){
                    board[i][j]='X';
                }
            }
        }
        
    }
};