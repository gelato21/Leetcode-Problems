class Solution {
public:
    bool halvesAreAlike(string s) {
        int count1=0, count2=0;
        for(int i=0;i<s.length()/2;i++){
            char ch=s[i];
            if(ch=='a' || ch=='e' || ch=='i' ||
                ch=='A' || ch=='u' || ch=='o' || 
                ch=='E' || ch=='I' || ch=='O' || 
                ch=='U' ) count1++;
        }
        for(int i=s.length()/2;i<s.length();i++){
            char ch=s[i];
            if(ch=='a' || ch=='e' || ch=='i' ||
                ch=='A' || ch=='u' || ch=='o' || 
                ch=='E' || ch=='I' || ch=='O' || 
                ch=='U' ) count2++;
        }
        return count1==count2;
    }
};