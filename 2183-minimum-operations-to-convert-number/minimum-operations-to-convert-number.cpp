class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        unordered_set<int> visited;
        queue<pair<int, int>> q;
        q.push({start, 0});
        visited.insert(start);
        while(q.empty()==false){
            auto [node, step]=q.front();
            q.pop();

            if(node==goal) return step;

            for(int i=0;i<nums.size();i++){
                int num=nums[i];
                int a = node + num;
                int b = node - num;
                int c = (node ^ num);
                if(a==goal || b==goal || c==goal) return step+1;
                if(0<=a && a<=1000 && visited.find(a)==visited.end()){
                    q.push({a, step+1});
                    visited.insert(a);
                }
                if(0<=b && b<=1000 && visited.find(b)==visited.end()){
                    q.push({b, step+1});
                    visited.insert(b);
                }
                if(0<c && c<=1000 && visited.find(c)==visited.end()){
                    q.push({c, step+1});
                    visited.insert(c);
                }
            }
        }
        return -1;
    }
};