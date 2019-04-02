private:
    vector<int> result;
    void preorder(TreeNode* root)
{
  if(root==NULL)
  {
    return ;
  }
  result.push_back(root->val);
  preorder(root->left);
  preorder(root->right);
}
public:
vector<int> preorderTraversal(TreeNode* root)
{
  preorder(root);
  return result;
}
