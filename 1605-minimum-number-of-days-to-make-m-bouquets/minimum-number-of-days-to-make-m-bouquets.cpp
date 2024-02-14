class Solution {
public:
    bool isPossible(vector<int>& arr, int day, int k, int m){
        int count=0, numberOfB=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=day){
                count++;
            }else{
                numberOfB+=(count/k);
                count=0;
            }
        }
        numberOfB+=(count/k);
        return numberOfB>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long val= (long long)m * (long long)k;
        if(val>(long long)n) return -1;
        int maxDay=-1e9, minDay=1e9;
        for(int i=0;i<n;i++){
            maxDay=max(maxDay, bloomDay[i]);
            minDay=min(minDay, bloomDay[i]);
        }
        int low=minDay, high=maxDay;
        while(low<=high){
            int mid=(low+high)/2;
            if(isPossible(bloomDay, mid, k, m)){
                high=mid-1;
            }else low=mid+1;
        }
        return low;
        // for(int i=minDay;i<=maxDay;i++){
        //     if(isPossible(bloomDay, i, k, m)){
        //         return i;
        //     }
        // }
        // return -1;
    }
};