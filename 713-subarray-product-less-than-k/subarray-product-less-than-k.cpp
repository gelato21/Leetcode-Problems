class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int numberOfSubarray=0;
        for(int i=0;i<nums.size();i++){
            int product = 1;
            for(int j = i;j>=0;j--){
                product=product*nums[j];
                if(product<k){
                    numberOfSubarray++;
                }else break;
            }
        }
        return numberOfSubarray;
    }
};