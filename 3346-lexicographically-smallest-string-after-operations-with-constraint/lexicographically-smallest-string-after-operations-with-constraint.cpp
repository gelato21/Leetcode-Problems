class Solution {
public:
    string getSmallestString(string s, int k) {
        for(int i=0;i<s.length();i++){
            for(int j=0;j<26;j++){
                int d = min(abs(j+26-(s[i]-'a')), abs(j-(s[i]-'a')));

                if(d<=k){
                    k-=d;
                    s[i]=(char)('a'+j);
                    break;
                }
            }
        }
        return s;
    }
};