/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void convert(TreeNode* root, unordered_map<int, vector<int>>& graph){
        if(root==nullptr) return;

        if(root->left){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }

        if(root->right){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }

        convert(root->left, graph);
        convert(root->right, graph);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> graph;
        convert(root, graph);

        queue<int> q;
        q.push(start);

        unordered_set<int> visited;

        int ans=-1;
        while(q.empty()==false){
            ans++;
            int size=q.size();
            for(int i=0;i<size;i++){
                int currNode=q.front();
                q.pop();

                for(auto child: graph[currNode]){
                    if(visited.find(child)==visited.end()){
                        q.push(child);
                    }
                }
                visited.insert(currNode);
            }
        }
        return ans;
    }
};