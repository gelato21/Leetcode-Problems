class Solution {
public:
    int getNextIndex(vector<vector<int>>& v, int start, int key){
        int end=v.size()-1;
        int ans=v.size()+1;
        while(start<=end){

            int mid=(start+end)/2;

            if(v[mid][0]>=key){
                end=mid-1;
                ans=mid;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
    int f(int ind, vector<vector<int>>& v, vector<int>& dp){

        if(ind>=v.size()) return 0;
        
        if(dp[ind]!=-1){
            return dp[ind];
        }

        //take
        int next=getNextIndex(v, ind+1, v[ind][1]);
        int take=v[ind][2]+f(next, v, dp);

        int notTake=f(ind+1, v, dp);

        return dp[ind]=max(take, notTake);
    }
    static bool cmp(vector<int> a, vector<int> b){
        return a[0]<b[0]; 
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>> v;
        for(int i=0;i<n;i++){
            v.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(v.begin(), v.end(), cmp);
        vector<int> dp(n, -1);
        return f(0, v, dp);
    }
};