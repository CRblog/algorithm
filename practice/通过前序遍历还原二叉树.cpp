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
							//LeftResult.root  :�����õ��������ĸ��ڵ�
	Result LeftResult = CreateTree(
	preorder+1+LeftResult.used,
	size - 1 -LeftResult.used)
	
	root->right = rightResult.root;
							//rightResult.root   �����õ��������ĸ��ڵ�
	Result r = {root,1+LeftResult.used+rightResult.used};
	return  r;
}
