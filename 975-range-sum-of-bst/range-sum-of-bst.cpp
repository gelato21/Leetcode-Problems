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
    // void calculate(TreeNode* root, int low, int high, int& ans){
    //     if(root==nullptr) return;

    //     if(low<=root->val && root->val<=high){
    //         ans+=root->val;
    //         calculate(root->left, low, high, ans);
    //         calculate(root->right, low, high, ans);
    //     }
    //     else if(root->val<low){
    //         calculate(root->right, low, high, ans);
    //     }
    //     else calculate(root->left, low, high, ans);
    // }
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==nullptr){
            return 0;
        }

        if(low<=root->val && root->val<=high){
            return root->val+rangeSumBST(root->left, low, high)+rangeSumBST(root->right, low, high);
        }
        else if(root->val<low){
            return rangeSumBST(root->right, low, high);
        }
        else{
            return rangeSumBST(root->left, low, high);
        }
    }
};