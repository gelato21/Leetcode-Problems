class Solution {
public:
    void f(int i, int target, vector<int> subset, vector<int>& arr, vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(subset);
            return ;
        }
        if(i>=arr.size()){
            return;
        }

        //pick
        if(target>=arr[i]){
            subset.push_back(arr[i]);
            f(i, target-arr[i], subset, arr, ans);
            subset.pop_back();
        }
        //not pick
        f(i+1, target, subset, arr, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        f(0, target, {}, candidates, ans);
        return ans;
    }
};