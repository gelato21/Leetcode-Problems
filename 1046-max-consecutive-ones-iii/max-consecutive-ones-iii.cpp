class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int start=0, end=0;
        int count=0;
        int ans=0;
        while(end<n){
            if(nums[end]==0){
                count++;
                if(count<=k){
                    ans=max(ans, end-start+1);
                }
                if(count>k){
                    while(start<=end && count>k){
                        if(nums[start]==0){
                            count--;
                        }
                        start++;
                    }
                }
            }
            ans=max(ans, end-start+1);
            end++;
        }
        return ans;
    }
};