class Solution {
public:
    int reverse(int n){
        int ans=0;
        while(n){
            int  digit=n%10;
            ans=ans*10+digit;
            n=n/10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        int mod=1000000007;
        // int count=0;
        // for(int i=0;i<nums.size();i++){
        //    int revi=reverse(nums[i]);
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]+reverse(nums[j])==nums[j]+revi){
        //             count++;
        //             count=count%mod;
        //         }
        //     }
        // }
        // return count;
        vector<int> arr;
        for(auto it: nums){
            arr.push_back(it-reverse(it));
        }

        unordered_map<int, int> disc;
        int ans=0;
        int MOD=1e9+7;

        for(int num: arr){
            ans=(ans+disc[num])%MOD;
            disc[num]++;
        }
        return ans;


    }
};