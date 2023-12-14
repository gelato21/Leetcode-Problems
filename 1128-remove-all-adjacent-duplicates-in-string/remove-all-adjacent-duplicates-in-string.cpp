class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.length();i++){
            bool flag=true;
            while(st.empty()==false && st.top()==s[i]){
                st.pop();
                flag=false;
            }
            if(flag){
                st.push(s[i]);
            }
        }
        string ans="";
        while(st.empty()==false){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};