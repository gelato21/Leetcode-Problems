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
    bool isPalindrom(unordered_map<int, int>& mp){
        int n=0;
        int countOdd=0;
        for(auto num: mp){
            if(num.second%2==1){
                countOdd++;
            }
            n+=num.second;
        }
        if(n%2==1){
            if(countOdd==1){
                return true;
            }
            else return false;
        }
        else{
            if(countOdd>0){
                return false;
            }
            return true;
        }
    }
    void numOfPath(TreeNode* root, unordered_map<int, int>& freq, int& ans){
        if(root->left==nullptr && root->right==nullptr){
            freq[root->val]++;
            if(isPalindrom(freq)){
                ans++;
            }
            freq[root->val]--;
            if(freq[root->val]==0){
                freq.erase(root->val);
            }
        }

        freq[root->val]++;
        if(root->left!=nullptr)
        numOfPath(root->left, freq, ans);
        if(root->right!=nullptr)
        numOfPath(root->right, freq, ans);
        freq[root->val]--;
        if(freq[root->val]==0){
            freq.erase(root->val);
        }

    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        unordered_map<int, int> mp;
        int ans=0;
        numOfPath(root, mp, ans);
        return ans;
    }
};