/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode tNode;

int treeHeight(tNode *node){
    if(!node){
        return 0;
    }

    int leftHeight = treeHeight(node->left);
    int rightHeight = treeHeight(node->right);

    if(leftHeight > rightHeight){
        return leftHeight + 1;
    }else{
        return rightHeight + 1;
    }

}

bool isBalanced(struct TreeNode* root) {

    if(!root){
        return true;
    }else{
        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);

        return (isBalanced(root->left) && isBalanced(root->right) && ( abs(leftHeight - rightHeight) <= 1));
    }
}