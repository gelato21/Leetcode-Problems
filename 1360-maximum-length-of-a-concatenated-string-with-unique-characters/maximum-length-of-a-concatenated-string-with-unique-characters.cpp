class Solution {
public:
    bool notContains(string& a, string &b){
        for(int i=0;i<b.size();i++){
            if(a.find(b[i])!=string::npos){
                return false;
            }
        }
        return true;
    }
    bool isValid(string &s){
        unordered_map<char, int> mp;
        for(auto ch: s){
            mp[ch]++;
        }
        for(auto it: mp){
            if(it.second>1){
                return false;
            }
        }
        return true;
    }
    int solve(int ind, vector<string>& arr, string res){
        if(ind==arr.size()){
            return res.size();
        }

        int take=0;
        if(isValid(arr[ind])){
            if(res.size()==0 || notContains(res, arr[ind])){
                take=solve(ind+1, arr, res+arr[ind]);
            }
        }
        int notTake=solve(ind+1, arr, res);

        return max(take, notTake);
    }
    int maxLength(vector<string>& arr) {
        string res="";
        int ans=0;
        return solve(0, arr, res);
    }
};