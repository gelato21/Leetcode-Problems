class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        vector<int> last(n);
        last[n-1]=0;
        for(int i=n-2;i>=0;i--){
            last[i]=nums[i+1]+last[i+1];
            cout<<last[i]<<" ";
        }
        int sum=0;
        for(int i=0;i<n;i++){
            int lft=abs(sum-(i*nums[i]));

            sum+=nums[i];

            
            int rht=abs(((n-i-1)*nums[i])-last[i]);

            ans.push_back(abs(lft+rht));
        }
        return ans;
    }
};