class Solution {
public:
static bool comp(string& s1, string& s2){
    return s1.size() < s2.size();
}
bool compare(string& s1, string& s2){
    if(s1.size() != s2.size() + 1) return false;
    
    int first = 0;
    int second = 0;
    
    while(first < s1.size()){
        if(second < s2.size() && s1[first] == s2[second]){
            first ++;
            second ++;
        }
        else first ++;
    }
    if(first == s1.size() && second == s2.size()) return true;
    else return false; 
}
    // bool compare(string s1, string s2){
    //     int n=s1.size();
    //     int m=s2.size();
    //     if((m-n)!=1) return false;

    //     vector<int> freq(26, 0);

    //     for(char c: s2){// pcxbc
    //         freq[c-'a']++;
    //     }
    //     for(char c: s1){//cxbc
    //         freq[c-'a']--;
    //     }
    //     int count=0;
    //     for(int i=0;i<26;i++){
    //         // cout<<(char)(i+'a')<<" "<<freq[i]<<endl;
    //         if(freq[i]==1){
    //             count++;
    //         }
    //         else if(freq[i]!=0){
    //             return false;
    //         }
    //     }
    //     if(count==1){
    //         return true;
    //     }
    //     else return false;
    // }
    
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int> dp(n, 1);

        sort(words.begin(), words.end(), comp);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(compare(words[i], words[j])==true && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                }
            }
        }
        
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi, dp[i]);
        }
        return maxi;
    }
};