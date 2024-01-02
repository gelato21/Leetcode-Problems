class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<vector<int>> ans;
        while(mp.size()){
            vector<int> temp, toErase;
            for(auto& [key, freq]: mp){
                temp.push_back(key);
                if(freq==1){
                    toErase.push_back(key);
                }
                else freq--;
           }
           ans.push_back(temp);
           for(auto &it: toErase){
               mp.erase(it);
           }
            
        }
        return ans;

    }
};