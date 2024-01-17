class Solution {
public:
    // void rotatebyOne(vector<int>& ans){
    //     int temp=ans[ans.size()-1];
    //     for(int i=ans.size()-2;i>=0;i--){
    //         ans[i+1]=ans[i];
    //     }
    //     ans[0]=temp;
    // }
    void reverse(vector<int>& nums, int start, int end){
        while(start<=end){
            swap(nums[start++], nums[end--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        // for(int i=0;i<k;i++){
        //     rotatebyOne(nums);
        // }
        //1 2 3 4 7 6 5
        //4 3 2 1 7 6 5
        //5 6 7 1 2 3 4
        int n=nums.size();
        k=k%n;
        reverse(nums, n-k, n-1);
        reverse(nums, 0, n-k-1);
        reverse(nums, 0, n-1);
        // int n=nums.size();
        // k=k%n;
        // vector<int> temp1, temp2;
        // for(int i=0;i<n-k;i++){
        //     temp1.push_back(nums[i]);
        // }
        // for(int i=n-k; i<nums.size();i++){
        //     temp2.push_back(nums[i]);
        // }
        // int index=0;
        // for(int i=0;i<k;i++){
        //     nums[index++]=temp2[i];
        // }
        // for(int i=0;i<temp1.size();i++){
        //     nums[index++]=temp1[i];
        // }

    }
};