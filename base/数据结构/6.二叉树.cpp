//树

ABCDFIEGH   前序
BADIFCGEH   中序
BIFDGHECA   后序

层序遍历
typedef struct Node{
	int value;
	struct Node *left;
	struct Node *right;
};


二叉树的前序遍历
leetcode 144
1.空树  return ;
2.一个结点  printf(root->value);
3.只有根+左子树
	printf(root->value);
	preorder(root->left);
4.只有根+右子树
	printf(root->value);
	preorder(root->right);

void PreorderTraversak(Node *root){
	if(root == NULL){//空树
	return;
}
	printf("%d",root->value);
	PreorderTraversal(root->left);
	PreorderTraversal(root->right);
}
//中序遍历
void Inorder(Node *root)
{
	if(root== NULL){//空树
	return;
	}
	PreorderTraversal(root->left);
	printf("%d",root->value);
	PreorderTraversal(root->right);
	
}
//结点个数
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
//叶子结点
int LeafSize(Node *root)
{   //空树：return 0;
	//一个结点：return 1;
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
//返回层数
int GetHeight(Node *root){
	//空 return 0;
	if(root == NULL){return 0;
	}
	int left = GetHeight(root->left);
	int right = GetHeight(root->right);
	
	return max(left,right)+1;
}
//第K层结点个数
int GetKLevelSize(Node *root,int k){
	int s=0;
	//空 return 0;
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
//二叉树中所有的value都不重复,找结点value是V的结点，找到了就返回结点地址
//如果没找到，返回NULL

//先确定根结点->左子树是否包含->右子树中是否包含

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






















