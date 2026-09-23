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
    int solve (TreeNode * root, int count){
        int ans = count ;
        if (root->left == NULL && root ->right == NULL) return ans ;
        if (root->left) ans = max(ans, solve (root->left , count +1));
        if (root->right) ans = max(ans, solve (root->right , count +1));
        return ans ;
    }
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return solve(root, 1);
    }
};