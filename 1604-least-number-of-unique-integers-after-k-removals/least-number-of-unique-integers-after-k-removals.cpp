class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(auto [it, freq]: mp){
            minHeap.push({freq, it});
        }
        for(int i=0;i<k;i++){
            auto [freq, it] = minHeap.top();
            minHeap.pop();
            if(freq != 1){
                minHeap.push({freq-1, it});
            }
        }
        return minHeap.size();
        
    }
};