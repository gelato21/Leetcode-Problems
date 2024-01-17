class Solution {
public:
    int binarySearch(vector<int>& numbers, int target, int start, int end){
        while(start<=end){
            int mid=(start+end)/2;
            if(numbers[mid]==target){
                return mid;
            }
            if(numbers[mid]<target){
                start=mid+1;
            }
            else end=mid-1;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int n=numbers.size();
        for(int i=0;i<numbers.size();i++){
            int ind=binarySearch(numbers, target-numbers[i], i+1, n-1);
            if(ind!=-1){
                ans.push_back(i+1);
                ans.push_back(ind+1);
                return ans;
            }
        }
        return ans;
    }
};