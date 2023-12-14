class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi=nums[0];
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi, nums[i]);
        }
        unordered_map<int, int> mp;
        int n=nums.size();
        long long j=0, i=0, ans=0;
        while(i<n){
            mp[nums[i]]++;
            while(mp[maxi]>=k){
                ans+=n-i;
                mp[nums[j]]--;
                j++;
            }
            i++;
        }
        return ans;
        
    }
};