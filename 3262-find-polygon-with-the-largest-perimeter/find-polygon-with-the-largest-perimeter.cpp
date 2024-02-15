class Solution {
public:
    long long largestPerimeter(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(), arr.end());
        long long ans=-1;
        long long  sum=arr[0]+arr[1];
        for(int i=2;i<n;i++){
            if(sum>arr[i]){
                ans=max(ans, sum+arr[i]);
            }
            sum+=arr[i];
        }
        return ans;
    }
};