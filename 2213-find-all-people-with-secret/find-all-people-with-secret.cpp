class Solution {
public:
    bool static myComp(const vector<int>& a, const vector<int>& b){
        return a[2] < b[2];
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), myComp);

        //Group Meetings in increasing order of time
        map<int, vector<pair<int, int>>> sameTimeMeetings;
        for(auto& meeting : meetings){
            int x = meeting[0], y = meeting[1], time = meeting[2];
            sameTimeMeetings[time].push_back({x, y});
        }

        vector<bool> knowsSecret(n, false);
        knowsSecret[0] = true;
        knowsSecret[firstPerson] = true;

        for(auto& [time, meetings] : sameTimeMeetings){
            unordered_map<int, vector<int>> graph;
            for(auto& [x, y]: meetings){
                graph[x].push_back(y);
                graph[y].push_back(x);
            }

            unordered_set<int> start;
            for(auto& [x, y]: meetings){
                if(knowsSecret[x]){
                    start.insert(x);
                }
                if(knowsSecret[y]){
                    start.insert(y);
                }
            }

            //now peform bfs
            queue<int> q;
            for(auto& person: start){
                q.push(person);
            }
            while(q.empty()==false){
                int person = q.front();
                q.pop();

                for(auto& nextPerson: graph[person]){
                    if(knowsSecret[nextPerson]==false){
                        knowsSecret[nextPerson] = true;
                        q.push(nextPerson);
                    }
                }
            }

        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(knowsSecret[i]){
                ans.push_back(i);
            }
        }
        return ans;

    }
};