class Solution {
public:
    bool check(int i, int j, vector<vector<char>>& board){
        char ch=board[i][j];
        for(int row=0;row<9;row++){
            if(i!=row && board[row][j]==ch){
                return false;
            }
        }
        for(int col=0;col<9;col++){
            if(j!=col && board[i][col]==ch){
                return false;
            }
        }
        int r1=(i/3)*3;
        int c1=(j/3)*3;
        for(int r=r1; r<r1+3; r++){
            for(int c=c1; c<c1+3; c++){
                if(r==i && c==j) continue;
                else if( board[r][c]==ch) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.' && check(i, j, board)==false){
                    return false;
                }
            }
        }
        return true;
    }
};