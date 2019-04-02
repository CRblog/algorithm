
//计算二叉树的高度
//找递推
//找终止条件
int GetHeight(Node *root)
{
  if(root==NULL)
  {
    return 0;
  }
  int left = GetHeight(root->left);
  int right = GetHeight(root->right);
  return (left>right?left:right)+1  
  //return max(left,right)+1;
}
