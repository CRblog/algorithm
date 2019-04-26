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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<int> a;
        vector<vector<int>> s;
        queue<TreeNode*> q;

        int count;
        TreeNode* temp;
        if(!root)
        {
            return s;
        }
        q.push(root);
        while(q.size()){
            count = q.size();
            a.clear();   //清空里面的数据，初始化
            while(count--){
                temp = q.front();  //保存队列头部的值
                if(temp->left)   q.push(temp->left);
                //如果左子树存在，就把左子树放进来
                if(temp->right)  q.push(temp->right);
                //如果右子树存在，就把右子树放进来
                q.pop();//出队列
                a.push_back(temp->val);
            }
            s.push_back(a);
        }
        return s;
    }
};
