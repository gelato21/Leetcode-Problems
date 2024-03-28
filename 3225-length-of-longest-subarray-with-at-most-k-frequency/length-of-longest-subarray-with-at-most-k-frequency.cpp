class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        
        unordered_map<int, int> mp;
        int start = 0, end = 0;
        while(end<n){
            mp[nums[end]]++;
            while(mp[nums[end]]>k){
                mp[nums[start]]--;
                start++;
            }
            ans=max(ans, end-start+1);
            end++;
        }
        return ans;
        
        
        
    }
};