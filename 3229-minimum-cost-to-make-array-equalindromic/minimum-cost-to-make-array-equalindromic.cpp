class Solution {
public:
    bool isPalindrome(int n){
        string s=to_string(n);
        string t=s;
        reverse(t.begin(), t.end());
        return s==t;
    }
    long long findcost(vector<int>& nums, int a){
        long long ans=0;
        for(auto it: nums){
            ans+=abs(it-a);
        }
        return ans;
    }
    long long minimumCost(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int r=nums[n/2];
        int a, b;
        int i=r;
        while(1){
            if(isPalindrome(i)){
                a=i;
                break;
            }
            i--;
        }
        i=r;
        while(1){
            if(isPalindrome(i)){
                b=i;
                break;
            }
            i++;
        }
        return min(findcost(nums, a), findcost(nums, b));
        
        
        
        
        
    }
};