class Solution {
public:
    vector<string> mp={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void f(int i, string& s, string temp, vector<string>& ans){
        if(i==s.length()){
            ans.push_back(temp);
            return ;
        }

        int digit=s[i]-48;
        for(int k=0;k<mp[digit].length();k++){
            temp.push_back(mp[digit][k]);
            f(i+1, s, temp, ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()){
            return ans;
        }
        f(0, digits, "", ans);
        return ans;

    }
};