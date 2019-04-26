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
            a.clear();   //�����������ݣ���ʼ��
            while(count--){
                temp = q.front();  //�������ͷ����ֵ
                if(temp->left)   q.push(temp->left);
                //������������ڣ��Ͱ��������Ž���
                if(temp->right)  q.push(temp->right);
                //������������ڣ��Ͱ��������Ž���
                q.pop();//������
                a.push_back(temp->val);
            }
            s.push_back(a);
        }
        return s;
    }
};
