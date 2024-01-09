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
    void post(TreeNode* root, vector<int>& ans){
        if(root==nullptr) return;
        if(root->left==nullptr && root->right==nullptr){
            ans.push_back(root->val);
            return;
        }

        post(root->left, ans);
        post(root->right, ans);

    }
    bool comp(vector<int> v, vector<int> arr){
        if(v.size()!=arr.size()) return false;
        for(int i=0;i<v.size();i++){
            if(v[i]!=arr[i]) return false;
        }
        return true;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1, ans2;
        post(root1, ans1);
        post(root2, ans2);

        if(comp(ans1, ans2)){
            return true;
        }
        return false;
    }
};