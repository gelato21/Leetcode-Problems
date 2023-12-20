class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int mini1=prices[0];
        int mini2=1e9;
        for(int i=1;i<prices.size();i++){
            if(mini1>prices[i]){
                mini2=mini1;
                mini1=prices[i];
            }
            else mini2=min(mini2, prices[i]);
        }
        if(mini1+mini2<=money){
            return money-(mini1+mini2);
        }
        else return money;
    }
};