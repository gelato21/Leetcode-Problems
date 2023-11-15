class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
        vector<int> count(n+1, 0);
        for(int& val: arr){
            count[min(val, n)]+=1;
        }
        int curr=0;
        for(int i=1;i<=n;i++){
            curr=min(i, curr+count[i]);
        }
        return curr;
    }
};