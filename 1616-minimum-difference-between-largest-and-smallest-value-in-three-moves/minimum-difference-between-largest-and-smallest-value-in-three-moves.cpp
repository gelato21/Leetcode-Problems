class Solution {
public:
    int minDifference(vector<int>& nums) {
        //  2 3 4 5
        // 0 1 5 10 14
        // 0 1 
        //  0 1 1 4  6 6 6
        int n=nums.size();
        if(n<=4){
            return 0;
        }

        sort(nums.begin(), nums.end());
        int op1=nums[n-1]-nums[3];
        int op2=nums[n-2]-nums[2];
        int op3=nums[n-3]-nums[1];
        int op4=nums[n-4]-nums[0];
        return min({op1, op2, op3, op4});
    }
};