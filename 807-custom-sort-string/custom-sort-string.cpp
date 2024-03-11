class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        for(char ch: s){
            mp[ch]++;
        }
        string ans="";
        for(char ch: order){
            if(mp.find(ch)!=mp.end()){
                for(int i=0;i<mp[ch];i++){
                    ans+=ch;
                }
                mp[ch]=0;
            }
        }
        for(auto it: mp){
            if(it.second>0){
                for(int i=0;i<it.second;i++){
                    ans+=it.first;
                }
            }
        }
        return ans;
    }
};