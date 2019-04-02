

//计算结点个数
//左子树结点+右子树结点+1
int size;
void Size(Node *root)
{
  if(root == NULL)
  {
    return;
  }
  size++;
  Size(root->left);
  Size(root->right);
}

int Size2(Node *root)
{
  if(root == NULL)
  {
    return 0;
  }
  int left = Size2(root->left);
  int right = Size2(root->right);
  return left + right + 1;
}
