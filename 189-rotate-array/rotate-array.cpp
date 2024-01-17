class Solution {
public:
    // void rotatebyOne(vector<int>& ans){
    //     int temp=ans[ans.size()-1];
    //     for(int i=ans.size()-2;i>=0;i--){
    //         ans[i+1]=ans[i];
    //     }
    //     ans[0]=temp;
    // }
    void rotate(vector<int>& nums, int k) {
        // for(int i=0;i<k;i++){
        //     rotatebyOne(nums);
        // }
        int n=nums.size();
        k=k%n;
        vector<int> temp1, temp2;
        for(int i=0;i<n-k;i++){
            temp1.push_back(nums[i]);
        }
        for(int i=n-k; i<nums.size();i++){
            temp2.push_back(nums[i]);
        }
        int index=0;
        for(int i=0;i<k;i++){
            nums[index++]=temp2[i];
        }
        for(int i=0;i<temp1.size();i++){
            nums[index++]=temp1[i];
        }

    }
};