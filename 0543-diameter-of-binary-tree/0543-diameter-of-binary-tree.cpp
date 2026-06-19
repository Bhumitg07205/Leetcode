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
// class Solution {
// public:
//     int hieght(TreeNode* root) {
//         if (root == NULL)
//             return 0;

//         return 1 + max(hieght(root->left), hieght(root->right));
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         if(root==NULL)return 0;
//         int D1=hieght(root->left)+hieght(root->right);
//         int D2= diameterOfBinaryTree(root->left);
//         int D3=diameterOfBinaryTree(root->right);
//         return max(D1,max(D2,D3));

//     }
// };
class Solution {
public:
    struct HDPair {
        int height;
        int diameter;
    };

    HDPair optDiameter(TreeNode* root) {
        HDPair p;

        if (root == NULL) {
            p.height = 0;
            p.diameter = 0;
            return p;
        }

        HDPair Left = optDiameter(root->left);
        HDPair Right = optDiameter(root->right);

        p.height = max(Left.height, Right.height) + 1;

        int D1 = Left.height + Right.height;
        int D2 = Left.diameter;
        int D3 = Right.diameter;

        p.diameter = max(D1, max(D2, D3));

        return p;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return optDiameter(root).diameter;
    }
};