class Solution {
public:
    int isPossible(vector<int>& arr, int bound){
        int partitions=1, sum=0;
        for(int i=0;i<arr.size();i++){
            if(sum+arr[i]<=bound){
                sum+=arr[i];
            }else{
                partitions++;
                sum=arr[i];
            }
        }
        return partitions;
    }
    int splitArray(vector<int>& arr, int k) {
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        while(low<=high){
            int mid=(low+high)/2;
            int partitions=isPossible(arr, mid);
            if(partitions > k){
                low=mid+1;
            }else high=mid-1;
        }
        return low;

        // for(int i=low;i<=high;i++){
        //     if(isPossible(arr, i)){
        //         return i;
        //     }
        // }
        // return -1;
    }
};