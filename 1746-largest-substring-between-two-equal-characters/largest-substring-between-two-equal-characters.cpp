class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans=-1;
        for(int i=0;i<s.length();i++){
            for(int j=0;j<s.length();j++){
                if(s[i]==s[j]){
                    int len=j-i-1;
                    ans=max(ans, len);
                }
            }
        }
        return ans;
    }
};