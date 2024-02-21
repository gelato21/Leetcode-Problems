class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans=0;
        for(int bit = 30; bit>=0; bit--){
            int first = (left & (1LL <<  bit));
            int second = (right & (1LL <<  bit));
            if( first != second){
                break;
            }
            else{
                ans = ans | first;
            }
        }
        return ans;
    }
};