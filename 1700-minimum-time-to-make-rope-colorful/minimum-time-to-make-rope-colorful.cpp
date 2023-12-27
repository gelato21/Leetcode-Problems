class Solution {
public:
    int minCost(string s, vector<int>& arr) {
        int ans=0;
        int n=s.length();
        int i=0, j=0;
        while(i<n && j<n){
            int currSum=0, currMax=0;
            while(j<n && s[i]==s[j]){
                currSum+=arr[j];
                currMax=max(currMax, arr[j]);
                j++;
            }
            if(j-i>=2){
                currSum-=currMax;
                ans+=currSum;
            }
            i=j;
        }
        return ans;
    }
};