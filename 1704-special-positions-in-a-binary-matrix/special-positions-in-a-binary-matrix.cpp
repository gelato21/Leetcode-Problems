class Solution {
public:
    bool special(int i, int j, vector<vector<int>>& mat){
        for(int ind=0;ind<mat.size();ind++){
            if(ind==i || mat[ind][j]==0){
                continue;
            }
            else return false;
        }
        for(int ind=0;ind<mat[0].size();ind++){
            if(ind==j || mat[i][ind]==0){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int cnt=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1 && special(i, j, mat)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};