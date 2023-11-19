class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int target=nums[n-1];
        int ans=0;
        for(int i=n-2;i>=0;i--){
            if(target!=nums[i]){
                int len=n-i-1;
                ans+=len;
                target=nums[i];
            }
        }
        return ans;
    }
};