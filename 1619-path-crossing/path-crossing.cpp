class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<char, pair<int, int>> moves;
        moves['N']={0, 1};
        moves['E']={1, 0};
        moves['S']={0, -1};
        moves['W']={-1, 0};

        unordered_set<string> visited;
        visited.insert("0,0");
        int x=0, y=0;

        for(char c: path){
            auto [dx, dy]=moves[c];
            x+=dx;
            y+=dy;

            string hash=to_string(x)+","+to_string(y);
            if(visited.find(hash)!=visited.end()){
                return true;
            }
            visited.insert(hash);
        }
        return false;
    }
};