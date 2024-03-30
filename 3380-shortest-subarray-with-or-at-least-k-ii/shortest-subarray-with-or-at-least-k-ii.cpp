class Solution {
public:
    bool isPossible(vector<int>store, int k){
        int num=0;
        for(int i=0;i<32;i++){
            if(store[i]){
                num+=pow(2, i);
            }
        }
        return num>=k;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int  n = nums.size(), start = 0, end = 0;
        int currOr = 0, ans = 1e9;
        vector<int> store(32, 0);
        while(end<n){
            int num = nums[end];

            //perform or opration
            for(int i=0;i<32 && num>0;i++){
                store[i]+=(num&1);
                num=num>>1;
            }

            while(start<=end && isPossible(store, k)){
                int num1 = nums[start];
                ans = min(ans, end-start+1);
                for(int i=0;i<32 && num1>0;i++){
                    store[i]-=(num1&1);
                    num1=num1>>1;
                }
                start++;
            }
            end++;
        }
        cout<<endl;
        if(ans==1e9){
            return -1;
        }else return ans;
    }
};