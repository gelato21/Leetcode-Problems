class Solution {
public:
    string longestPrefix(string s) {
        int n=s.length();
        vector<int> lps(n, 0);
        int i=0, j=1;
        while(j<n){
            if(s[i]==s[j]){
                lps[j]=i+1;
                i++, j++;
            }else{
                if(i==0){
                    lps[j]=0;
                    j++;
                }else{
                    i=lps[i-1];
                }
            }
        }
        if(lps[n-1]==0) return "";
        string ans="";
        for(int i=0;i<lps[n-1];i++){
            ans+=s[i];
        }
        return ans;
    }
};