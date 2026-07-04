class Solution {
public:
    TreeNode* inorder(TreeNode* root){
        while(root->left){
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;

        if(root->val < key){
            root->right = deleteNode(root->right, key);
        }
        else if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        else {
            if(root->left == NULL && root->right == NULL)
                return NULL;
            if(root->left == NULL)
                return root->right;
            if(root->right == NULL)
                return root->left;
            TreeNode* New = inorder(root->right);
            root->val = New->val;
            root->right = deleteNode(root->right, New->val);
        }
        return root;
    }
};
