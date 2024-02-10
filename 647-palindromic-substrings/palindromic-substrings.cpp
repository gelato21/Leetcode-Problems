class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            // for odd
            int low=i, high=i;
            while(low>=0 && high<n && s[low]==s[high]){
                ans++, low--, high++;
            }

            //for even
            low=i, high=i+1;
            while(low>=0 && high<n && s[low]==s[high]){
                ans++, low--, high++;
            }
        }
        return ans;
    }
};