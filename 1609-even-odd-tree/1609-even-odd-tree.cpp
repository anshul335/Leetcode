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
    bool isEvenOddTree(TreeNode* root) {
        int level = 0;
        queue<TreeNode *>q;
        q.push(root);
        while (!q.empty()){
            int last = -1;
            int size = q.size();
            while (size--){
                TreeNode * node = q.front();
                q.pop();
                if ((level % 2 )== (node->val %2)) return false;
                if (last == -1 ){
                    last = node->val;
                }
                else if (level %2 == 1 && last <= node->val) return false;
                else if (level %2 == 0 && last >= node->val ) return false;
                last = node->val;

                if (node ->left) q.push(node->left );
                if (node ->right) q.push(node->right );
                
            }
            level++;
        }
        return true;
    }
};