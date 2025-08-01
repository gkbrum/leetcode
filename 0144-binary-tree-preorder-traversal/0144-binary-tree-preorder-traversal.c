/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */ 

int countNodes(struct TreeNode *node){
    if(!node) return 0;

    int countLeft = countNodes(node->left);
    int countRight = countNodes(node->right);

    return (countLeft + countRight + 1);
}

void preorder_r(struct TreeNode *node, int *returnArr, int *i){
    returnArr[*i] = node->val;
    (*i)++;

    if(node->left){
        preorder_r(node->left, returnArr, i);
    }

    if(node->right){
        preorder_r(node->right, returnArr, i);
    }

    return;
}


int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int x = 0;
    int *i = &x;
    *returnSize = countNodes(root);

    if (!root) return NULL;

    int *returnArr = (int *)malloc(sizeof(int) * *returnSize);

    preorder_r(root, returnArr, i);

    return returnArr;

}