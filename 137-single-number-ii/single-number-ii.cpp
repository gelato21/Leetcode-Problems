class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int tn=-1, tn1=0, tn2=0;
        for(int i=0;i<arr.size();i++){
            int cwtn = tn & arr[i];
            int cwtn1 = tn1 & arr[i];
            int cwtn2 = tn2 & arr[i];

            tn = tn & (~cwtn);
            tn1 = tn1 | cwtn;

            tn1 = tn1 & (~cwtn1);
            tn2= tn2 | cwtn1;

            tn2 = tn2 & (~cwtn2);
            tn = tn | cwtn2;

        }
        return tn1;
    }
};