class Solution {
public:
    bool check(int i, vector<int>& nums, int k){
        if(abs(nums[i]-nums[i+2])<=k && abs(nums[i]-nums[i+1])<=k && abs(nums[i+1]-nums[i+2])<=k){
            return true;
        }
        else return false;
    }
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans, temp;
        int m=0;
        for(int i=0;i<n/3;i++){
            if(check(m, nums, k)==false){
                return temp;
            }
            else{
                ans.push_back({nums[m], nums[m+1], nums[m+2]});
                m+=3;
            }
        }
        return ans;
        
    }
};