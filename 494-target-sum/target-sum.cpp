class Solution {
public:
    int f(int ind, int target, vector<int>& arr){
        if(ind==0){
            if( target+arr[0]==0 && target-arr[0]==0){
                return 2;
            }
            else if( target+arr[0]==0 || target-arr[0]==0){
                return 1;
            }
            else return 0;
        }
        int minus=f(ind-1, target-arr[ind], arr);
        int add=f(ind-1, target+arr[ind], arr);

        return minus+add;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return f(n-1, target, nums);
    }
};