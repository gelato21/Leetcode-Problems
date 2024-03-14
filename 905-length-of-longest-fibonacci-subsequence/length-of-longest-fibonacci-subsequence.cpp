class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> st(arr.begin(), arr.end());

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                int x = arr[j], y = arr[i]+arr[j];
                int len = 2;
                while(st.find(y)!=st.end()){
                    int z=x+y;
                    x =y;
                    y=z;
                    ans = max(ans, ++len);
                }
            }
        }
        if(ans>=3){
            return ans;
        }
        return 0;
    }
};