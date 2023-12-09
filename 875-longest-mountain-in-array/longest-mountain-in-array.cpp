class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        if(n<3) return 0;
        if(n==3){
            if(arr[0]<arr[1] && arr[1]>arr[2]){
                return 3;
            }
            else return 0;
        }
        vector<int> high(n, 0), low(n, 0);
        for(int i=1;i<n;i++){
            if(arr[i-1]<arr[i]){
                high[i]=high[i-1]+1;
            } 
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                low[i]=low[i+1]+1;
            }
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            if(high[i]!=0 && low[i]!=0)
            ans=max(ans, high[i]+low[i]+1);
        }
        return ans;
    }
};