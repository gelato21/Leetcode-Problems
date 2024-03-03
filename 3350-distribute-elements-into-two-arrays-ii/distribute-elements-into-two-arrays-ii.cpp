class Solution {
public:
    void insert(vector<int>& arr, int value){
        auto it = lower_bound(arr.begin(), arr.end(), value);
        arr.insert(it, value);
    }
    int greaterCount(vector<int>& arr, int& num){
        auto it = upper_bound(arr.begin(), arr.end(), num);
        int count = distance(it, arr.end());

        return count;
    }
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2, sa1, sa2;
        
        
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        sa1.push_back(nums[0]);
        sa2.push_back(nums[1]);
        for(int i=2;i<nums.size();i++){
            
            int num1 = greaterCount(sa1, nums[i]);
            int num2 = greaterCount(sa2, nums[i]);
            if(num1>num2){
                arr1.push_back(nums[i]);
                insert(sa1, nums[i]);
            }else if(num2> num1){
                arr2.push_back(nums[i]);
                insert(sa2, nums[i]);
            }else if(arr1.size()<=arr2.size()){
                arr1.push_back(nums[i]);
                insert(sa1, nums[i]);
            }else{
                arr2.push_back(nums[i]);
                insert(sa2, nums[i]);
            }
            
            
            // if(arr1.back()>arr2.back()){
            //     arr1.push_back(nums[i]);
            // }else arr2.push_back(nums[i]);
        }
        vector<int> ans;
        for(auto it: arr1){
            ans.push_back(it);
        }
        for(auto it: arr2){
            ans.push_back(it);
        }
        return ans;
    }
};