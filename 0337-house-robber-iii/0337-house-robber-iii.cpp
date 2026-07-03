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
class pairr{
    public:
    int incl;
    int excl;
};
class Solution {
public:
    pairr sum(TreeNode* root) {
        pairr p;
        if(root==NULL){
            p.incl=p.excl=0;
            return p;
        }
        pairr left=sum(root->left);
        pairr right=sum(root->right);
        p.incl=root->val+left.excl+right.excl;
        p.excl=max(left.incl,left.excl)+max(right.incl,right.excl);
        return p;
    }
    int rob(TreeNode* root) {
        pairr p;
        p=sum(root);
        return max(p.incl,p.excl);
    }
};