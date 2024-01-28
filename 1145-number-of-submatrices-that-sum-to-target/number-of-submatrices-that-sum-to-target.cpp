class Solution {
public:
    int numberOfSubTarget(vector<int> nums, int target){
        int ans=0;
        int preSum=0;
        unordered_map<int, int> mp;

        mp[0]=1;

        for(int i=0;i<nums.size();i++){
            preSum+=nums[i];
            if(mp.find(preSum-target)!=mp.end()){
                ans+=mp[preSum-target];
            }
            mp[preSum]++;
        }
        return ans;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> prevArr(m);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int k=0;k<m;k++){
                prevArr[k]=0;
            }
            for(int row=i;row<n;row++){
                for(int col=0;col<m;col++){
                    prevArr[col]+=matrix[row][col];
                }
                ans+=numberOfSubTarget(prevArr, target);
            }
        }
        return ans;
    }
};