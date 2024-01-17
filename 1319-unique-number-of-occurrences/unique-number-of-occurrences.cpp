class Solution {
public:

    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> freq(2001, 0);
        for(int it: arr){
            freq[it+1000]++;
        }
        unordered_set<int> s;
        sort(freq.rbegin(), freq.rend());
        for(int i=0;i<freq.size();i++){
            if(freq[i]==0){
                break;
            }
            if(s.find(freq[i])!=s.end()){
                return false;
            }
            else s.insert(freq[i]);
        }
        return true;
    }
};