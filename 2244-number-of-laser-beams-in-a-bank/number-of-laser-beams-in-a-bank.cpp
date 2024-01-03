class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int m=bank[0].size();  
        int ans=0;
        int prev=-1;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<m;j++){
                if(bank[i][j]=='1'){
                    count++;
                }
            }
            if(prev!=-1){
                ans+=(prev*count);
            }
            if(count!=0)
            prev=count;
        } 
        return ans;
    }
};