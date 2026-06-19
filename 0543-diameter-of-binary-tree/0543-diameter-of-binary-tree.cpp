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
    int hieght(TreeNode* root) {
        if (root == NULL)
            return 0;

        return 1 + max(hieght(root->left), hieght(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int D1=hieght(root->left)+hieght(root->right);
        int D2= diameterOfBinaryTree(root->left);
        int D3=diameterOfBinaryTree(root->right);
        return max(D1,max(D2,D3));

    }
};