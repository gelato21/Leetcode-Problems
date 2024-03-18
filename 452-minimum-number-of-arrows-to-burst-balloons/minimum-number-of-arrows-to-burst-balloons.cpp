class Solution {
public:
    bool static myComp(const vector<int>& a, const vector<int>& b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }else return a[0]<b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), myComp);
        vector<vector<int>> ans;
        //[1, 6] [2, 8]
        ans.push_back(points[0]);
        int pointer = 0;
        for(int i=1;i<n;i++){
            int end1 = ans[pointer][1];
            if(end1>=points[i][0]){
                ans[pointer][1]=min(ans[pointer][1], points[i][1]);
            }else{
                ans.push_back(points[i]);
                pointer++;
            }
        }
        return ans.size();
    }
};