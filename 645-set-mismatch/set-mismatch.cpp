class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> s;
        int n=nums.size();
        int sum=0;
        vector<int> ans;
        for(auto num: nums){
            if(s.find(num)!=s.end()){
                ans.push_back(num);
            }else{
                s.insert(num);
                sum+=num;
            }
        }
        int totalSum=n*(n+1)/2;
        ans.push_back(totalSum-sum);
        return ans;
    }
};