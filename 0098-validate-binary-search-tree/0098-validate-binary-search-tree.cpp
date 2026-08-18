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
    bool isValidBST(TreeNode* root) {
        return bst(root, LLONG_MIN, LLONG_MAX);
    }
    bool bst(TreeNode* root, long long minval, long long maxval){
        if(root==NULL)return true;
        if(root->val>=maxval||root->val<=minval)return false;
        return bst(root->left,minval,root->val)&&bst(root->right,root->val,maxval);
    }
};