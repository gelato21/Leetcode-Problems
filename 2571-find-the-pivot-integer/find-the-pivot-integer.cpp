class Solution {
public:
    int pivotInteger(int n) {
        int totalSum=(n*(n+1))/2;
        int sum = 0;
        for(int i=1;i<=n;i++){
            //consider every element as pivot
            sum+=i;
            int half = totalSum-(sum-i);
            if(sum==half) return i;
        }
        return -1;
    }
};