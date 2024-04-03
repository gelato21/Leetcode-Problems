class Solution {
public:
    vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    bool isExist(int row, int col, int index, vector<vector<char>>& board, string& word, vector<vector<bool>>& visited){
        if(index==word.length()){
            return true;
        }
        
        visited[row][col]=true;
        bool ans = false;
        for(int i=0;i<4;i++){
            int newRow = direction[i].first + row;
            int newCol = direction[i].second + col;
            if(newRow>=0 && newCol>=0 && newRow<board.size() && newCol<board[0].size() && 
                visited[newRow][newCol]==false && board[newRow][newCol]==word[index]){
                if(index==word.length()-1){
                    return true;
                }
                ans = (ans || isExist(newRow, newCol, index+1, board, word, visited));
            }
        }
        visited[row][col]=false;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    visited.assign(n, vector<bool>(m, false));
                    if(isExist(i, j, 1, board, word, visited)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};