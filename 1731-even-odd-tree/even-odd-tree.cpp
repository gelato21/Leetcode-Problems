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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(q.empty()==false){
            int size = q.size();
            int prev = -1;
            for(int count=0; count < size ;count++){
                TreeNode* currNode = q.front();
                q.pop();
                cout<<currNode->val<<" ";

                // for even case: currNode should be odd
                if(level%2==0){
                    if(currNode->val%2==0){
                        return false;
                    }else{
                        if(prev==-1 || prev<currNode->val){
                            prev=currNode->val;
                        }else{
                            return false;
                        }
                    }
                }else{ // for odd case: currNode should be even
                    if(currNode->val%2==1){
                        return false;
                    }else{
                        if(prev==-1 || prev>currNode->val){
                            prev=currNode->val;
                        }else{
                            return false;
                        }
                    }
                }

                if(currNode->left){
                    q.push(currNode->left);
                }
                if(currNode->right){
                    q.push(currNode->right);
                }

            }
            cout<<endl;
            level++;
        }
        return true;
    }
};