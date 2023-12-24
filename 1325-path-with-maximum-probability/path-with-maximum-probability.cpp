class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<int, double>>> graph;
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        priority_queue<pair<double, int>> maxHeap;
        maxHeap.push({1.0, start});

        unordered_set<int> visited;

        while(maxHeap.empty()==false){
            double currProb=maxHeap.top().first;
            int currNode=maxHeap.top().second;
            maxHeap.pop();

            if(currNode==end){
                return currProb;
            }

            visited.insert(currNode);

            for(auto& [nextNode, nextProb]: graph[currNode]){
                if(visited.find(nextNode)==visited.end()){
                    maxHeap.push({currProb*nextProb, nextNode});
                }
            }
        }
        return 0.0;

    }
};