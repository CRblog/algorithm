Result CreateTree(char preorder[],int size)
{
	if(size==0)
	{
		Result r = {NULL,0};
		return r;
	}
	int rootvalue = preorder[0];
	if(preorder[0]=='#')
	{
		Result r = {NULL,1};
		return r;
	}
	Node *root = (Node *)malloc(sizeof(Node));
	root->value =rootvalue;
	
	Result LeftResult = CreateTree(preorder+1,size-1);
	
	root->left = LeftResult.root;//
							//LeftResult.root  :创建好的左子树的根节点
	Result LeftResult = CreateTree(
	preorder+1+LeftResult.used,
	size - 1 -LeftResult.used)
	
	root->right = rightResult.root;
							//rightResult.root   创建好的右子树的根节点
	Result r = {root,1+LeftResult.used+rightResult.used};
	return  r;
}
