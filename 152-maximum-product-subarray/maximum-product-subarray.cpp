class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //bruteforce approach => O(n^2)
        // int ans = *max_element(nums.begin(), nums.end());
        // int n = nums.size();
        // for(int i=0;i<n;i++){
        //     int product = 1;
        //     for(int j=i;j<n;j++){
        //         product = product*nums[j];
        //         ans = max(ans, product);
        //     }
        // }
        // return ans;


        // optimal apporach => O(n)
        // 1. if all element is positive then the answer will be product of entire elment
        // 2. if all even negative element are present the answer will be entire product of element
        // 3. if odd negative element then:
        //      a. then removing one negative element the answer either prefix of suffix product
        //      b. do it for every negative elemnet
        // 4. if 0 comes in array then treat the remove and think of 
        //    different arr 

        int prefix = 1, suffix = 1, n= nums.size();
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            if(prefix==0) prefix = 1;
            if(suffix==0) suffix = 1;
        
            suffix = suffix * nums[n-i-1];
            prefix = prefix * nums[i];

            ans = max(ans, max(suffix, prefix));
        
        }
        return ans;
    }
};