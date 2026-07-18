class Solution {
public:
    vector<int> ans;

    void printAtLevelK(TreeNode* root, int k) {
        if (root == NULL || k < 0) return;

        if (k == 0) {
            ans.push_back(root->val);
            return;
        }

        printAtLevelK(root->left, k - 1);
        printAtLevelK(root->right, k - 1);
    }

    int solve(TreeNode* root, TreeNode* target, int k) {
        if (root == NULL) return -1;

        if (root == target) {
            printAtLevelK(root, k);
            return 0;
        }

        int DL = solve(root->left, target, k);

        if (DL != -1) {
            if (DL + 1 == k)
                ans.push_back(root->val);
            else
                printAtLevelK(root->right, k - DL - 2);

            return DL + 1;
        }

        int DR = solve(root->right, target, k);

        if (DR != -1) {
            if (DR + 1 == k)
                ans.push_back(root->val);
            else
                printAtLevelK(root->left, k - DR - 2);

            return DR + 1;
        }

        return -1;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        solve(root, target, k);
        return ans;
    }
};