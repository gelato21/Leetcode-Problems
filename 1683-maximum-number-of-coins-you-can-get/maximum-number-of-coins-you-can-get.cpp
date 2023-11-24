class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        // 5 4 3 2 6 7 1 8 9
        //   |     |     |
        // 4 5    6 7    8 9 

        // 1 2 2 3 7 8

        // 2 4 5
        int count=piles.size()/3;
        int i=piles.size()-2;
        int ans=0;
        while(count--){
            ans+=piles[i];
            i=i-2;
        }
        return ans;
    }
};