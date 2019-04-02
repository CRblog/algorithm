#include<iostream>
using namespace std;
 struct Node{
    int value;
    Node *left;
    Node *right;
};

//二叉树结点中的所有value都不重复
//找结点的value是v的结点
//如果找到了，返回v所在的结点地址
//如果没找到，返回NULL
//Find返回NULL意味着没找到，返回非NULL，意味着找到了
//先确定跟结点->左子树中是否包含->右子树中是否包含
//如果根结点就是,不需要再去左右结点中查找了

//，去右子树找
//
Node * Find(Node *root,int v){
  if(root==NULL)     { 
    return NULL;
  }
  //先去根找
  if(root->value == v)  {
    return root;
  }
  //根如果没找到，去左子树找
  Node *result = Find(root->left,v);
  if(result!=NULL)   {
    //左子树找到了
    return result;
  } 
  //如果左子树没找到，去右子树找
  result = Find(root->right,v);
  if(result!=NULL)   {
    return result;
  }

}

