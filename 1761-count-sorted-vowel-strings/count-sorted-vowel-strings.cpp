class Solution {
public:
    int f(int ind, int n){
        if(n==0) return 1;
        if(ind>=5) return 0;

        //pick
        int pick=f(ind, n-1);
        //notpick
        int notpick=f(ind+1, n);

        return pick+notpick;
    }
    int countVowelStrings(int n) {
        return f(0, n);
    }
};