




//求第K层的，就是求它子结点的K-1层
int GetKLevel(Node *root,int k)
{
  if(root==NULL)
  {
    return 0;
  }
  if(k==1)
  {
    return 1;//k等于1说明当前结点刚好在第K层
  }
  int left = GetKLevel(root->left,k-1);
  int right = GetKLevel(root->right,k-1);
  return left+right;
}
