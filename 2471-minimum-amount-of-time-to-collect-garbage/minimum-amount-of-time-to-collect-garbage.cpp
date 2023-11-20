class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n=garbage.size();
        int ans=0, a, b, c;
        a=b=c=0;

        for(int i=0;i<n;i++){
            ans+=garbage[i].length();
        }
        for(int i=1;i<n-1;i++){
            travel[i]+=travel[i-1];
        }

        //find Last occurence of m, g, p
        for(int i=1;i<n;i++){
            if(garbage[i].find('M')!=string::npos){
                a=travel[i-1];
            }
            if(garbage[i].find('P')!=string::npos){
                b=travel[i-1];
            }
            if(garbage[i].find('G')!=string::npos){
                c=travel[i-1];
            }
        }
        ans+=a+b+c;
        return ans;
    }
};