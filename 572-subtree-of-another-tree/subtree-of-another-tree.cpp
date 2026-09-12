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
private:
    bool checktree(TreeNode* root, TreeNode* subRoot){
        if(root == nullptr && subRoot == nullptr){
            return true;
        }else if(root == nullptr || subRoot == nullptr){
            return false;
        }
        if(root->val != subRoot->val){
            return false;
        }

        return checktree(root->left, subRoot->left) && checktree(root->right, subRoot->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr){
            return true;
        }else if(root == nullptr || subRoot == nullptr){
            return false;
        }

        if(root->val == subRoot->val){
          if(checktree(root, subRoot)){
            return true;
          }
        }
        bool leftSub = isSubtree(root->left, subRoot);
        if(!leftSub){
            return isSubtree(root->right, subRoot);
        }
        
        

        return true;
    }
};