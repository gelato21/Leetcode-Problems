class Solution {
public:
    void solve(string temp, int openB, int closeB, vector<string>& ans){
        if(openB==0 && closeB==0){
            ans.push_back(temp);
            return;
        }

        if(openB==closeB){
            temp.push_back('(');
            solve(temp, openB-1, closeB, ans);
            temp.pop_back();
        }
        else if(openB==0){
            temp.push_back(')');
            solve(temp, openB, closeB-1, ans);
            temp.pop_back();
        }
        else if(closeB==0){
            return;
        }
        else{
            temp.push_back(')');
            solve(temp, openB, closeB-1, ans);
            temp.pop_back();
            temp.push_back('(');
            solve(temp, openB-1, closeB, ans);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int openB=n;
        int closeB=n;
        vector<string> ans;
        string temp="";
        solve(temp, openB, closeB, ans);
        return ans;
    }
};