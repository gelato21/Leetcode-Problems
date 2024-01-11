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
    // int maxdiff;
    // void findMaxDiff(TreeNode* root, TreeNode* child){
    //     if(child==nullptr) return;

    //     maxdiff=max(maxdiff, abs(root->val-child->val));

    //     findMaxDiff(root, child->left);
    //     findMaxDiff(root, child->right);
        
    // }
    // void solve(TreeNode* root){
    //     if(root==nullptr) return;

    //     //fix the root and explore the children
    //     findMaxDiff(root, root->left);
    //     findMaxDiff(root, root->right);

    //     solve(root->left);
    //     solve(root->right);
    // }

    int solve(TreeNode* root, int minVal, int maxVal){
        if(root==nullptr){
            return abs(minVal-maxVal);
        }

        minVal=min(minVal, root->val);
        maxVal=max(maxVal, root->val);

        int l=solve(root->left, minVal, maxVal);
        int r=solve(root->right, minVal, maxVal);
        return max(l, r);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==nullptr) return -1;
        
        return solve(root, root->val, root->val);
        
    }
};