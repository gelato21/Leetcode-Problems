class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> mp;
        for(vector<string> it: paths){
            string source=it[0];
            string desti=it[1];
            // if(mp.find(source)==mp.end()){
            //     mp[]
            // }
            mp[source]++;
            if(mp.find(desti)==mp.end()){
                mp[desti]=0;
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