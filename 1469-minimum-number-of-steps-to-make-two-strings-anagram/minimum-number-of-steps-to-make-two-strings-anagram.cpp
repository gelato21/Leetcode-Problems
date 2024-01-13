class Solution {
public:
    int minSteps(string s, string t) {
        //a->1 b->2
        //a->2 b->1

        //leetcode
        //practice
        

        //a->-1, b->1
        vector<int> freq1(26, 0), freq2(26, 0);
        for(char ch: s){
            freq1[ch-'a']++;
        }
        for(char ch: t){
            freq2[ch-'a']++;
        }
        int count=0;
        for(int i=0;i<26;i++){
            if(freq1[i]==freq2[i]){
                continue;
            }
            else if(freq1[i]<freq2[i]){
                count+=(freq2[i]-freq1[i]);
            }
        }
        return count;
    }
};