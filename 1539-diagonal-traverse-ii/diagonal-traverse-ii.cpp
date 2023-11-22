class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        map<int, vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            int k=i;
            for(int j=0;j<nums[i].size();j++){
                mp[k].push_back(nums[i][j]);
                k++;
            }
        }
        for(auto [it, arr]: mp){
            reverse(arr.begin(), arr.end());
            for(int i=0;i<arr.size();i++){
                ans.push_back(arr[i]);
            }
        }
        return ans;

    }
};