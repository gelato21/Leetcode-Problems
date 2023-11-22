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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> counter;
        dfs(root, counter);

        int maxFreq=0;

        for(auto& [key, val]: counter){
            maxFreq=max(maxFreq, val);
        }

        vector<int> ans;
        for(auto& [key, val]: counter){
            if(val==maxFreq){
                ans.push_back(key);
            }
        }

        return ans;
    }
    void dfs(TreeNode* root, unordered_map<int, int>& counter){
        if(root==nullptr){
            return;
        }

        counter[root->val]++;
        dfs(root->left, counter);
        dfs(root->right, counter);
    }
};