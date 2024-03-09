class Solution {
public:
    int numberOfBST(int n){
        if(n==0 || n==1){
            return 1;
        }
        int res=0;
        for(int i=0;i<n;i++){
            res+=numberOfBST(i)*numberOfBST(n-i-1);
        }
        return res;
    }
    int numTrees(int n) {
        return numberOfBST(n);
    }
};