int *p;
int size;
void _preorder(struct TreeNode *root){
  if(root == NULL)
  {
    return 0;
  }
  p[size++] = root->val;
  _preorder(root->left);
  _preorder(root->right);
}

int *preorderTraversal(struct TreeNode* root,int* returnSize){
  p = (int*) malloc(sizeof(int)*100*10000);
  size = 0;
  _preorder(root);

  *returnSize = size;
  return p;
}
