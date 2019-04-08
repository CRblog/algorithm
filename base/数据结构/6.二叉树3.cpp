������
    ���õݹ�ķ�ʽ���������������
    ǰ�����򣬺���
    �ֲ��Ե��ӽǣ�
        1.�ҵ��ƹ�ʽ
        2.����ֹ����
            1������
            2��ֻ��һ�����
    ���ö��н��������������
        ����
    ���÷ǵݹ�ķ�ʽ��ѭ��+ջ��

1.���ݴ��ս���ǰ�����й���������
typedef struct{
	Node *node;
	int used;       //����������ʹ�õ����г���
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











2.�������Ĳ������

queue<Node *> q;  �������
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

�ô��ս��Ĳ������
    �������NULL֮��ʣ������н�㶼��NULL������ȫ�����������򣬲�����ȫ��������
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
    //�Ѿ�����һ��NULL�ˣ��ж϶�����ʣ��������Ƿ��з�NULL�����
	while(!q.empty()){
		Node *front = q.front();
		q.pop();
		if(front!=NULL){
			return false;
		}
	}
	return true;
}

//����ǰ������򹹽�������

Node *buildTree(char preorder[],char inorder[],int size){
    if(size == 0){
    	return NULL;
	}

	char rootValue = preorder[0];
	int r = 0;
	for(int i=0;i<size;i++)
	{
		if(inorder[i] == rootValue){
			r=i;//�������е�root���
			break;
		}
	}
	assert(r!=-1);//������һ�����ҵ�rootValue
	
	Node *root = (Node *)malloc(sizeof(Node));
//��
	root->value = rootValue;
	//������
	root->left  =buildTree(preorder + 1,inorder,r );
	//������
	root->right = buildTree(preorder +1 +r,inorder + r+1,size-1-r);
	
	return root;
}

//���ݺ�������򹹽�������
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
				r=i;//�������е�root���
				break;
			}
		}
	assert(r!=-1);
	Node *root = (Node *)malloc(sizeof(Node));
	root->value = rootValue;
	root->left = buildTree(postorder,inorder,r);
	root->right = buildTree(preorder+r,inorder + r+1,size-1-r);
}

�ݹ��ȱ�㣺
    1.�������Ȳ�����׼
    2.ջ����10M
//�ǵݹ�ǰ��
    1.ѭ��
    2.ջ
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
//�ǵݹ��������
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

//�ǵݹ�������

void Postorder(Node *root){
	stack<Node *> s;
	Node *cur = root;
	Node *last = NULL;//��һ�α���������������ĸ����
	
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

������������:��ߵ�ֵС�ڸ����ұߵ�ֵ�ȸ���
��������

�����������˳���ÿ�����ȡ��ΪNode
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













