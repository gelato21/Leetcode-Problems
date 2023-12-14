class Solution {
public:
    void helper(int i, vector<int> subset, vector<vector<int>>& ans, int k, int n){
        if(k>subset.size()+n-i+1){
            return;
        }
        if(subset.size()==k){
            ans.push_back(subset);
            return;
        }
        if(i>n){
            return;
        }

        //pick
        subset.push_back(i);
        helper(i+1, subset, ans, k, n);
        subset.pop_back();

        //notpick
        helper(i+1, subset, ans, k, n);

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        helper(1, {}, ans, k, n);
        return ans;
    }
};