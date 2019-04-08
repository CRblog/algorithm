/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //求二叉树的最小深度
 //这个题有个坑，最小深度要是根节点到最近的叶子节点的距离
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
		//如果树只有一个叶子结点，那么结果是2不是1，
		//其他情况就是直接左右最小值相加再加上根节点.
    }
};
