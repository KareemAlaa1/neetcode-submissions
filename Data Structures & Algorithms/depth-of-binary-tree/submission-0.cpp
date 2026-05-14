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
    int maxDepth(TreeNode* root, int depth = 0) {
        if (root == nullptr)return depth;
        int depthL = maxDepth(root->left,depth+1);
        int dephtR = maxDepth(root->right,depth+1);
        return max(depthL, dephtR);
    }
};
