class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        unordered_set<char> visited;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end()){
                if(mp[s[i]]!=t[i]){
                    return false;
                }
            }else if(visited.find(t[i])!=visited.end(t[i])){
                return false;
            }else{
                mp[s[i]]=t[i];
                visited.insert(t[i]);
            }
        }
        return true;
    }
};