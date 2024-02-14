class Solution {
public:
    int findDays(vector<int>& arr, int cap){
        int load=0, days=1;
        for(int i=0;i<arr.size();i++){
            if(load+arr[i]>cap){
                days++;
                load=arr[i];
            }else{
                load+=arr[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& arr, int d) {
        int maxi=-1e9, sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            maxi=max(maxi, arr[i]);
        }
        int low=maxi, high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            int daysReq=findDays(arr, mid);
            if(daysReq<=d){
                high=mid-1;
            }else low=mid+1;
        }
        return low;
    }
};