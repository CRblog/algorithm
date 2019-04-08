/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //�����������С���
 //������и��ӣ���С���Ҫ�Ǹ��ڵ㵽�����Ҷ�ӽڵ�ľ���
class Solution {
public:
    int min(int a,int b)
    {
        return a>b?b:a;
    }
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        return (left&&right)?1+min(left,right):1+left+right;
		//�����ֻ��һ��Ҷ�ӽ�㣬��ô�����2����1��
		//�����������ֱ��������Сֵ����ټ��ϸ��ڵ�.
    }
};
