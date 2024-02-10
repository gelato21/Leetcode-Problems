class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int maxLen=0;
        pair<int, int> ans;
        for(int i=0;i<n;i++){
            // considering every element as middle of palindrome
            // for odd
            int low=i, high=i, length=1;
            while(low>=0 && high<n && s[low]==s[high]){
                if(maxLen < length){
                    ans={low, high};
                    maxLen = length;
                }
                low--, high++;
                length+=2;
            }

            // for even
            low=i, high=i+1, length=2;
            while(low>=0 && high<n && s[low]==s[high]){
                if(maxLen < length){
                    ans = {low, high};
                    maxLen = length;
                }
                low--, high++;
                length+=2;
            }
        }

        string pSubstring = "";
        for(int i=ans.first; i<=ans.second; i++){
            pSubstring+=s[i];
        }
        return pSubstring;
    }
};