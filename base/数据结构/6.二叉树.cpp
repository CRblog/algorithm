//��

ABCDFIEGH   ǰ��
BADIFCGEH   ����
BIFDGHECA   ����

�������
typedef struct Node{
	int value;
	struct Node *left;
	struct Node *right;
};


��������ǰ�����
leetcode 144
1.����  return ;
2.һ�����  printf(root->value);
3.ֻ�и�+������
	printf(root->value);
	preorder(root->left);
4.ֻ�и�+������
	printf(root->value);
	preorder(root->right);

void PreorderTraversak(Node *root){
	if(root == NULL){//����
	return;
}
	printf("%d",root->value);
	PreorderTraversal(root->left);
	PreorderTraversal(root->right);
}
//�������
void Inorder(Node *root)
{
	if(root== NULL){//����
	return;
	}
	PreorderTraversal(root->left);
	printf("%d",root->value);
	PreorderTraversal(root->right);
	
}
//������
int size;
void Size(Node *root)
{
	if(root==NULL){
		return ;
	}
	int left = Size2(root->left);
	int right = Size2(root->left);
	return left+right+1;
}
//Ҷ�ӽ��
int LeafSize(Node *root)
{   //������return 0;
	//һ����㣺return 1;
	if(root == NULL)
	{
		return 0;
	}
	if(root->left == NULL&&root->right == NULL)
	{
		return 1;
	}
	int left = LeafSize(root->left);
	int right = LeafSize(root->right);
	return left+right;
}
//���ز���
int GetHeight(Node *root){
	//�� return 0;
	if(root == NULL){return 0;
	}
	int left = GetHeight(root->left);
	int right = GetHeight(root->right);
	
	return max(left,right)+1;
}
//��K�������
int GetKLevelSize(Node *root,int k){
	int s=0;
	//�� return 0;
	if(root == NULL){
		return 0;
	}
	if(k==1)
	{
		return 1;
	}
	return GetKLevelSize(root->left,k-1)
	+GetKLevelSize(root->right,k-1);
	
}
//�����������е�value�����ظ�,�ҽ��value��V�Ľ�㣬�ҵ��˾ͷ��ؽ���ַ
//���û�ҵ�������NULL

//��ȷ�������->�������Ƿ����->���������Ƿ����

Node * Find(Node *root,int v)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->value==v)
	{
		return root;
	}
	Node *result = Find(root->left,v);
	if(Find(root->left,v)!=NULL)
	{
		return result;
	}
	result =Find(root->right,v);
	if(result!=NULL)
	{
		return result;
	}
	else
	{
		return NULL;
	}
}






















