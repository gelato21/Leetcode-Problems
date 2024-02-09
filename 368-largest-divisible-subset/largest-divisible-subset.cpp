class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), hash(n);
        for(int i=0;i<n;i++){
            hash[i]=i;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j]+1 > dp[i]){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
        }
        int maxLen=0, maxLenIndex=-1;
        for(int i=0;i<n;i++){
            if(maxLen<dp[i]){
                maxLen= dp[i];
                maxLenIndex = i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[maxLenIndex]);
        while(hash[maxLenIndex]!=maxLenIndex){
            maxLenIndex=hash[maxLenIndex];
            ans.push_back(nums[maxLenIndex]);
        }
        return ans;
    }
};