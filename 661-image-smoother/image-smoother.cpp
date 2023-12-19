class Solution {
public:
    vector<pair<int, int>> direction={{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size();
        int m=img[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                int sum=img[i][j], len=1;
                for(int k=0;k<direction.size();k++){
                    int newRow=direction[k].first+i;
                    int newCol=direction[k].second+j;

                    if(newRow<n && newCol<m && newRow>=0 && newCol>=0){
                        sum+=img[newRow][newCol];
                        len++;
                    }
                }
                ans[i][j]=sum/len;
            }
        }
        return ans;
    }
};