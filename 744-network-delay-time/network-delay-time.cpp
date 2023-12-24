class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for(int i=1;i<=n;i++){
            graph[i]=vector<pair<int, int>>();
        }

        for(auto &edge: times){
            graph[edge[0]].push_back({edge[1], edge[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, k});

        unordered_map<int, int> minPath;

        while(minHeap.empty()==false){
            auto [d, node]=minHeap.top();
            minHeap.pop();

            if(minPath.find(node)!=minPath.end()) continue;
            minPath[node]=d;

            for(auto &child: graph[node]){
                int weight=child.second, node2=child.first;
                if(minPath.find(node2)==minPath.end())
                minHeap.push({d+weight, node2});
            }
        }


        int ans=0;
        for(int i=1;i<=n;i++){
            if(minPath.find(i)==minPath.end()){
                return -1;
            }
            else ans=max(ans, minPath[i]);
        }
        return ans;

        
    }
};