private:
  vector<int> result;
  void Inorder(TreeNode* root)
{
  if(root==NULL)
  {
    return;
  }
  Inorder(root->left);
  result.push_back(root->val);
  Inorder(root->right);
}

public:
vector<int> inorderTraversal(TreeNode* root) {
  Inorder(root->left);
  Inorder(root);
  return result;
}
