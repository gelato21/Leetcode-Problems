class Solution {
public:
    int minPairSum(vector<int>& nums) {
        vector<int> temp=nums;
        sort(temp.begin(), temp.end());
        int maxi=0;
        for(int i=0;i<temp.size()/2;i++){
            maxi=max(maxi, temp[i]+temp[temp.size()-i-1]);
        }
        return maxi;
    }
};