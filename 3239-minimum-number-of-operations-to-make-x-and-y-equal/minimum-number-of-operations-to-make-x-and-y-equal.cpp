class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        unordered_set<int> visited;
        queue<pair<int, int>> q;
        q.push({x, 0});
        visited.insert(x);
        while(q.empty()==false){
            auto [node, step]=q.front();
            q.pop();

            if(node==y){
                return step;
            }
            if(visited.find(node+1)==visited.end()){
                q.push({node+1, step+1});
                visited.insert(node+1);
            }
            if(visited.find(node-1)==visited.end()){
                q.push({node-1, step+1});
                visited.insert(node-1);
            }
            if(node%11==0 && visited.find(node/11)==visited.end()){
                q.push({node/11, step+1});
                visited.insert(node/11);
            }
            if(node%5==0 && visited.find(node/5)==visited.end()){
                q.push({node/5, step+1});
                visited.insert(node/5);
            }
        }
        return -1;
    }
};