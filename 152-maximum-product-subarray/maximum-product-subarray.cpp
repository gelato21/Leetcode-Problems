class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //bruteforce approach => O(n^2)
        int ans = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            int product = 1;
            for(int j=i;j<n;j++){
                product = product*nums[j];
                ans = max(ans, product);
            }
        }
        return ans;
    }
};