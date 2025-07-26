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

typedef struct TreeNode tNode;

void recursive(tNode *node, int *answer, int *i){
    if (node == NULL) return;
    
    if(node->left != NULL){
        recursive(node->left, answer, i);
    }

    answer[*i] = node->val;
    (*i)++;

    if(node->right != NULL){
        recursive(node->right, answer, i);
    }
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *answer = malloc(sizeof(int) * 100);
    int *i = malloc(sizeof(int));
    *i = 0;

    recursive(root, answer, i);

    *returnSize = *i;

    return answer;
}