class Solution {
public:
    // int binarySearch(vector<int>& numbers, int target, int start, int end){
    //     while(start<=end){
    //         int mid=(start+end)/2;
    //         if(numbers[mid]==target){
    //             return mid;
    //         }
    //         if(numbers[mid]<target){
    //             start=mid+1;
    //         }
    //         else end=mid-1;
    //     }
    //     return -1;
    // }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n=nums.size();
        int left=0, right=n-1;
        while(left<right){
            int sum=nums[left]+nums[right];
            if(sum==target){
                ans.push_back(left+1);
                ans.push_back(right+1);
                return ans;
            }
            if(sum>target){
                right--;
            }
            else{
                left++;
            }
        }
        return ans;
    }
};