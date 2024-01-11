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
    int maxdiff;
    void findMax(TreeNode* root, TreeNode* child){
        if(child==nullptr) return;

        maxdiff=max(maxdiff, abs(root->val-child->val));

        findMax(root, child->left);
        findMax(root, child->right);
        
    }
    void solve(TreeNode* root){
        if(root==nullptr) return;

        //fix the root and explore the children
        findMax(root, root->left);
        findMax(root, root->right);

        solve(root->left);
        solve(root->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        maxdiff=-1;
        solve(root);
        return maxdiff;
    }
};