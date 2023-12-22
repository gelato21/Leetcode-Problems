class Solution {
public:
    int maxScore(string s) {
        int totalOne=0;
        for(char c: s){
            if(c=='1'){
                totalOne++;
            }
        }
        int ans=0;
        int cnt=0;
        for(int i=0;i<s.length()-1;i++){
            char c=s[i];
            if(c=='0'){
                cnt++;
            }
            else{
                totalOne--;
            }
            ans=max(ans, cnt+totalOne);
        }
        return ans;

    }
};