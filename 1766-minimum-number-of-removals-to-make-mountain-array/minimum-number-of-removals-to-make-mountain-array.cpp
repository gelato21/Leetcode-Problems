class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis1(n, 1), lis2(n, 1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    lis1[i]=max(lis1[i], lis1[j]+1);
                }
            }
        }

        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[i]>nums[j]){
                    lis2[i]= max(lis2[i], lis2[j]+1);
                }
            }
        }
        int ans = -1e9;
        for(int i=0;i<n;i++){
            if(lis1[i]>1 && lis2[i]>1){
                ans= max(ans, lis1[i]+lis2[i]-1);
            }
        }
        return (n-ans);


    }
};