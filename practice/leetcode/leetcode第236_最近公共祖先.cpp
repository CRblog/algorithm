
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
            return root;       //��Ϊ�գ�����
        if(root==p||root==q)
            return root;
        TreeNode *left=lowestCommonAncestor(root->left,p,q);   //���������ҹ�������
        TreeNode *right=lowestCommonAncestor(root->right,p,q);  //���Һ������ҹ�������

        if(left!=NULL&&right!=NULL)   //������Ҷ���Ϊ�գ�˵�����Ҷ���root�ĺ��ӽڵ�
            return root;
        else if(left==NULL)  //�������Ϊ�գ������Һ���
            return right;
        else if(right==NULL)   //����Һ���Ϊ�գ���������
            return left;
        else
            return NULL;
    }
};
