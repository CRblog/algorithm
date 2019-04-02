



//找递推
//已知左子树的叶子结点个数 left;
//已知右子树的叶子结点个数 right;
//整棵树的叶子结点个数 n = left+right;
//
//找终止条件
//空树、一个结点的树
int LeafSize(Node *root)
{
  if(root==NULL)
  {
    return 0;
  }
  if(root->left==NULL&&root->right==NULL)
  {
    return 1;
  }
 int left =  LeafSize(root->left);
 int right = LeafSize(root->right);
 return left+right;
}



   
