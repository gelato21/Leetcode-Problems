class Solution {
public:
    int solve(vector<int>& nums, int k){
         int n=nums.size();
        int odd_count=0, ans=0;
        int i=0, j=0;
        while(j<n){
            if(nums[j]%2==1){
                odd_count++;
            }
            
            while(odd_count>k && i<=j){
                if(nums[i]%2==1){
                    odd_count--;
                }
                i++;
            }
            ans+= j-i+1;
            j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
       return solve(nums, k)-solve(nums, k-1);
    }
};