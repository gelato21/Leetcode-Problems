class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int countOpen = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                countOpen++;
            }else if(s[i]==')'){
                countOpen--;
            }
            ans = max(ans, countOpen);
        }
        return ans;
    }
};