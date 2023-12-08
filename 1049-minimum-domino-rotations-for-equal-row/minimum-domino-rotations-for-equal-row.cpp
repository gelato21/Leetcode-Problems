class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        int ans=1e9;
        for(int i=1;i<=6;i++){
            int niche=0, upper=0;
            bool flag=true;
            for(int j=0;j<n;j++){
                if(tops[j]!=i && bottoms[j]!=i){
                    j=n;
                    flag=false;
                }
                if(j<n && tops[j]==i){
                    upper++;
                }
                if(j<n && bottoms[j]==i){
                    niche++;
                }
            }
            if(flag){
                ans=min(ans, min(n-upper, n-niche));
            }
        }
        return ans==1e9 ? -1 : ans;
    }
};