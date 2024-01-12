class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_map<int, int> mp;
        int i=0, count=0;
        int ans=0;
        while(i<n){
            count+=nums[i];
            if(count==goal){
                ans++;
            }
            if(mp.find(count-goal)!=mp.end()){
                ans+=mp[count-goal];
            }
            mp[count]++;
            i++;
        }
        return ans;
    }
};