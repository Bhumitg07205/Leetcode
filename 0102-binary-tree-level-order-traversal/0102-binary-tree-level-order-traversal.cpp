class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if(root == nullptr)
            return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> level;

            for(int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();

                level.push_back(temp->val);

                if(temp->left)
                    q.push(temp->left);

                if(temp->right)
                    q.push(temp->right);
            }

            result.push_back(level);
        }

        return result;
    }
};