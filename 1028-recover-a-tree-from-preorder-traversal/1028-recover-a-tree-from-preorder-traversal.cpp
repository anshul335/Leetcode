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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<pair<TreeNode * , int>> st;
        int i =0;
        int rootNum = 0;
        while (i<traversal.length() && traversal[i] >='0' && traversal[i] <='9'){
            rootNum *= 10;
            rootNum +=(traversal[i] - '0');
            i++;
        }
        TreeNode * root = new TreeNode(rootNum);
        st.push({root, 0});
        for (;i<traversal.length();i++){
            int count = 0;
            while (i<traversal.length() && traversal[i] == '-'){
               count++;
                i++;
            }
            int currNum = 0;
            while (i<traversal.length() && traversal[i] >='0' && traversal[i] <='9'){
                currNum *= 10;
                currNum +=(traversal[i] - '0');
                i++;
            }
            i--;
            while (!st.empty() && count != st.top().second +1){
                st.pop();
            }
            TreeNode * currNode = st.top().first;
            if (currNode ->left == NULL){
                currNode->left = new TreeNode(currNum);
                st.push({currNode->left, count});
            }
            else {
                currNode->right = new TreeNode(currNum);
                st.push({currNode->right, count});
            }
        }
        return root;
    }
    
};