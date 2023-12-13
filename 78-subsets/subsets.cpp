class Solution {
public:
    vector<vector<int>> helper(int i, vector<int>& nums){

        if(i==nums.size()){
            return {{}};
        }

        vector<vector<int>> partialAns=helper(i+1, nums);
        vector<vector<int>> ans;
        for(vector<int> x: partialAns){
            ans.push_back(x);
        }
        for(vector<int> x: partialAns){
            x.push_back(nums[i]);
            ans.push_back(x);
        }
        return ans;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        return helper(0, nums);
    }
};