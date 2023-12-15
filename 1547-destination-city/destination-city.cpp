class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> mp;
        for(vector<string> path: paths){
            string src=path[0];
            string dst=path[1];
            mp[src]++;
            if(mp.find(dst)==mp.end()){
                mp[dst]=0;
            }
            
        }
        string ans;
        for(auto it: mp){
            if(it.second==0){
                ans=it.first;
            }
        }
        return ans;
    }

};