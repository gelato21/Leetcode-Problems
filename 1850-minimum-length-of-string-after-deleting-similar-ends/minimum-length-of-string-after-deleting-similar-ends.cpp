class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        int low=0, high=n-1;
        while(low<high){
            if(s[low]==s[high]){
                char ch=s[low];
                low++, high--;
                while(low<n && s[low]==ch){
                    low++;
                }
                while(high>=0 && s[high]==ch){
                    high--;
                }
            }
            else{
                break;
            }
        }
        // cout<<low<<" "<<high<<endl;
        if(low>high) return 0;
        return high-low+1;
    }
};