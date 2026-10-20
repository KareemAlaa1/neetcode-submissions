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
    int dfs(TreeNode* root, int &ans){
        int leftlen=0;
        int rightlen=0;
        if(root->left!=nullptr) leftlen = 1 + dfs(root->left, ans);
        if(root->right!=nullptr) rightlen = 1 + dfs(root->right, ans);
        ans=max(ans,leftlen+rightlen);
        return max(leftlen,rightlen);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        dfs(root,ans);
        return ans;
    }
};
