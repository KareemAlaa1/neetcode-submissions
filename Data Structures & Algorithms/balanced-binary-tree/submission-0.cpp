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
    int dfs(TreeNode* root, bool &ans){
        if(root==nullptr)return 0;
        int leftlen = dfs(root->left,ans);
        int rightlen = dfs(root->right,ans);
        if(abs(leftlen-rightlen)>1)ans=false;
        return 1 + max(leftlen,rightlen);
    }
public:
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        dfs(root,ans);
        return ans;
    }
};
