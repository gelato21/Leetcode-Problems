class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector<int> temp;
        for(int i=1;i<arr.size();i++){
            if(arr[i-1]<arr[i]){
                temp.push_back(0);
            }else if(arr[i-1]>arr[i]){
                temp.push_back(1);
            }else temp.push_back(-1);
        }
        int len = 0, ans = 1;
        int i=0;
        while(i<temp.size()){
            int expected = temp[i];
            if(temp[i]==-1){
                i++;
                continue;
            }
            while(i<temp.size() && temp[i]==expected){
                len++;
                expected = !temp[i];
                i++;
            }
            ans =max(ans, len+1);
            len = 0;
        }
        return ans;
    }

};