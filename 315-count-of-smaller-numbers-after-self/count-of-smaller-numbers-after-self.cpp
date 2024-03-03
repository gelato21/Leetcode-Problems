class Solution {
public:
    void insert(vector<int>& sortedArray, int value){
        // int n = sortedArray.size();
        // if(n==0){
        //     sortedArray.push_back(value);
        // }
        auto ind = lower_bound(sortedArray.begin(), sortedArray.end(), value);
        sortedArray.insert(ind, value);
    }
    int countLesser(vector<int>& sortedArray, int target){
        int n = sortedArray.size();
        if(n==0) return 0;

        auto ind = lower_bound(sortedArray.begin(), sortedArray.end(), target);
        return ind-sortedArray.begin();

    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> sortedArray;
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            int count = countLesser(sortedArray, nums[i]);
            ans.push_back(count);
            insert(sortedArray, nums[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};