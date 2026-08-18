//Apna COllEGE 
/*class Solution {
public:
    TreeNode* prev=NULL;
    int minDiffInBST(TreeNode* root) {
        if(root==NULL)return INT_MAX;
        int ans=INT_MAX;
        if(root->left!=NULL){
            int leftMIN=minDiffInBST(root->left);
            ans=min(ans,leftMIN);
        }
        if(prev!=NULL)ans=min(ans,root->val-prev->val);
        prev=root;
        if(root->right!=NULL){
            int rightMIN=minDiffInBST(root->right);
            ans=min(ans,rightMIN);
        }
        return ans;
    }
};*/
class Solution {
public:
    vector<int>traversal;
    void inorder(TreeNode* root){
        if(root==NULL)return;
        minDiffInBST(root->left);
        traversal.push_back(root->val);
        minDiffInBST(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        int ans=INT_MAX;
        for(int i=1;i<traversal.size();i++){  
            ans=min(ans,traversal[i]-traversal[i-1]);
        }
        return ans;
    }
};