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
    map<int,vector<TreeNode *> > mpp;
    vector<TreeNode * > solve (int n){
        if (n%2==0) return {};
        if (n==1){
            TreeNode * node = new TreeNode ;
            return {node};
        } 
        if (mpp.find(n) != mpp.end()) return mpp[n];
        vector<TreeNode *>res;
        for (int i = 1;i<n;i+=2){
             vector<TreeNode * >  left = solve (i);
             vector<TreeNode * >  right = solve (n-i-1);
             for (auto & l : left){
                for (auto & r : right){
                    TreeNode * root = new TreeNode();
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
             }
        }
        return mpp[n] =  res;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
           return solve (n);
    }
};