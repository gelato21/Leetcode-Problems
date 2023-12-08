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
    string ans;
    void preorder(TreeNode* root){
        if(root==nullptr){
            return;
        }
        ans+=to_string(root->val);
        if(root->left){
            ans.push_back('(');
            preorder(root->left);
            ans.push_back(')');
        }
        if(root->right){
            if(root->left==nullptr) ans+="()";
            ans.push_back('(');
            preorder(root->right);
            ans.push_back(')');
        }
    }
    string tree2str(TreeNode* root) {
        preorder(root);
        return ans;
    }
};