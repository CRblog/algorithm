/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int TreeDeep(TreeNode* root)//�������
    {
        if(!root)
            return 0;
        return 1+max(TreeDeep(root->left),TreeDeep(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root)  //��ֵ��������������true
            return true;
        if(abs(TreeDeep(root->left) - TreeDeep(root->right))>1)    //
            return false;
        else{
         if(isBalanced(root->left) && isBalanced(root->right)){
            return true;
        } else
            return false;
        }
    }

};
