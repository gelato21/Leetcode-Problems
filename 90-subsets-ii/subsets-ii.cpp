class Solution {
public:
    void helper(int i, vector<int> subset, vector<int>& nums, vector<vector<int>>& ans){

        if(i==nums.size()){
            ans.push_back(subset);
            return;
        }

        //pick
        subset.push_back(nums[i]);
        helper(i+1, subset, nums, ans);
        subset.pop_back();

        while(i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
        }
        helper(i+1, subset, nums, ans);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        helper(0, {}, nums, ans);
        return ans;
    }
};