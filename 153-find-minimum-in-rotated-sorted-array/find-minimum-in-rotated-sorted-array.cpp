class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        int low=0, high=n-1, ans=1e9;
        while(low<=high){
            int mid = (low+high)/2;
            
            // is left part is sorted then 
            if(arr[low] <= arr[mid]){
                ans=min(ans, arr[low]);
                low=mid+1;
            }else{
                ans=min(ans, arr[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
};