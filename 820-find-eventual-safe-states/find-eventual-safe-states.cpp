class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int numberOfNodes=g.size();
        vector<vector<int>> graph(numberOfNodes);
        vector<int> inDegree(numberOfNodes, 0);
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[i].size();j++){
                graph[g[i][j]].push_back(i);
                inDegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numberOfNodes;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }

        vector<int>ans;
        while(q.empty()==false){
            int node=q.front();
            q.pop();
            ans.push_back(node);

            for(auto otherNodes: graph[node]){
                inDegree[otherNodes]--;
                if(inDegree[otherNodes]==0){
                    q.push(otherNodes);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};