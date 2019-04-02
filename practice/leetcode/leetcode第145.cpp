private:
  vector<int> result;
  void postorder(TreeNode* root)
{
  if(root==NULL)
  {
    return;
  }
  postorder(root->left);
  postorder(root->right);
  result.push_back(root->val);
}
public:
vector<int> postorderTraversal(TreeNode* root){
  postorder(root);
  return result;
}
