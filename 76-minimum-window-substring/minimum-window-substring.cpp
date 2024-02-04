class Solution {
public:
    bool isContain(vector<int> v, vector<int>count){
        for(int i=0;i<256;i++){
            if(v[i]==0){
                continue;
            }
            else if(v[i]>count[i]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<int> v(256, 0), count(256, 0);
        for(int i=0;i<t.length();i++){
            v[t[i]]++;
        }

        int minLen=INT_MAX;
        vector<int> ans(2, -1);
        int i=0, j=0;
        while(j<s.length()){
            count[s[j]]++;
            while(isContain(v, count)){
                if(j-i+1 < minLen){
                    ans[0]=i;
                    ans[1]=j;
                    minLen=j-i+1;
                }
                count[s[i]]--;
                i++;
            }
            j++;
        }
        if(ans[0]==-1) return "";
        string res="";
        for(int i=ans[0];i<=ans[1];i++){
            res+=s[i];
        }
        return res;
    }
};