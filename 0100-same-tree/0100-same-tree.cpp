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
    bool ans = true;
    void check(TreeNode * p , TreeNode * q){
        if (p == NULL && q == NULL ) return ;
        if (p == NULL || q == NULL) {
            ans = false;
            return;
        }
        if (p->val!= q->val) {
            ans = false;
            return ;
        }
        check(p ->left , q->left);
        check(p->right, q->right);

    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        check(p,q);
        return ans ;
    }
};