class Solution {
public:
    void f(int i, vector<int> subset, vector<int>& arr, vector<vector<int>>& ans, int target){
        if(target==0){
            ans.push_back(subset);
            return;
        }
        if(i>=arr.size()){
            return;
        }

        //pick
        bool flag=true;
        if(arr[i]<=target){
            flag=false;
            subset.push_back(arr[i]);
            f(i+1, subset, arr, ans, target-arr[i]);
            subset.pop_back();
        }
        // notpick
        if(flag==false)
        while(i+1<arr.size() && arr[i]==arr[i+1]) i++;
        f(i+1, subset, arr, ans, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        f(0, {}, candidates, ans, target);
        return ans;
    }
};