class Solution {
public:
    
    int threeSumClosest(vector<int>& nums, int target) {
        int ans;
        sort(nums.begin(), nums.end());
        int min_closest=1e9;
       for(int i=0;i<nums.size()-2;i++){
           int low=i+1, high=nums.size()-1;
           while(low<high){
               int curr_closest=abs(target-(nums[i]+nums[low]+nums[high]));
               if(curr_closest<min_closest){
                   min_closest=curr_closest;
                   ans=(nums[i]+nums[low]+nums[high]);
               }
               if(nums[i]+nums[low]+nums[high]<target){
                   low++;
               }
               else if(nums[i]+nums[low]+nums[high]>target){
                   high--;
               }

               else return target;
           }
       } 
       return ans;
    }
};