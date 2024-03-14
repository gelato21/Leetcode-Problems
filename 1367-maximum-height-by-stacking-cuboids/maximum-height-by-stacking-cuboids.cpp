class Solution {
public:
    // [height, length, width]
    int maxCubHeight(int ind, int prevIndex, vector<vector<int>>& cub){
        if(ind>=cub.size()){
            return 0;
        }

        int pick = 0 , notPick = 0;
        if(prevIndex == -1 || (cub[prevIndex][0]>=cub[ind][0] && cub[prevIndex][1]>=cub[ind][1] && cub[prevIndex][2]>=cub[ind][2])){
            pick = cub[ind][0] + maxCubHeight(ind+1, ind, cub);
        }
        notPick = maxCubHeight(ind+1, prevIndex, cub);

        return max(pick , notPick);
    }
    int maxHeight(vector<vector<int>>& cub) {
        int n = cub.size();
        for(int i=0;i<n;i++){
            sort(cub[i].rbegin(), cub[i].rend());
        }
        sort(cub.rbegin(), cub.rend());

        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cout<<cub[i][j]<<" ";
            }
            cout<<endl;
        }
        return maxCubHeight(0, -1, cub);

        
    }
};