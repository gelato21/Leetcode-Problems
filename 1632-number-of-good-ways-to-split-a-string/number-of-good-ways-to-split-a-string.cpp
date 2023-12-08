class Solution {
public:
    
    int numSplits(string s) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for(char c: s){
            mp2[c]++;
        }
        int ans=0;
        for(int i=0;i<s.length();i++){
            mp1[s[i]]++;
            if(mp2[s[i]]>1){
                mp2[s[i]]--;
            }
            else mp2.erase(s[i]);
            if(mp1.size()==mp2.size()) ans++;
        }
        return ans;
    }
};