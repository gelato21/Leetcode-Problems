class Solution {
public:
    void threeSum(vector<int>& nums, long long ind, long long target, vector<vector<int>>& ans){
        int n=nums.size();
        for(int i=ind;i<n-2;i++){
            if(i==ind || nums[i]!=nums[i-1]){
                long long low=i+1, high=n-1, sum=target-nums[i];
                while(low<high){
                    if(nums[low]+nums[high]==sum){
                        ans.push_back({nums[ind-1], nums[i], nums[low], nums[high]});
                        while(low<high && nums[low]==nums[low+1]){
                            low++;
                        }
                        while(low<high && nums[high]==nums[high-1]){
                            high--;
                        } 
                        low++, high--;
                    }
                    else if(nums[low]+nums[high]<sum){
                        low++;
                    }
                    else high--;
                }
            }
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++){
            if(i==0 || nums[i]!=nums[i-1]){
                threeSum(nums, i+1, target-nums[i], ans);
            }
        }
        return ans;
    }
};