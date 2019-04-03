
bool preorder(struct TreeNode *r,struct TreeNode *t)
{
  if(r == NULL){
    return false;
  }
  if(isSameTree(r,t))
  {
    return true;
  }
  bool result = preorder(r->left,t);
  if(result == true){
    return true;
  }
  return  preorder(r->left,t);
}
bool isSubtree(struct TreeNode *s,struct TreeNode *t){
  return preorder(s,t);
}
