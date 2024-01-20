class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int mod=1e9+7;
        vector<int> next_smaller(n, 0), prev_smaller(n, 0);

        stack<int> s1, s2;
        s1.push(0);
        for(int i=1;i<n;i++){
            while(s1.empty()==false && arr[i]<arr[s1.top()]){
                s1.pop();
            }
            if(s1.empty()==true){
                prev_smaller[i]=i;
            }
            else{
                prev_smaller[i]=i-s1.top()-1;
            }
            s1.push(i);
        }

        s2.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(s2.empty()==false && arr[i]<=arr[s2.top()]){
                s2.pop();
            }
            if(s2.empty()==true){
                next_smaller[i]=n-i-1;
            }
            else{
                next_smaller[i]=s2.top()-i-1;
            }
            s2.push(i);
        }
    
        int res=0;
        for(int i=0;i<n;i++){
            long long p=((next_smaller[i]+1)*(prev_smaller[i]+1))%mod;
            p=(p*arr[i])%mod;
            res=(res+p)%mod;
        }
        return res%mod;
       
    }
};