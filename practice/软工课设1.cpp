#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <fstream>
using namespace std;
#define MAXSIZE 9
 /*定义航线量的最大值*/

typedef struct ads{
     char Enternum[7];
	 char name[100];
     char sex[2];
     int  age;
     char key[10];
}ad;

typedef struct cms{
    char EnterNum[8];    //登入账号
    char name[100];      //姓名
    char sex[2];         //性别
    int age;             //年龄
    char key[10];        //登入密码
}com;

typedef struct numbers{
    int comnum;//用户人数
	int adnum;  //管理员人数；
}number;

typedef struct IDNode
{
	char ID[18];
	struct IDNode *next;
}IDList;

typedef struct wat_ros
{ 
	char name[10];/*姓名*/
	char ID[18];/*身份证号*/
	int req_amt;/*订票量*/
	struct wat_ros *next;
}qnode,*qptr;

typedef struct pqueue
{
	qptr front;/*等候替补客户名单域的头指针*/
	qptr rear;/*等候替补客户名单域的属指针*/
}linkqueue;

typedef struct ord_ros
{  
	char name[10];/*客户姓名*/
	char ID[18];/*身份证号*/
	int ord_amt;/*订票量*/
	int grade;/*舱位等级*/
	struct ord_ros *next;
}linklist;

struct airline
{
	char ter_name[10];/*终点站名 */
    char air_num[10];/*航班号*/
    char plane_num[10];/*飞机号*/
    char date[7];/*飞行日期（星期几）*/
    int tkt_amt;/*乘员定额*/
    int tkt_sur;/*余票量*/
    linklist *order;
	/*乘员名单域，指向乘员名单链表的头指针*/
    linkqueue wait;
	/*等候替补的客户名单域，分别指向排队等候名单队头队尾的指针*/
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
	cout<<"请输入航班"<<i+1<<"信息(共"<<MAXSIZE<<"条)"<<endl;
		cout<<"请输入终点站名字："<<endl;
		cin>>(air+i)->ter_name;
		cout<<"请输入航班号："<<endl;
		cin>>(air+i)->air_num;
	    cout<<"请输入飞机号："<<endl;
		cin>>(air+i)->plane_num;
		cout<<"请输入飞行日期："<<endl;
        cin>>(air+i)->date;
		cout<<"请输入乘员定额："<<endl;
		cin>>(air+i)->tkt_amt;
		cout<<"请输入余票量："<<endl;
		cin>>(air+i)->tkt_sur;
			//文件操作
		//写入!
		file<<(air+i)->ter_name<<"    "<<(air+i)->air_num<<"    "<<(air+i)->plane_num<<"    "<<(air+i)->date
			<<"    "<<(air+i)->tkt_amt<<"    "<<(air+i)->tkt_sur<<endl;
		/*cin>>(air+i)->ter_name>>(air+i)->air_num>>(air+i)->plane_num>>(air+i)->date>>(air+i)->tkt_amt>>(air+i)->tkt_sur;*/
		printf("还需要继续添加吗？(Y,y/N,n)\n");
		cin>>NG;
}while((NG=='Y'||NG=='y')&&(i++<=MAXSIZE));	
}



void display(struct airline *info)
/*打印每条航线的基本信息*/
{
 printf("│ %-6.6s │ %-6.6s │  %-6.6s│  %-6.6s  │   %-6.0d │   %-6.0d │\n",info->ter_name,info->air_num,info->plane_num,info->date,info->tkt_amt,info->tkt_sur);
}
void list()
/*打印全部航线信息*/
{ 
	struct airline *info;
	int i=0;
	info=air;
	cout<<"┌────┬────┬────┬─────┬─────┬─────┐"<<endl;
    cout<<"│终点站名│ 航班号 │飞机号  │飞行日期  │ 乘员定额 │  余票量  │"<<endl;
    cout<<"├────┼────┼────┼─────┼─────┼─────┤"<<endl;
	while(i<MAXSIZE)
	{
		display(info);
		if(i!=MAXSIZE-1)
		printf("├────┼────┼────┼─────┼─────┼─────┤\n");
		info++;
		i++;
	}
	cout<<"└────┴────┴────┴─────┴─────┴─────┘\n";
	printf("\n\n");
}



void search()
/*根据客户提出的终点站名输出航线信息*/
{
	struct airline *info,*find();
	char name[10];
	int i=0;
	info=start;
	cout<<"请输入终点站名:"<<endl;
	cin>>name;
	while(i<MAXSIZE) 
	{
		if(!strcmp(name,info->ter_name)) break;
		info++;
		i++;
	}
	if(i>=MAXSIZE)
		cout<<"对不起，该航线未找到!"<<endl;
	else
	{
		cout<<"终点站名"<<" "<<"航班号"<<" "<<"飞机号"<<" "<<"飞行日期"<<" "<<"成员定额"<<" "<<"余票量"<<endl;
		display(info);
	}
}
struct airline *find()
/*根据系统提出的航班号查询并以指针形式返回*/
{ struct airline *info;
   char number[10];
   int i=0;
   info=start;
   cout<<"请输入航班号:"<<endl;
  cin>>number;
   while(i<MAXSIZE) 
   {
     if(!strcmp(number,info->air_num)) return info;
     info++;
     i++;
   }
   cout<<"对不起，该航线未找到!"<<endl;
   return NULL;
}
void prtlink()
/*打印订票乘员名单域的客户名单信息*/
{
	linklist *p;
	struct airline *info;
	info=find();
	p=info->order;
	if(p!=NULL)
	{
		cout<<"客户姓名     身份证号           订票数额   舱位等级"<<endl;
		while(p)
		{
			cout<<p->name<<" "<<p->ID<<" "<<p->ord_amt<<" "<<p->grade<<endl;
			p=p->next;
		}
	}
	else
	{
		cout<<"该航线没有客户信息!"<<endl;
	}
}
linklist *insertlink(linklist *head,int amount,char name[],char ID[],int grade)
/*增加订票乘员名单域的客户信息*/
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
		/*若原无订票客户信息*/
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
/*增加排队等候的客户名单域*/
{ 
	qptr new1;
	new1=(qptr)malloc(sizeof(qnode));
	strcpy(new1->name,name);
	new1->req_amt=amount;
	new1->next=NULL;
	if(q.front==NULL)
/*若原排队等候客户名单域为空*/
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
/*办理订票业务*/
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
/*根据客户提供的航班号进行查询，如为空，退出该模块*/
	cout<<"请输入你订票所需要的数量:"<<endl;
	scanf("%d",&amount);
	if(amount>info->tkt_sur)/*若客户订票额超过乘员定票总额，要求用户选择*/
	{ 
		cout<<"对不起，您输入的票的数量已经超过余票定额!"<<endl;
		cout<<"输入 1 ，预定所有"<<info->tkt_sur<<"张剩余机票 ，输入 2 返回！"<<endl;
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
				cout<<"请输入您的姓名（订票客户）:"<<endl;
				cin>>name;
				cout<<"请输入您的身份证号码:"<<endl;
				cin>>ID;
				while( strlen(ID)!=18 )
					/*检查身份证号长度*/
				{
					ID[18]=0;
					cout<<"您输入的身份证号长度错误"<<" "<<ID<<endl;
					cout<<"请重新输入您的身份证号码:"<<endl;
					cin>>ID;
				}

             	temp1=L;
				while(temp1->next!=NULL&&strcmp(ID,temp1->ID)!=0)
					temp1=temp1->next;
				if(strcmp(ID,temp1->ID)==0)
				{
					printf("您的身份证已经领过余票！\n");
 		        break;
				}
				else
				{
					temp2=(IDList *)malloc(sizeof(IDList));
					temp2->next=temp1->next;
					temp1->next=temp2;
				}

				 cout<<"请输入"<<name<<":票的舱位等级:"<<endl;
				 cin>>grade;
				 info->order=insertlink(info->order,amount,name,ID,grade);/*在订票乘员名单域中添加客户信息*/
				 for(i=0;i<amount;i++)/*依次输出该订票客户的座位号*/
				 {
					cout<<name<<"的座位号是:"<<info->tkt_amt-info->tkt_sur+i+1<<endl;
				 }
				 info->tkt_sur-=amount;/*该航线的余票量应减掉该客户的订票量*/
				 printf("\n祝您乘坐愉快！\n");
			}
			else
			{
				return;
			}
		}
	}
	if(amount<=info->tkt_sur)
/*若客户订票额末超过余票量，订票成功并等记信息*/
	{
		int i;
		L=(IDList *)malloc(sizeof(IDList));
		L->next=NULL;
		temp1=L;
		for(i=0;i<amount;i++)
		{
			cout<<"请输入您的姓名（订票客户）:"<<endl;
			cin>>name;
			cout<<"请输入您的身份证号码:"<<endl;
			cin>>ID;
			while( strlen(ID)!=18 )
/*检查身份证号长度*/
			{
				ID[18]=0;
				cout<<"您输入的身份证号长度错误"<<" "<<ID<<endl;
				cout<<"请重新输入您的身份证号码:"<<endl;
				cin>>ID;
			}
			
            temp1=L;
			while(temp1->next!=NULL&&strcmp(ID,temp1->ID)!=0)
			temp1=temp1->next;
			if(strcmp(ID,temp1->ID)==0)
			{
				printf("您的身份证已经顶过余票！\n");
	        break;
			}
			else
			{
				temp2=(IDList *)malloc(sizeof(IDList));
				temp2->next=temp1->next;
	    	temp1->next=temp2;
			}

			cout<<"请输入"<<name<<"票的舱位等级:"<<endl;
			cin>>grade;
			info->order=insertlink(info->order,amount,name,ID,grade);
			/*在订票乘员名单域中添加客户信息*/
			for(i=0;i<amount;i++)
			/*依次输出该订票客户的座位号*/
			{
				cout<<name<<"的座位号是:"<<info->tkt_amt-info->tkt_sur+i+1<<endl;
			}
			info->tkt_sur-=amount;
			/*该航线的余票量应减掉该客户的订票量*/
			printf("\n祝您乘坐愉快！\n");
		}
	}
	else       
	/*若满员或余票额少于订票额，询问客户是否需要进行排队等候*/
	{ 
		char r;
		printf("\n已经没有更多的票，您需要排队等候吗?(Y/N)");
		r=getch();
		cout<<r<<endl;
		if(r=='Y'||r=='y')
		{ 
			cout<<"请输入您的姓名（排队订票客户）:"<<endl;
			cin>>name;
			info->wait=appendqueue(info->wait,name,amount);
   /*在排队等候乘员名单域中添加客户信息*/
			cout<<"注册成功!"<<endl;
		}
		else 
		{
		   cout<<"欢迎您下次再次订购！"<<endl;
		}
	}
}

void return_tkt()
/*退票模块*/
{
	struct airline *info;
	qnode *t,*back,*f,*r;
	int grade;
	linklist *p1,*p2,*head;
	char cusname[10];
	if(!(info=find())) return;
/*调用查询函数，根据客户提供的航线进行搜索*/
	head=info->order;
	p1=head;
	cout<<"请输入你的姓名（退票客户）:"<<endl;
	cin>>cusname;
	while(p1!=NULL)
	{
/*根据客户提供的姓名到订票客户名单域进行查询*/
		if(!strcmp(cusname,p1->name)) break;
		p2=p1;p1=p1->next;
	}
    if(p1==NULL)
	{
		cout<<"对不起，你没有订过票!"<<endl;
		return;
	}
/*若未找到，退出本模块*/
    else
    {
/*若信息查询成功，删除订票客户名单域中的信息*/
        if(p1==head) head=p1->next;
        else p2->next=p1->next;
        info->tkt_sur+=p1->ord_amt;
        grade=p1->grade;
        cout<<"成功退票！"<<p1->name<<endl;
        free(p1);
    }
    info->order=head;
/*重新将航线名单域指向订票单链表的头指针 */
    f=(info->wait).front;
/*f指向排队等候名单队列的头结点*/
    r=(info->wait).rear;
/*r指向排队等候名单队列的尾结点*/
    t=f;
/*t为当前满点条件的排队候补名单域*/
    while(t)
    {
		if(info->tkt_sur=info->wait.front->req_amt)
		{
/*若满足条件者为头结点*/
			int i;
			info->wait.front=t->next;
			cout<<"订票成功！"<<t->name<<endl;
			for(i=0;i<t->req_amt;i++)
/*输出座位号*/
				 printf("%s的座位号是:%d\n",t->name,(info->tkt_sur)-i);
			info->tkt_sur-=t->req_amt;
				  info->order=insertlink(info->order,t->req_amt,t->name,t->ID,grade);
/*插入到订票客户名单链表中*/
			free(t);
			break;
		}
		back=t;
		t=t->next;
		if((info->tkt_sur)>=(t->req_amt)&&t!=NULL)
/*若满足条件者不为头结点*/
		{
			int i;
			back->next=t->next;
			cout<<"订票成功！"<<t->name<<endl;
			for(i=0;i<t->req_amt;i++)/*输出座位号*/
			printf("<%s>'s seat number is:%d\n",t->name,(info->tkt_sur)-i);
			info->tkt_sur-=t->req_amt;
			info->order=insertlink(info->order,t->req_amt,t->name,t->ID,grade);
/*插入到订票客户名单链表中*/
			free(t);
			break;
		}
		if(f==r) break;
    }
}

void sort_tkt()
{/*按剩余票数排序*/

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
    cout<<"终点站名"<<" "<<"航班号"<<" "<<"飞机号"<<" "<<"飞行日期"<<" "<<"乘员定额"<<" "<<"余票量"<<endl;
    for(j=0;j<MAXSIZE;j++)
    {
         display(info);
         info++;
    }
}

//删除航线
void rewrite()
{
	fstream file;
	file.open("airline.txt");
	int i;
	for (i=0;i<MAXSIZE;i++) 
	{	

		//printf("读取正在航班%d信息(共%d条)",i+1,MAXSIZE);
		//cout<<endl;
		//文件操作
		//读取!
		file>>(air+i)->ter_name>>(air+i)->air_num>>(air+i)->plane_num>>(air+i)->date>>(air+i)->tkt_amt>>(air+i)->tkt_sur;
	}
	file.close();

	cout<<"现在列出所有航线："<<endl;
	list();
	cout<<"需要删除一条航线，请输入这条航线的序号！"<<endl;

	ofstream file_in;
	file_in.open("airline.txt",ios::trunc);
	
	int a;
	cin>>a;
	cout<<"您选择了删去序号为"<<a<<"的航线"<<endl<<endl;
	
	while (i<MAXSIZE) 
	{	
		if(i==a-1)
      //不写入选择删除的那一条航线，达到了删除目的
		{
			goto lable;
		}
		//文件操作
		//写入!
		file_in<<(air+i)->ter_name<<"    "<<(air+i)->air_num<<"    "<<(air+i)->plane_num<<"    "<<(air+i)->date
			<<"    "<<(air+i)->tkt_amt<<"    "<<(air+i)->tkt_sur<<endl;
		lable:
		i++;
	}
	file_in.close();

	file.open("airline.txt");
	for (int k=0;i<MAXSIZE;i++) 
	{	

		//printf("读取正在航班%d信息(共%d条)",i+1,MAXSIZE);
		//cout<<endl;
		//文件操作
		//读取!
		file>>(air+i)->ter_name>>(air+i)->air_num>>(air+i)->plane_num>>(air+i)->date>>(air+i)->tkt_amt>>(air+i)->tkt_sur;
	}
}

//载入航班信息
void loadairline()
{
	cout<<"现在开始读取航班信息"<<endl;
	fstream file;
	file.open("airline.txt");

	//cin>>(air+i)->ter_name>>(air+i)->air_num>>(air+i)->plane_num>>(air+i)->date>>(air+i)->tkt_amt>>(air+i)->tkt_sur;

	//for (int i=0;i<MAXSIZE;i++) 
	//{	
	//	//清零! 
	//	(air+i)->ter_name = "  ";
	//	
	//}
	for (int i=0;i<MAXSIZE;i++) 
	{	

		printf("读取正在航班%d信息(共%d条)",i+1,MAXSIZE);
		cout<<endl;
		//文件操作
		//读取!
		file>>(air+i)->ter_name>>(air+i)->air_num>>(air+i)->plane_num>>(air+i)->date>>(air+i)->tkt_amt>>(air+i)->tkt_sur;
	}
	cout<<"读取完成!"<<endl;
}
void Read_Airline();
void Save_Information();
void menu_select()
/*菜单界面*/
{
	char menu_select;
	cout<<"         ~~~~~~~~~☆☆☆☆☆航空客运订票系统☆☆☆☆☆~~~~~~~"<<endl;
	cout<<"如果您已经录入了航班信息请输入 8 从文件载入，您也可以输入 7 设定新的航班信息"<<endl;
	cout<<"**********************************************************************"<<endl;
	cout<<"                           1.浏览航线信息"<<endl;
	cout<<"                           2.浏览已订票客户信息"<<endl;
	cout<<"                           3.查询航线"<<endl;
	cout<<"                           4.办理订票业务"<<endl;
	cout<<"                           5.办理退票业务"<<endl;
	cout<<"                           6.查看剩余票数并排序"<<endl;
	cout<<"                           7.设定航班信息"<<endl;
	cout<<"                           8.载入航班信息"<<endl;
	cout<<"                           9.删除航班信息"<<endl;
	cout<<"                           0.退出系统"<<endl;
	cout<<"**********************************************************************"<<endl;
lable:
	cout<<"请选择"<<endl;
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
		cout<<"欢迎使用本系统，再见！"<<endl;
		exit(0);
	}
	else
	{
		goto lable;
	}
}
//保存输入航班的信息
void Save_Information()
{
   FILE *fp;
   int i=0;
   if((fp=fopen("user.txt","wb"))==NULL){
      printf("打开失败！\n");
	  return;
   }
   while(i<MAXSIZE){
	fwrite(&air[i],sizeof(struct airline),1,fp);
     i++;
   }
   fclose(fp);
}
//用户界面
void commenu_select(){
	char menu_select;
	cout<<"        航空客运订票系统"<<endl;
	cout<<"******************************************"<<endl;
	cout<<"       1.浏览航线信息"<<endl;
	cout<<"       2.查询航线"<<endl;
	cout<<"       3.办理订票业务"<<endl;
	cout<<"       4.办理退票业务"<<endl;
	cout<<"       0.退出系统"<<endl;
	cout<<"*******************************************"<<endl;
lable:
	cout<<"请选择"<<endl;
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
		cout<<"欢迎使用本系统，再见！"<<endl;
		exit(0);
	}
	else
	{
		goto lable;
	}
}
/*********************管理员登入*********************************/
void AdEnter(){
    char n[8],m1[10],m;
    char flag;
	int k1=0,pw=0;
    FILE *fp;
    ad a;
	k1=0;
	pw=0; 
    cout<<"\n\t\t\t请输入账号：";
    cin>>n;
    if((fp=fopen("adfile.txt","rb"))==NULL){
         cout<<"无法打开文件"<<endl;
           exit(0);
    }
    while(fread(&a,sizeof(ad),1,fp)==1){
         if(strcmp(n,a.Enternum)==0){
			 pw=1;
         cout<<"\t\t\t请输入密码：";
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
	      cout<<"\t\t""密码不能为空，请重新输入"<<endl;
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
                cout<<"密码错误,请按任意键返回\n";
                system("pause");
                system("cls");                    
                break;
           }
		  break;
		 }
		 
		}
        if(pw!=1){
              system("cls");
              cout<<"帐号不存在,按任意键返回\n";
              system("pause");
              system("cls");
         }
		  fclose(fp);
}
/*********************用户登入界面*********************************************************/
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
         cout<<"\t\t\t请输入账号：";
         cin>>n;
         if((fp=fopen("com.txt","rb+"))==NULL){
              cout<<"无法打开文件"<<endl;
              exit(0);
         }
         while(i<num.comnum){
			  re=fread(&c,sizeof(c),1,fp);
              if(strcmp(n,c.EnterNum)==0){
				     pw=1;
                     cout<<"\t\t\t请输入密码：";
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
			             cout<<"\t\t""密码不能为空，请重新输入"<<endl;
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
                         cout<<"密码错误,请按任意键返回\n";
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
              cout<<"帐号不存在,按任意键返回\n";
              system("pause");
              system("cls");
          }
		  fclose(fp);
		  fclose(fd);
}
/*********************注册管理员信息*************************************/
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
	 cout<<"\n\n************************注册管理员信息************************\n\n";
     i=0;
	 strcpy(a1.Enternum,"admin");	
	 cout<<"\t\t账号："<<a1.Enternum<<endl;      
     cout<<"\n\t\t输入姓名：";     cin>>a1.name;
     cout<<"\n\t\t输入性别：";     cin>>a1.sex;
     cout<<"\n\t\t输入年龄：";     cin>>a1.age;
l2:	 cout<<"\n\t\t输入密码：";
	 k1=0;
	 k2=0;
     do{
		fflush(stdin);	  //清洗流，以妨碍密码的正确输入
		for(m=getch();m!=13&&k1<10;m=getch()){
		//若用户输入回车则结束密码输入   
			if (m==8 ) /*若用户按了退格键则……*/ 
			{ 
				if (k1>0 ) /*如果已显示星数不为0则……*/ 
				{ 
					printf("\b"); /*退一个格*/ 
					m1[--k1]='\0'; /*password[i-1]的值改为'\0', 已显示星数减一,数组索引值减一*/ 
				} 
				putchar(0); /*显示空字符*/ 
				printf("\b"); /*退一个格*/ 
				continue ; 
			}       
			if( m<32 || m>127 )
				continue; /*密码只能为ASCII码值为32-127的字符,保证只能输入字母数组*/ 
		
			printf("*"); /*上述情况都不是则显示一个星*/ 

			m1[k1++] = m; /*将ch赋给password[i],已显示星数加一,数组索引值加一*/  
		}
		m1[k1] = '\0'; /*设置结尾的空字符*/ 
		if(m1[0]=='\0')
			cout<<"\t\t""密码不能为空，请重新输入"<<endl;
		fflush(stdin);
	}while(m1[0]=='\0');
	cout<<"\n\n\t\t确认密码：";
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
			cout<<"\t\t""密码不能为空，请重新输入"<<endl;
		fflush(stdin);
	}while(m2[0]=='\0');
	 if(strcmp(m1,m2)==0)   strcpy(a1.key,m1);
	 else {
		 cout<<"\t\t密码不匹配请重新输入！\n";
		 goto l2;
	 }
     do{
		cout<<"\n\n\t\t是否确定输入？（Y/N）";
		cin>>ch;
	}while(ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N');
	if(ch=='y'||ch=='Y'){
		fseek(fp,0,2);
		fwrite(&a1,sizeof(a1),1,fp);
		num.adnum++;
		fseek(fp,0,0);
		system("cls");
		cout<<"添加成功！"<<endl;
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
/*********************注册用户*****************************************/
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
	 cout<<"\n\n************************注册用户信息************************\n\n";
     i=0;	
	 cout<<"\t\t输入账号（七位）：";  cin>>a1.EnterNum;      
     cout<<"\n\t\t输入姓名：";     cin>>a1.name;	
     cout<<"\n\t\t输入性别：";     cin>>a1.sex;
     cout<<"\n\t\t输入年龄：";     cin>>a1.age;
l2:	 cout<<"\n\t\t输入密码：";
	 k1=0;
	 k2=0;
     do{
		fflush(stdin);	  //清洗流，以妨碍密码的正确输入
		for(m=getch();m!=13&&k1<10;m=getch()){
		//若用户输入回车则结束密码输入   
			if (m==8 ) /*若用户按了退格键则……*/ 
			{ 
				if (k1>0 ) /*如果已显示星数不为0则……*/ 
				{ 
					printf("\b"); /*退一个格*/ 
					m1[--k1]='\0'; /*password[i-1]的值改为'\0', 已显示星数减一,数组索引值减一*/ 
				} 
				putchar(0); /*显示空字符*/ 
				printf("\b"); /*退一个格*/ 
				continue ; 
			}       
			if( m<32 || m>127 )
				continue; /*密码只能为ASCII码值为32-127的字符,保证只能输入字母数组*/ 
		
			printf("*"); /*上述情况都不是则显示一个星*/ 

			m1[k1++] = m; /*将ch赋给password[i],已显示星数加一,数组索引值加一*/  
		}
		m1[k1] = '\0'; /*设置结尾的空字符*/ 
		if(m1[0]=='\0')
			cout<<"\t\t""密码不能为空，请重新输入"<<endl;
		fflush(stdin);
	}while(m1[0]=='\0');
	cout<<"\n\n\t\t确认密码：";
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
			cout<<"\t\t""密码不能为空，请重新输入"<<endl;
		fflush(stdin);
	}while(m2[0]=='\0');
	 if(strcmp(m1,m2)==0)   strcpy(a1.key,m1);
	 else {
		 cout<<"\t\t密码不匹配请重新输入！\n";
		 goto l2;
	 }
     do{
		cout<<"\n\n\t\t是否确定输入？（Y/N）";
		cin>>ch;
	}while(ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N');
	if(ch=='y'||ch=='Y'){
		fseek(fp,0,2);
		fwrite(&a1,sizeof(a1),1,fp);
		num.comnum++;
		fseek(fp,0,0);
		system("cls");
		cout<<"添加成功！"<<endl;
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
/*********************登入*****************************************/
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
cout<<"                   ├──────────────────┤"<<endl; 
cout<<"                   │             1.管理员登录           │"<<endl;
cout<<"                   ├──────────────────┤"<<endl;
cout<<"                   │             2.用户登录             │"<<endl;
cout<<"                   ├──────────────────┤"<<endl;
cout<<"                   │             3.用户注册             │"<<endl;
cout<<"                   ├──────────────────┤"<<endl;
cout<<"                   │             0.退出系统             │"<<endl;
cout<<"                   └──────────────────┘"<<endl;
          do{
            cout<<"请选择：";
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
      printf("打开失败！\n");
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
