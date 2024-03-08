class Solution {
public:
    int f(int count, int n, int prevCopied){
        if(count>n){
            return 1e5;
        }
        if(count==n){
            return 0;
        }

        int paste = 1 + f(count+prevCopied, n, prevCopied);
        int copyAndpaste = 2 + f(count*2, n, count);

        return min(paste, copyAndpaste);

    }
    int minSteps(int n) {
        if(n==1) return 0;
        return 1 + f(1, n, 1);
    }
};