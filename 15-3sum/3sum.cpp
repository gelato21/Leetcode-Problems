class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        for(int i=0;i<=n-3;i++){
            int low=i+1, high=n-1;
            while(low<high){
                if(nums[low]+nums[high]==-nums[i]){
                    ans.insert({nums[i], nums[low], nums[high]});
                    low++, high--;
                }
                else if(nums[high]+nums[low]>-nums[i]){
                    high--;
                }
                else low++;
            }
        }
        vector<vector<int>> res;
        for(auto it: ans){
            res.push_back(it);
        }
       
        return res;
    }
};