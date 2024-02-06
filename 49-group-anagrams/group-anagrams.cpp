class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        for(int i=0;i<strs.size();i++){
            vector<int> freq(26, 0);
            for(char c: strs[i]){
                freq[c-'a']++;
            }
            mp[freq].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto [f, v]: mp){
            vector<string> temp;
            for(string s: v){
                temp.push_back(s);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};