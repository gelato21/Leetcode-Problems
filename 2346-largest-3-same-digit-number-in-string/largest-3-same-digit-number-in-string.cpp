class Solution {
public:
    string largestGoodInteger(string num) {
        unordered_map<char, int> mp;
        for(int i=0;i<3;i++){
            mp[num[i]]++;
        }
        int maxi=-1;
        if(mp.size()==1){
            maxi=num[0]-'0';
        }
        for(int i=3;i<num.length();i++){
            mp[num[i]]++;
            if(mp[num[i-3]]==1){
                mp.erase(num[i-3]);
            }
            else
            mp[num[i-3]]--;

            if(mp.size()==1){
                maxi=max(maxi, num[i]-'0');
            }

        }
        string ans="";
        if(maxi==-1) return ans;
        else {
            string s=to_string(maxi);
            for(int i=0;i<3;i++){
                ans+=s;
            }
            return ans;
        }

    }
};