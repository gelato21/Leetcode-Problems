class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int temp =0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            temp=max(temp, mp[nums[i]]);
        }
        
        int ans=0;
        for(auto [key, value]: mp){
            if(value==temp){
                ans+=value;
            }
        }
        return ans;
    }
};