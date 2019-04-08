二叉树
    利用递归的方式解决二叉树的问题
    前序，中序，后序
    局部性的视角：
        1.找递推公式
        2.找终止条件
            1）空树
            2）只有一个结点
    利用队列解决二叉树的问题
        层序
    利用非递归的方式（循环+栈）

1.根据带空结点的前序序列构建二叉树
typedef struct{
	Node *node;
	int used;       //构建过程中使用的序列长度
};

Result CreateTree(char preorder[],int size){
	Result result;
	if(size == 0){
		result.node = NULL;
		result.used = 0;
		return result
		;
	}
	if(preorder[0] =='#'){
		result.node = NULL;
		result.used = 1;
		return result;
	}
	Result leftR = CreateTree(proder + 1,size -1);
	Result rightR = CreateTree(proder + leftR.used +1,size - leftR.used -1);
	root->left =leftR.node;
	root->right =rightR.node;
	
	result.node =root ;
	result.used =1+leftR.used+rightR.used;
	return result;
}











2.二叉树的层序遍历

queue<Node *> q;  定义队列
q.push(node);       q.pop();
q.front();          q.empty();

void Levelorder(Node *root){
	queue<Node *> q;
	q.push(root);
	while(!q.empty()){
		Node *front  = q.front();
		printf("%c",front->value);
		if(front->left != NULL){
			q.push(front->left);
		}
		if(front->right != NULL){
			q.push(front->right);
		}
	}
	printf("\n");
}

用带空结点的层序遍历
    如果遇到NULL之后，剩余的所有结点都是NULL，是完全二叉树，否则，不是完全二叉树。
bool IsComplete(Node *root){
	if(root ==NULL){
		return true;
	}
	queue<Node *> q;
	q.push(root);
	while(true){
		Node *front = q.front();
		q.pop();
		if(front == NULL){
			break;
		}
		q.push(front->left);
		q.push(front->right);
	}
    //已经遇到一个NULL了，判断队列中剩余的数据是否还有非NULL的情况
	while(!q.empty()){
		Node *front = q.front();
		q.pop();
		if(front!=NULL){
			return false;
		}
	}
	return true;
}

//根据前序和中序构建二叉树

Node *buildTree(char preorder[],char inorder[],int size){
    if(size == 0){
    	return NULL;
	}

	char rootValue = preorder[0];
	int r = 0;
	for(int i=0;i<size;i++)
	{
		if(inorder[i] == rootValue){
			r=i;//找中序中的root结点
			break;
		}
	}
	assert(r!=-1);//中序中一定能找到rootValue
	
	Node *root = (Node *)malloc(sizeof(Node));
//根
	root->value = rootValue;
	//左子树
	root->left  =buildTree(preorder + 1,inorder,r );
	//右子树
	root->right = buildTree(preorder +1 +r,inorder + r+1,size-1-r);
	
	return root;
}

//根据后序和中序构建二叉树
Node *buildTree(char postorder[],char inorder[],int size)
{
	if(size == 0){
		return NULL;
	}
	char rootValue = postorder[size-1];
	int r = 0;
		for(int i=0;i<size;i++)
		{
			if(inorder[i] == rootValue){
				r=i;//找中序中的root结点
				break;
			}
		}
	assert(r!=-1);
	Node *root = (Node *)malloc(sizeof(Node));
	root->value = rootValue;
	root->left = buildTree(postorder,inorder,r);
	root->right = buildTree(preorder+r,inorder + r+1,size-1-r);
}

递归的缺点：
    1.控制力度不够精准
    2.栈容量10M
//非递归前序
    1.循环
    2.栈
void PreorderNoR(Node *root){
	stack<Node *> s;
	Node *cur = root;
	while(!s.empty()&&cur!=NULL){
		while(cur!=NULL){
			printf("%c",cur->value);
			s.push(cur);
			cur = cur->left;
		}
		Node *top = s.top();
		s.pop();
		
		cur = top->right;
	}
	printf("\n");
}
//非递归中序遍历
void InorderNoR(Node *root){
	stack<Node *>  s;
	Node *cur = root;
	
	while(!s.empty()||cur!=NULL){
		while(cur!=NULL){
			s.push(cur);
			cur = cur->left;
		}
		Node *top = s.top();
		s.pop();
		printf("%c",top->value);
		cur = top->right;
	}
	printf("\n");
}

//非递归后序遍历

void Postorder(Node *root){
	stack<Node *> s;
	Node *cur = root;
	Node *last = NULL;//上一次被完整遍历完的树的根结点
	
	while(!s.empty()||cur!=NULL){
		while(cur!=NULL)
		{
			s.push(cur);
			cur = cur->left;
		}
		Node *top = s.top();
		if(top->right == NULL){
			printf("%c",top->value);
			s.pop();
			last = top;
		}
		else if(top->right == last){
			printf("%c",top->value);
			s.pop();
			last = top;
		}
		else{
			cur = top->right;
		}
		cur = top->right;
	}
}

二叉树搜索树:左边的值小于根，右边的值比根大
中序有序

按中序遍历的顺序把每个结点取出为Node
void Foreach(Node *node){
	node->left = prev;
	if(prev != NULL){
		prev->right = value;
	}
	prev = node;
}
void Inorder(Node *root){
	if(root!=NULL){
		Inorder(root->left);
		Foreach(root);
		Inorder(root->right);
	}
}













