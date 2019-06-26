#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <fstream>
using namespace std;
#define MAXSIZE 9
 /*���庽���������ֵ*/

typedef struct ads{
     char Enternum[7];
	 char name[100];
     char sex[2];
     int  age;
     char key[10];
}ad;

typedef struct cms{
    char EnterNum[8];    //�����˺�
    char name[100];      //����
    char sex[2];         //�Ա�
    int age;             //����
    char key[10];        //��������
}com;

typedef struct numbers{
    int comnum;//�û�����
	int adnum;  //����Ա������
}number;

typedef struct IDNode
{
	char ID[18];
	struct IDNode *next;
}IDList;

typedef struct wat_ros
{ 
	char name[10];/*����*/
	char ID[18];/*���֤��*/
	int req_amt;/*��Ʊ��*/
	struct wat_ros *next;
}qnode,*qptr;

typedef struct pqueue
{
	qptr front;/*�Ⱥ��油�ͻ��������ͷָ��*/
	qptr rear;/*�Ⱥ��油�ͻ����������ָ��*/
}linkqueue;

typedef struct ord_ros
{  
	char name[10];/*�ͻ�����*/
	char ID[18];/*���֤��*/
	int ord_amt;/*��Ʊ��*/
	int grade;/*��λ�ȼ�*/
	struct ord_ros *next;
}linklist;

struct airline
{
	char ter_name[10];/*�յ�վ�� */
    char air_num[10];/*�����*/
    char plane_num[10];/*�ɻ���*/
    char date[7];/*�������ڣ����ڼ���*/
    int tkt_amt;/*��Ա����*/
    int tkt_sur;/*��Ʊ��*/
    linklist *order;
	/*��Ա������ָ���Ա���������ͷָ��*/
    linkqueue wait;
	/*�Ⱥ��油�Ŀͻ������򣬷ֱ�ָ���ŶӵȺ�������ͷ��β��ָ��*/
}lineinfo;

struct airline *start;
struct airline air[MAXSIZE];

void insert()
{    
	char NG;
	fstream file;
	file.open("airline.txt",ios::trunc);
    int i=0;
do{
	cout<<"�����뺽��"<<i+1<<"��Ϣ(��"<<MAXSIZE<<"��)"<<endl;
		cout<<"�������յ�վ���֣�"<<endl;
		cin>>(air+i)->ter_name;
		cout<<"�����뺽��ţ�"<<endl;
		cin>>(air+i)->air_num;
	    cout<<"������ɻ��ţ�"<<endl;
		cin>>(air+i)->plane_num;
		cout<<"������������ڣ�"<<endl;
        cin>>(air+i)->date;
		cout<<"�������Ա���"<<endl;
		cin>>(air+i)->tkt_amt;
		cout<<"��������Ʊ����"<<endl;
		cin>>(air+i)->tkt_sur;
			//�ļ�����
		//д��!
		file<<(air+i)->ter_name<<"    "<<(air+i)->air_num<<"    "<<(air+i)->plane_num<<"    "<<(air+i)->date
			<<"    "<<(air+i)->tkt_amt<<"    "<<(air+i)->tkt_sur<<endl;
		/*cin>>(air+i)->ter_name>>(air+i)->air_num>>(air+i)->plane_num>>(air+i)->date>>(air+i)->tkt_amt>>(air+i)->tkt_sur;*/
		printf("����Ҫ���������(Y,y/N,n)\n");
		cin>>NG;
}while((NG=='Y'||NG=='y')&&(i++<=MAXSIZE));	
}



void display(struct airline *info)
/*��ӡÿ�����ߵĻ�����Ϣ*/
{
 printf("�� %-6.6s �� %-6.6s ��  %-6.6s��  %-6.6s  ��   %-6.0d ��   %-6.0d ��\n",info->ter_name,info->air_num,info->plane_num,info->date,info->tkt_amt,info->tkt_sur);
}
void list()
/*��ӡȫ��������Ϣ*/
{ 
	struct airline *info;
	int i=0;
	info=air;
	cout<<"�����������Щ��������Щ��������Щ����������Щ����������Щ�����������"<<endl;
    cout<<"���յ�վ���� ����� ���ɻ���  ����������  �� ��Ա���� ��  ��Ʊ��  ��"<<endl;
    cout<<"�����������੤�������੤�������੤���������੤���������੤����������"<<endl;
	while(i<MAXSIZE)
	{
		display(info);
		if(i!=MAXSIZE-1)
		printf("�����������੤�������੤�������੤���������੤���������੤����������\n");
		info++;
		i++;
	}
	cout<<"�����������ة��������ة��������ة����������ة����������ة�����������\n";
	printf("\n\n");
}



void search()
/*���ݿͻ�������յ�վ�����������Ϣ*/
{
	struct airline *info,*find();
	char name[10];
	int i=0;
	info=start;
	cout<<"�������յ�վ��:"<<endl;
	cin>>name;
	while(i<MAXSIZE) 
	{
		if(!strcmp(name,info->ter_name)) break;
		info++;
		i++;
	}
	if(i>=MAXSIZE)
		cout<<"�Բ��𣬸ú���δ�ҵ�!"<<endl;
	else
	{
		cout<<"�յ�վ��"<<" "<<"�����"<<" "<<"�ɻ���"<<" "<<"��������"<<" "<<"��Ա����"<<" "<<"��Ʊ��"<<endl;
		display(info);
	}
}
struct airline *find()
/*����ϵͳ����ĺ���Ų�ѯ����ָ����ʽ����*/
{ struct airline *info;
   char number[10];
   int i=0;
   info=start;
   cout<<"�����뺽���:"<<endl;
  cin>>number;
   while(i<MAXSIZE) 
   {
     if(!strcmp(number,info->air_num)) return info;
     info++;
     i++;
   }
   cout<<"�Բ��𣬸ú���δ�ҵ�!"<<endl;
   return NULL;
}
void prtlink()
/*��ӡ��Ʊ��Ա������Ŀͻ�������Ϣ*/
{
	linklist *p;
	struct airline *info;
	info=find();
	p=info->order;
	if(p!=NULL)
	{
		cout<<"�ͻ�����     ���֤��           ��Ʊ����   ��λ�ȼ�"<<endl;
		while(p)
		{
			cout<<p->name<<" "<<p->ID<<" "<<p->ord_amt<<" "<<p->grade<<endl;
			p=p->next;
		}
	}
	else
	{
		cout<<"�ú���û�пͻ���Ϣ!"<<endl;
	}
}
linklist *insertlink(linklist *head,int amount,char name[],char ID[],int grade)
/*���Ӷ�Ʊ��Ա������Ŀͻ���Ϣ*/
{ 
	linklist *p1,*new1;
	p1=head;
	new1=(linklist *)malloc(sizeof(linklist));
	if(!new1)
	{
		cout<<"Out of memory!!"<<endl;
		return NULL;
	}
	strcpy(new1->name,name);
	strcpy(new1->ID,ID);
	new1->ord_amt=amount;
	new1->grade=grade;
	new1->next=NULL;
	if(head==NULL)
		/*��ԭ�޶�Ʊ�ͻ���Ϣ*/
	{
		head=new1;
		new1->next=NULL;
	}
	else
	{
		head=new1;
		new1->next=p1;
	}
	return head;
}
linkqueue appendqueue(linkqueue q,char name[],int amount)
/*�����ŶӵȺ�Ŀͻ�������*/
{ 
	qptr new1;
	new1=(qptr)malloc(sizeof(qnode));
	strcpy(new1->name,name);
	new1->req_amt=amount;
	new1->next=NULL;
	if(q.front==NULL)
/*��ԭ�ŶӵȺ�ͻ�������Ϊ��*/
	{
		q.front=new1;
	}
	else
	{
		q.rear->next=new1;
	}
	q.rear=new1;
	return q;
}

void order()
/*����Ʊҵ��*/
{
    struct airline *info;
	IDList * L,*temp1,*temp2;
	int amount,grade,i;
	char name[10];
	char ID[18];
	info=start;
	if(!(info=find()))
	{
		return;
	}
/*���ݿͻ��ṩ�ĺ���Ž��в�ѯ����Ϊ�գ��˳���ģ��*/
	cout<<"�������㶩Ʊ����Ҫ������:"<<endl;
	scanf("%d",&amount);
	if(amount>info->tkt_sur)/*���ͻ���Ʊ�����Ա��Ʊ�ܶҪ���û�ѡ��*/
	{ 
		cout<<"�Բ����������Ʊ�������Ѿ�������Ʊ����!"<<endl;
		cout<<"���� 1 ��Ԥ������"<<info->tkt_sur<<"��ʣ���Ʊ ������ 2 ���أ�"<<endl;
		char a;
		cin>>a;
          L=(IDList *)malloc(sizeof(IDList));
          L->next=NULL;
          temp1=L;
     for(i=0;i<info->tkt_sur;i++)
		{
			if(a=='1')
			{
				int i;
				cout<<"������������������Ʊ�ͻ���:"<<endl;
				cin>>name;
				cout<<"�������������֤����:"<<endl;
				cin>>ID;
				while( strlen(ID)!=18 )
					/*������֤�ų���*/
				{
					ID[18]=0;
					cout<<"����������֤�ų��ȴ���"<<" "<<ID<<endl;
					cout<<"�����������������֤����:"<<endl;
					cin>>ID;
				}

             	temp1=L;
				while(temp1->next!=NULL&&strcmp(ID,temp1->ID)!=0)
					temp1=temp1->next;
				if(strcmp(ID,temp1->ID)==0)
				{
					printf("�������֤�Ѿ������Ʊ��\n");
 		        break;
				}
				else
				{
					temp2=(IDList *)malloc(sizeof(IDList));
					temp2->next=temp1->next;
					temp1->next=temp2;
				}

				 cout<<"������"<<name<<":Ʊ�Ĳ�λ�ȼ�:"<<endl;
				 cin>>grade;
				 info->order=insertlink(info->order,amount,name,ID,grade);/*�ڶ�Ʊ��Ա����������ӿͻ���Ϣ*/
				 for(i=0;i<amount;i++)/*��������ö�Ʊ�ͻ�����λ��*/
				 {
					cout<<name<<"����λ����:"<<info->tkt_amt-info->tkt_sur+i+1<<endl;
				 }
				 info->tkt_sur-=amount;/*�ú��ߵ���Ʊ��Ӧ�����ÿͻ��Ķ�Ʊ��*/
				 printf("\nף��������죡\n");
			}
			else
			{
				return;
			}
		}
	}
	if(amount<=info->tkt_sur)
/*���ͻ���Ʊ��ĩ������Ʊ������Ʊ�ɹ����ȼ���Ϣ*/
	{
		int i;
		L=(IDList *)malloc(sizeof(IDList));
		L->next=NULL;
		temp1=L;
		for(i=0;i<amount;i++)
		{
			cout<<"������������������Ʊ�ͻ���:"<<endl;
			cin>>name;
			cout<<"�������������֤����:"<<endl;
			cin>>ID;
			while( strlen(ID)!=18 )
/*������֤�ų���*/
			{
				ID[18]=0;
				cout<<"����������֤�ų��ȴ���"<<" "<<ID<<endl;
				cout<<"�����������������֤����:"<<endl;
				cin>>ID;
			}
			
            temp1=L;
			while(temp1->next!=NULL&&strcmp(ID,temp1->ID)!=0)
			temp1=temp1->next;
			if(strcmp(ID,temp1->ID)==0)
			{
				printf("�������֤�Ѿ�������Ʊ��\n");
	        break;
			}
			else
			{
				temp2=(IDList *)malloc(sizeof(IDList));
				temp2->next=temp1->next;
	    	temp1->next=temp2;
			}

			cout<<"������"<<name<<"Ʊ�Ĳ�λ�ȼ�:"<<endl;
			cin>>grade;
			info->order=insertlink(info->order,amount,name,ID,grade);
			/*�ڶ�Ʊ��Ա����������ӿͻ���Ϣ*/
			for(i=0;i<amount;i++)
			/*��������ö�Ʊ�ͻ�����λ��*/
			{
				cout<<name<<"����λ����:"<<info->tkt_amt-info->tkt_sur+i+1<<endl;
			}
			info->tkt_sur-=amount;
			/*�ú��ߵ���Ʊ��Ӧ�����ÿͻ��Ķ�Ʊ��*/
			printf("\nף��������죡\n");
		}
	}
	else       
	/*����Ա����Ʊ�����ڶ�Ʊ�ѯ�ʿͻ��Ƿ���Ҫ�����ŶӵȺ�*/
	{ 
		char r;
		printf("\n�Ѿ�û�и����Ʊ������Ҫ�ŶӵȺ���?(Y/N)");
		r=getch();
		cout<<r<<endl;
		if(r=='Y'||r=='y')
		{ 
			cout<<"�����������������ŶӶ�Ʊ�ͻ���:"<<endl;
			cin>>name;
			info->wait=appendqueue(info->wait,name,amount);
   /*���ŶӵȺ��Ա����������ӿͻ���Ϣ*/
			cout<<"ע��ɹ�!"<<endl;
		}
		else 
		{
		   cout<<"��ӭ���´��ٴζ�����"<<endl;
		}
	}
}

void return_tkt()
/*��Ʊģ��*/
{
	struct airline *info;
	qnode *t,*back,*f,*r;
	int grade;
	linklist *p1,*p2,*head;
	char cusname[10];
	if(!(info=find())) return;
/*���ò�ѯ���������ݿͻ��ṩ�ĺ��߽�������*/
	head=info->order;
	p1=head;
	cout<<"�����������������Ʊ�ͻ���:"<<endl;
	cin>>cusname;
	while(p1!=NULL)
	{
/*���ݿͻ��ṩ����������Ʊ�ͻ���������в�ѯ*/
		if(!strcmp(cusname,p1->name)) break;
		p2=p1;p1=p1->next;
	}
    if(p1==NULL)
	{
		cout<<"�Բ�����û�ж���Ʊ!"<<endl;
		return;
	}
/*��δ�ҵ����˳���ģ��*/
    else
    {
/*����Ϣ��ѯ�ɹ���ɾ����Ʊ�ͻ��������е���Ϣ*/
        if(p1==head) head=p1->next;
        else p2->next=p1->next;
        info->tkt_sur+=p1->ord_amt;
        grade=p1->grade;
        cout<<"�ɹ���Ʊ��"<<p1->name<<endl;
        free(p1);
    }
    info->order=head;
/*���½�����������ָ��Ʊ�������ͷָ�� */
    f=(info->wait).front;
/*fָ���ŶӵȺ��������е�ͷ���*/
    r=(info->wait).rear;
/*rָ���ŶӵȺ��������е�β���*/
    t=f;
/*tΪ��ǰ�����������ŶӺ�������*/
    while(t)
    {
		if(info->tkt_sur=info->wait.front->req_amt)
		{
/*������������Ϊͷ���*/
			int i;
			info->wait.front=t->next;
			cout<<"��Ʊ�ɹ���"<<t->name<<endl;
			for(i=0;i<t->req_amt;i++)
/*�����λ��*/
				 printf("%s����λ����:%d\n",t->name,(info->tkt_sur)-i);
			info->tkt_sur-=t->req_amt;
				  info->order=insertlink(info->order,t->req_amt,t->name,t->ID,grade);
/*���뵽��Ʊ�ͻ�����������*/
			free(t);
			break;
		}
		back=t;
		t=t->next;
		if((info->tkt_sur)>=(t->req_amt)&&t!=NULL)
/*�����������߲�Ϊͷ���*/
		{
			int i;
			back->next=t->next;
			cout<<"��Ʊ�ɹ���"<<t->name<<endl;
			for(i=0;i<t->req_amt;i++)/*�����λ��*/
			printf("<%s>'s seat number is:%d\n",t->name,(info->tkt_sur)-i);
			info->tkt_sur-=t->req_amt;
			info->order=insertlink(info->order,t->req_amt,t->name,t->ID,grade);
/*���뵽��Ʊ�ͻ�����������*/
			free(t);
			break;
		}
		if(f==r) break;
    }
}

void sort_tkt()
{/*��ʣ��Ʊ������*/

    int j;
    struct airline t,*info,*p,*q;
	p=info=air;
	for(p=info;(p+1)->tkt_sur;p++)
	{
	   for(q=p+1;q->tkt_sur;q++)
	   {
		   if(p->tkt_sur<q->tkt_sur)
		   {
			t=*p;
			*p=*q;
			*q=t;
		   }
	   }
	}
    cout<<"�յ�վ��"<<" "<<"�����"<<" "<<"�ɻ���"<<" "<<"��������"<<" "<<"��Ա����"<<" "<<"��Ʊ��"<<endl;
    for(j=0;j<MAXSIZE;j++)
    {
         display(info);
         info++;
    }
}

//ɾ������
void rewrite()
{
	fstream file;
	file.open("airline.txt");
	int i;
	for (i=0;i<MAXSIZE;i++) 
	{	

		//printf("��ȡ���ں���%d��Ϣ(��%d��)",i+1,MAXSIZE);
		//cout<<endl;
		//�ļ�����
		//��ȡ!
		file>>(air+i)->ter_name>>(air+i)->air_num>>(air+i)->plane_num>>(air+i)->date>>(air+i)->tkt_amt>>(air+i)->tkt_sur;
	}
	file.close();

	cout<<"�����г����к��ߣ�"<<endl;
	list();
	cout<<"��Ҫɾ��һ�����ߣ��������������ߵ���ţ�"<<endl;

	ofstream file_in;
	file_in.open("airline.txt",ios::trunc);
	
	int a;
	cin>>a;
	cout<<"��ѡ����ɾȥ���Ϊ"<<a<<"�ĺ���"<<endl<<endl;
	
	while (i<MAXSIZE) 
	{	
		if(i==a-1)
      //��д��ѡ��ɾ������һ�����ߣ��ﵽ��ɾ��Ŀ��
		{
			goto lable;
		}
		//�ļ�����
		//д��!
		file_in<<(air+i)->ter_name<<"    "<<(air+i)->air_num<<"    "<<(air+i)->plane_num<<"    "<<(air+i)->date
			<<"    "<<(air+i)->tkt_amt<<"    "<<(air+i)->tkt_sur<<endl;
		lable:
		i++;
	}
	file_in.close();

	file.open("airline.txt");
	for (int k=0;i<MAXSIZE;i++) 
	{	

		//printf("��ȡ���ں���%d��Ϣ(��%d��)",i+1,MAXSIZE);
		//cout<<endl;
		//�ļ�����
		//��ȡ!
		file>>(air+i)->ter_name>>(air+i)->air_num>>(air+i)->plane_num>>(air+i)->date>>(air+i)->tkt_amt>>(air+i)->tkt_sur;
	}
}

//���뺽����Ϣ
void loadairline()
{
	cout<<"���ڿ�ʼ��ȡ������Ϣ"<<endl;
	fstream file;
	file.open("airline.txt");

	//cin>>(air+i)->ter_name>>(air+i)->air_num>>(air+i)->plane_num>>(air+i)->date>>(air+i)->tkt_amt>>(air+i)->tkt_sur;

	//for (int i=0;i<MAXSIZE;i++) 
	//{	
	//	//����! 
	//	(air+i)->ter_name = "  ";
	//	
	//}
	for (int i=0;i<MAXSIZE;i++) 
	{	

		printf("��ȡ���ں���%d��Ϣ(��%d��)",i+1,MAXSIZE);
		cout<<endl;
		//�ļ�����
		//��ȡ!
		file>>(air+i)->ter_name>>(air+i)->air_num>>(air+i)->plane_num>>(air+i)->date>>(air+i)->tkt_amt>>(air+i)->tkt_sur;
	}
	cout<<"��ȡ���!"<<endl;
}
void Read_Airline();
void Save_Information();
void menu_select()
/*�˵�����*/
{
	char menu_select;
	cout<<"         ~~~~~~~~~������տ��˶�Ʊϵͳ������~~~~~~~"<<endl;
	cout<<"������Ѿ�¼���˺�����Ϣ������ 8 ���ļ����룬��Ҳ�������� 7 �趨�µĺ�����Ϣ"<<endl;
	cout<<"**********************************************************************"<<endl;
	cout<<"                           1.���������Ϣ"<<endl;
	cout<<"                           2.����Ѷ�Ʊ�ͻ���Ϣ"<<endl;
	cout<<"                           3.��ѯ����"<<endl;
	cout<<"                           4.����Ʊҵ��"<<endl;
	cout<<"                           5.������Ʊҵ��"<<endl;
	cout<<"                           6.�鿴ʣ��Ʊ��������"<<endl;
	cout<<"                           7.�趨������Ϣ"<<endl;
	cout<<"                           8.���뺽����Ϣ"<<endl;
	cout<<"                           9.ɾ��������Ϣ"<<endl;
	cout<<"                           0.�˳�ϵͳ"<<endl;
	cout<<"**********************************************************************"<<endl;
lable:
	cout<<"��ѡ��"<<endl;
	cin>>menu_select;
	if(menu_select=='1')
	{
		start=air;
		Read_Airline();
		list();
	}
	else if(menu_select=='2')
	{
		start=air;
		prtlink();
	}
	else if(menu_select=='3')
	{
		start=air;
		search();
	}
	else if(menu_select=='4')
	{
		start=air;
		order();
	}
	else if(menu_select=='5')
	{
		start=air;
		return_tkt();
	}
	else if(menu_select=='6')
	{   
		start=air;
		sort_tkt();
	}
	else if(menu_select=='7')
	{
		insert();
		Save_Information();
	//	true=0;
	}
	else if(menu_select=='8')
	{
		start=air;
		loadairline();
	}
	else if(menu_select=='9')
	{
		start=air;
		rewrite();
	}
	else if(menu_select=='0')
	{
		cout<<"��ӭʹ�ñ�ϵͳ���ټ���"<<endl;
		exit(0);
	}
	else
	{
		goto lable;
	}
}
//�������뺽�����Ϣ
void Save_Information()
{
   FILE *fp;
   int i=0;
   if((fp=fopen("user.txt","wb"))==NULL){
      printf("��ʧ�ܣ�\n");
	  return;
   }
   while(i<MAXSIZE){
	fwrite(&air[i],sizeof(struct airline),1,fp);
     i++;
   }
   fclose(fp);
}
//�û�����
void commenu_select(){
	char menu_select;
	cout<<"        ���տ��˶�Ʊϵͳ"<<endl;
	cout<<"******************************************"<<endl;
	cout<<"       1.���������Ϣ"<<endl;
	cout<<"       2.��ѯ����"<<endl;
	cout<<"       3.����Ʊҵ��"<<endl;
	cout<<"       4.������Ʊҵ��"<<endl;
	cout<<"       0.�˳�ϵͳ"<<endl;
	cout<<"*******************************************"<<endl;
lable:
	cout<<"��ѡ��"<<endl;
	cin>>menu_select;
	if(menu_select=='1')
	{
		start=air;
		Read_Airline();
		list();
	}
	else if(menu_select=='2')
	{
		start=air;
		search();
	}
	else if(menu_select=='3')
	{
		start=air;
		order();
	}
	else if(menu_select=='4')
	{
		start=air;
		return_tkt();
	}
	else if(menu_select=='0')
	{
		cout<<"��ӭʹ�ñ�ϵͳ���ټ���"<<endl;
		exit(0);
	}
	else
	{
		goto lable;
	}
}
/*********************����Ա����*********************************/
void AdEnter(){
    char n[8],m1[10],m;
    char flag;
	int k1=0,pw=0;
    FILE *fp;
    ad a;
	k1=0;
	pw=0; 
    cout<<"\n\t\t\t�������˺ţ�";
    cin>>n;
    if((fp=fopen("adfile.txt","rb"))==NULL){
         cout<<"�޷����ļ�"<<endl;
           exit(0);
    }
    while(fread(&a,sizeof(ad),1,fp)==1){
         if(strcmp(n,a.Enternum)==0){
			 pw=1;
         cout<<"\t\t\t���������룺";
         do{
		    fflush(stdin);	 
		    for(m=getch();m!=13&&k1<10;m=getch())
			{
		    if (m==8 ) 
			{ 
				 if (k1>0 ) 
				{ 
					  printf("\b"); 
				      m1[--k1]='\0'; 
				} 
				 putchar(0); 
				 printf("\b"); 
				 continue ; 
			}       
			if( m<32 || m>127 )
				     continue; 
		
			printf("*"); 

			m1[k1++] = m; 
			}
		  m1[k1] = '\0'; 
		  if(m1[0]=='\0')
	      cout<<"\t\t""���벻��Ϊ�գ�����������"<<endl;
		  fflush(stdin);
		 }while(m1[0]=='\0');
         system("cls");
         if(strcmp(m1,a.key)==0){
                while(true)
				{
					menu_select();
				}
                 break;
          }
          else{
                cout<<"�������,�밴���������\n";
                system("pause");
                system("cls");                    
                break;
           }
		  break;
		 }
		 
		}
        if(pw!=1){
              system("cls");
              cout<<"�ʺŲ�����,�����������\n";
              system("pause");
              system("cls");
         }
		  fclose(fp);
}
/*********************�û��������*********************************************************/
void comender(){
    char n[8],m1[10],m;
    char flag,t;
	int k1=0,pw=0,i=0,re;
    FILE *fp,*fd;
    com c;
	number num;
    if((fd=fopen("num.txt","rb"))==NULL){
          cout<<"can't open person.txt.\n"<<endl;
          exit(0);
    }
	re=fread(&num,sizeof(num),1,fd);
         cout<<"\t\t\t�������˺ţ�";
         cin>>n;
         if((fp=fopen("com.txt","rb+"))==NULL){
              cout<<"�޷����ļ�"<<endl;
              exit(0);
         }
         while(i<num.comnum){
			  re=fread(&c,sizeof(c),1,fp);
              if(strcmp(n,c.EnterNum)==0){
				     pw=1;
                     cout<<"\t\t\t���������룺";
                     do{
		                 fflush(stdin);	 
		                 for(m=getch();m!=13&&k1<10;m=getch()){
		                 if (m==8 ) 
						 { 
				             if (k1>0 ) 
							 { 
					             printf("\b"); 
				        	     m1[--k1]='\0'; 
							 } 
				         putchar(0); 
				         printf("\b"); 
				         continue ; 
						 }       
			            if( m<32 || m>127 )
				        continue; 
		
			             printf("*"); 

			             m1[k1++] = m; 
						 }
		                 m1[k1] = '\0'; 
		                 if(m1[0]=='\0')
			             cout<<"\t\t""���벻��Ϊ�գ�����������"<<endl;
		                 fflush(stdin);
					 }while(m1[0]=='\0');
                     system("cls");
                     if(strcmp(m1,c.key)==0){
                         	while(true)
							{
							commenu_select();
							} 
						 system("cls");
                           break;
                     }
                     else{
                         cout<<"�������,�밴���������\n";
                         system("pause");
                         system("cls");                    
                         break;
                     }
					 break;
               }
			  else i++;
          }
		 
          if(pw!=1){
              system("cls");
              cout<<"�ʺŲ�����,�����������\n";
              system("pause");
              system("cls");
          }
		  fclose(fp);
		  fclose(fd);
}
/*********************ע�����Ա��Ϣ*************************************/
void inputad(){
	int s1;
	ad a1;
	char t,m,m1[10],m2[10],*p=m1;
     FILE *fp,*fd;
	 int i=0;
	 int k,k1=0,k2=0;
	 char flag,ch;
	 number num;
	 if((fd=fopen("num.txt","rb+"))==NULL){
          fd=fopen("num.txt","wb+");
		   num.adnum=0;
		  num.comnum=0;
	 }
	 else k=fread(&num,sizeof(num),1,fd);
     if(num.adnum<0)  num.adnum=0;
	 fclose(fd);
	 if((fp=fopen("adfile.txt","rb+"))==NULL){
                fp=fopen("adfile.txt","wb+");
		  }
l1:
     system("cls");
	 cout<<"\n\n************************ע�����Ա��Ϣ************************\n\n";
     i=0;
	 strcpy(a1.Enternum,"admin");	
	 cout<<"\t\t�˺ţ�"<<a1.Enternum<<endl;      
     cout<<"\n\t\t����������";     cin>>a1.name;
     cout<<"\n\t\t�����Ա�";     cin>>a1.sex;
     cout<<"\n\t\t�������䣺";     cin>>a1.age;
l2:	 cout<<"\n\t\t�������룺";
	 k1=0;
	 k2=0;
     do{
		fflush(stdin);	  //��ϴ�����Է����������ȷ����
		for(m=getch();m!=13&&k1<10;m=getch()){
		//���û�����س��������������   
			if (m==8 ) /*���û������˸���򡭡�*/ 
			{ 
				if (k1>0 ) /*�������ʾ������Ϊ0�򡭡�*/ 
				{ 
					printf("\b"); /*��һ����*/ 
					m1[--k1]='\0'; /*password[i-1]��ֵ��Ϊ'\0', ����ʾ������һ,��������ֵ��һ*/ 
				} 
				putchar(0); /*��ʾ���ַ�*/ 
				printf("\b"); /*��һ����*/ 
				continue ; 
			}       
			if( m<32 || m>127 )
				continue; /*����ֻ��ΪASCII��ֵΪ32-127���ַ�,��ֻ֤��������ĸ����*/ 
		
			printf("*"); /*�����������������ʾһ����*/ 

			m1[k1++] = m; /*��ch����password[i],����ʾ������һ,��������ֵ��һ*/  
		}
		m1[k1] = '\0'; /*���ý�β�Ŀ��ַ�*/ 
		if(m1[0]=='\0')
			cout<<"\t\t""���벻��Ϊ�գ�����������"<<endl;
		fflush(stdin);
	}while(m1[0]=='\0');
	cout<<"\n\n\t\tȷ�����룺";
     do{
		fflush(stdin);	 
		for(m=getch();m!=13&&k2<10;m=getch()){
	
			if (m==8 ) 
			{ 
				if (k2>0 ) 
				{ 
					printf("\b"); 
					m2[--k2]='\0'; 
				} 
				putchar(0); 
				printf("\b"); 
				continue ; 
			}       
			if( m<32 || m>127 )
				continue; 
		
			printf("*"); 

			m2[k2++] = m; 
		}
		m2[k2] = '\0'; 
		if(m2[0]=='\0')
			cout<<"\t\t""���벻��Ϊ�գ�����������"<<endl;
		fflush(stdin);
	}while(m2[0]=='\0');
	 if(strcmp(m1,m2)==0)   strcpy(a1.key,m1);
	 else {
		 cout<<"\t\t���벻ƥ�����������룡\n";
		 goto l2;
	 }
     do{
		cout<<"\n\n\t\t�Ƿ�ȷ�����룿��Y/N��";
		cin>>ch;
	}while(ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N');
	if(ch=='y'||ch=='Y'){
		fseek(fp,0,2);
		fwrite(&a1,sizeof(a1),1,fp);
		num.adnum++;
		fseek(fp,0,0);
		system("cls");
		cout<<"��ӳɹ���"<<endl;
		system("pause");
		system("cls");
	}
    else goto l1;  
	    if((fd=fopen("num.txt","wb+"))==NULL){
               cout<<"can't open num.txt.\n"<<endl;
               exit(0);
	}
	fwrite(&num,sizeof(num),1,fd);
    fclose(fp);
	fclose(fd);
}
/*********************ע���û�*****************************************/
void inputcom(){
	int s1;
	com a1;
	char t,m,m1[10],m2[10],*p=m1;
     FILE *fp,*fd;
	 int i=0;
	 int k,k1=0,k2=0;
	 char flag,ch;
	 number num;
	 if((fd=fopen("num.txt","rb+"))==NULL){
          fd=fopen("num.txt","wb+");
		  num.comnum=0;
	 }
	 else k=fread(&num,sizeof(num),1,fd);
     if(num.comnum<0)  num.comnum=0;
	 fclose(fd);
	 if((fp=fopen("com.txt","rb+"))==NULL){
                fp=fopen("com.txt","wb+");
		  }
l1:
     system("cls");
	 cout<<"\n\n************************ע���û���Ϣ************************\n\n";
     i=0;	
	 cout<<"\t\t�����˺ţ���λ����";  cin>>a1.EnterNum;      
     cout<<"\n\t\t����������";     cin>>a1.name;	
     cout<<"\n\t\t�����Ա�";     cin>>a1.sex;
     cout<<"\n\t\t�������䣺";     cin>>a1.age;
l2:	 cout<<"\n\t\t�������룺";
	 k1=0;
	 k2=0;
     do{
		fflush(stdin);	  //��ϴ�����Է����������ȷ����
		for(m=getch();m!=13&&k1<10;m=getch()){
		//���û�����س��������������   
			if (m==8 ) /*���û������˸���򡭡�*/ 
			{ 
				if (k1>0 ) /*�������ʾ������Ϊ0�򡭡�*/ 
				{ 
					printf("\b"); /*��һ����*/ 
					m1[--k1]='\0'; /*password[i-1]��ֵ��Ϊ'\0', ����ʾ������һ,��������ֵ��һ*/ 
				} 
				putchar(0); /*��ʾ���ַ�*/ 
				printf("\b"); /*��һ����*/ 
				continue ; 
			}       
			if( m<32 || m>127 )
				continue; /*����ֻ��ΪASCII��ֵΪ32-127���ַ�,��ֻ֤��������ĸ����*/ 
		
			printf("*"); /*�����������������ʾһ����*/ 

			m1[k1++] = m; /*��ch����password[i],����ʾ������һ,��������ֵ��һ*/  
		}
		m1[k1] = '\0'; /*���ý�β�Ŀ��ַ�*/ 
		if(m1[0]=='\0')
			cout<<"\t\t""���벻��Ϊ�գ�����������"<<endl;
		fflush(stdin);
	}while(m1[0]=='\0');
	cout<<"\n\n\t\tȷ�����룺";
     do{
		fflush(stdin);	 
		for(m=getch();m!=13&&k2<10;m=getch()){
	
			if (m==8 ) 
			{ 
				if (k2>0 ) 
				{ 
					printf("\b"); 
					m2[--k2]='\0'; 
				} 
				putchar(0); 
				printf("\b"); 
				continue ; 
			}       
			if( m<32 || m>127 )
				continue; 
		
			printf("*"); 

			m2[k2++] = m; 
		}
		m2[k2] = '\0'; 
		if(m2[0]=='\0')
			cout<<"\t\t""���벻��Ϊ�գ�����������"<<endl;
		fflush(stdin);
	}while(m2[0]=='\0');
	 if(strcmp(m1,m2)==0)   strcpy(a1.key,m1);
	 else {
		 cout<<"\t\t���벻ƥ�����������룡\n";
		 goto l2;
	 }
     do{
		cout<<"\n\n\t\t�Ƿ�ȷ�����룿��Y/N��";
		cin>>ch;
	}while(ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N');
	if(ch=='y'||ch=='Y'){
		fseek(fp,0,2);
		fwrite(&a1,sizeof(a1),1,fp);
		num.comnum++;
		fseek(fp,0,0);
		system("cls");
		cout<<"��ӳɹ���"<<endl;
		system("pause");
		system("cls");
	}
    else goto l1;  
    if((fd=fopen("num.txt","wb+"))==NULL){
               cout<<"can't open num.txt.\n"<<endl;
               exit(0);
	}
	fwrite(&num,sizeof(num),1,fd);
    fclose(fp);
	fclose(fd);
}
/*********************����*****************************************/
void ChoiseSystem(){
	
    char flag;
	int f=1,k=0;
	number num;
	FILE *fd;
	if((fd=fopen("num.txt","rb+"))==NULL){
		fd=fopen("num.txt","wb+");
	}
	k=fread(&num,sizeof(num),1,fd);
	if(num.adnum<0)  num.adnum=0;
	if(num.adnum==0)  
		inputad();
     while(1){
cout<<"                   ����������������������������������������"<<endl; 
cout<<"                   ��             1.����Ա��¼           ��"<<endl;
cout<<"                   ����������������������������������������"<<endl;
cout<<"                   ��             2.�û���¼             ��"<<endl;
cout<<"                   ����������������������������������������"<<endl;
cout<<"                   ��             3.�û�ע��             ��"<<endl;
cout<<"                   ����������������������������������������"<<endl;
cout<<"                   ��             0.�˳�ϵͳ             ��"<<endl;
cout<<"                   ����������������������������������������"<<endl;
          do{
            cout<<"��ѡ��";
            cin>>flag;
            fflush(stdin);  
          }while(flag!='1'&&flag!='2'&&flag!='0'&&flag!='3');
          switch(flag){
                 case '1':
                         AdEnter();
                         break;
                 case '2':
                        comender();
                         break;
				 case '3':
                         inputcom();
						 break;
                 case '0':
                         f=0;
						 break;
          }
          if(f==0)  break;
	   }
} 

void Read_Airline(){
    FILE *fp;
	int count;
   int i=0;
   if((fp=fopen("user.txt","rb"))==NULL){
      printf("��ʧ�ܣ�\n");
	  return;
   }
   while(i<MAXSIZE){
	  count=fread(&air[i],sizeof(struct airline),1,fp);
	 // cout<<"count="<<count;
     i++;
   }
   fclose(fp);
}

int main()
{
ChoiseSystem();
	return 0;
}
