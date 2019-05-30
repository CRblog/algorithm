
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return root;       //都为空，返回
        if(root==p||root==q)
            return root;
        TreeNode *left=lowestCommonAncestor(root->left,p,q);   //在左孩子里找公共祖先
        TreeNode *right=lowestCommonAncestor(root->right,p,q);  //在右孩子里找公共祖先

        if(left!=NULL&&right!=NULL)   //如果左右都不为空，说明左右都在root的孩子节点
            return root;
        else if(left==NULL)  //如果左孩子为空，返回右孩子
            return right;
        else if(right==NULL)   //如果右孩子为空，返回左孩子
            return left;
        else
            return NULL;
    }
};
