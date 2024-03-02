class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1, index = n-1;
        vector<int> ans(n);
        while(low<=high){
            int a = nums[low]*nums[low];
            int b = nums[high]*nums[high];
            if(b>a){
                ans[index]=b;
                high--;
            }
            else{
                ans[index]=a;
                low++;
            }
            index--;
        }
        return ans;
        
    }
};