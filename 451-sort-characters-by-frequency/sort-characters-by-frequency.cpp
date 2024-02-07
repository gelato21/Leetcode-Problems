class Solution {
public:
    string frequencySort(string s) {
        string ans="";
        unordered_map<char,int> mp;
        for(auto it: s) mp[it]++;
        priority_queue<pair<int, char>> pq;
        for(auto it: mp){
            pq.push({it.second, it.first});
        }
        while(pq.empty()==false){
            for(int i=0;i<pq.top().first;i++)
                ans+=pq.top().second;
            pq.pop();
        }
        return ans;

    }
};