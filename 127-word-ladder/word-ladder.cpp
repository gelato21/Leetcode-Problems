class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDictonary;
        unordered_set<string> visited;
        for(int i=0;i<wordList.size();i++){
            wordDictonary.insert(wordList[i]);
        }
        if(wordDictonary.find(endWord)==wordDictonary.end()){
            return 0;
        }
        int numberOfWords=0;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);

        while(q.empty()==false){
            int size=q.size();

            for(int i=0;i<size;i++){
                string front=q.front();
                q.pop();

                if(front==endWord){
                    return numberOfWords+1;
                }
                for(int index=0;index<front.length();index++){
                    string s=front;
                    for(char ch='a';ch<='z';ch++){
                        s[index]=ch;
                        if(wordDictonary.find(s)!=wordDictonary.end() && visited.find(s)==visited.end()){
                            visited.insert(s);
                            q.push(s);
                        }
                    }
                }
            }
            numberOfWords++;
        }
        // cout<<"pankaj"<<" "<<numberOfWords<<endl;
        return 0;
    }
};