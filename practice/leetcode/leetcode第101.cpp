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
    bool isSameTree(TreeNode* l,TreeNode* r){
        if(l==NULL&&r==NULL)
            return true;
        if(l==NULL||r==NULL)
            return false;
        if(r->val==l->val)
            return isSameTree(l->right,r->left)&&isSameTree(l->left,r->right);
            //左的右和右的左，右的右和左的左相等才表示对称
        else
            return false;
    }
    bool isSymmetric(TreeNode* root) {
        return isSameTree(root,root);
    }
};
