#include <iostream>
#include "stdlib.h"
#include "stdafx.h"
#include "string.h"
struct emp 
{
	char name[20];
	char gender[10];
	int num;
	int salary;
	struct emp *next;
};
//定义一个链表头和一个链表尾
struct emp *Head;//作为全局变量
struct emp *End;
FILE *fp;

void Exit();//退出程序
void InputEmp();//输入职工信息 
void DisplayEmp();
void WriteToFile();
void ReadFromFile();
void Query ();
void Dismiss();
void ChangeEmp();

int main(int argc, char* argv[])
{
	Head=(struct emp*)malloc(sizeof(struct emp));
//	End=(struct emp*)malloc(sizeof(emp));
    Head->next=NULL;
    End=Head;
    
	int selection;
	system("color f0");  
	while(1)
	{
		printf(" \t\t\t\t        职工管理系统--作者：XXX  版权所有\n");
        printf("\t===========================================================================================================\n");
        printf(" \t\t\t    1: 从文件载入职工信息：读文件             2: 保存职工信息：写文件\n");  
        printf("\t\t \t    3: 添加职工信息                           4: 删除职工信息\n");
        printf("\t\t \t    5: 修改职工信息                           6: 查询职工信息\n");
        printf("\t\t \t    7: 浏览职工信息\n");
        printf("\t\t \t    0: 退出程序\n");
        printf("\t===========================================================================================================\n");
        printf("\t\t \t       请选择:");
	    scanf("%d",&selection);
		switch(selection)
		{
		case 0:Exit();break;
		case 1:ReadFromFile();break;
			
	    case 2:WriteToFile();break;
			
		case 3:InputEmp();break;
		
		case 4:Dismiss();break;
		
		case 5:ChangeEmp();break;
				
		case 6:Query ();break;
			
		case 7:DisplayEmp();break;
		default: ;

		}
	system("cls");//清理屏幕
	}
    
	return 0;
}
void ChangeEmp()
{
	
	int WokerNum;
	struct emp *p;
	char sure[2];
	

	if(Head==End)//若空 
	
	printf("链表中没有数据\n");
	else
	{
    	printf("请输入要修改的职工号：\n");
	    scanf("%d",&WokerNum);
    	p=Head->next;//p指向第一个有效节点 
	    while((p!=NULL)&&(p->num!=WokerNum))
        p=p->next;//p往后移 
        if(p==NULL)
		printf("对不起，该职工号不存在\n");
    	else
         {
        	printf("\n\n\n     \t\t\t\t\t         职工信息如下    \n\n");
 	        printf("      \t\t\t\t       工号     姓名    性别     工资\n");
            printf("     \t\t\t\t      %3d      %3s      %3s      %3d\n",p->num,p->name,p->gender,p->salary);
            printf("\n\n确认修改%d的职工信息 ?(y/n):",p->num);
	        scanf("%s",sure);
	            if((sure[0]=='y')||(sure[0]=='Y'))
	            {
	             printf("姓名:");
   	             scanf("%s",p->name);
                 printf("性别:");
	             scanf("%s",p->gender);
                 printf("工资:");
	             scanf("%d",&p->salary);
	             printf("修改成功！\n");
		        }
	
         }
   }
    system("pause");
    return;
	
}
void QueryByNum()
{
	int WokerNum;
	struct emp *p;
	printf("请输入要查询的职工号：\n");
	scanf("%d",&WokerNum);
	p=Head->next;//p指向第一个有效节点 
	while((p!=NULL)&&(p->num!=WokerNum))
    p=p->next;//p往后移 

    if(p==NULL)
    	printf("对不起，该职工号不存在\n");
   	else
    {
       	printf("\n\n\n     \t\t\t\t\t         职工信息如下    \n\n");
    	printf("      \t\t\t\t       工号     姓名    性别     工资\n");
        printf("     \t\t\t\t      %3d      %3s      %3s      %3d\n",p->num,p->name,p->gender,p->salary);
    }
 } 
 void QuerySalary()
{
	int minsalary,maxsalary;
	int count=0;//计数器 
	struct emp *p;
	printf("请输入要查询的工资下限和上限：\n");
	scanf("%d%d",&minsalary,&maxsalary);
	p=Head->next;//p指向第一个有效节点 
	while(p!=NULL)
    {      
        	if((p->salary>=minsalary)&&(p->salary<=maxsalary))
        	{ 
        	count++;
			if(count==1)
			{
        	    printf("\n\n\n     \t\t\t\t\t         职工信息如下    \n\n");
        	    printf("      \t\t\t\t       工号     姓名    性别     工资\n");
            }
            printf("     \t\t\t\t      %3d      %3s      %3s      %3d\n",p->num,p->name,p->gender,p->salary);
           
            }
            
            p=p->next;//p往后移 
    
	}
	printf("一共找着了%d个记录。\n",count);
 } 
void Query ()
{
	int selection;
	printf("\n\n\t1-按职工号查询     \t\t2-按工资范围查询\n");
	
    scanf("%d",&selection);
    switch(selection)
    {
    	case 1: QueryByNum();break;
    	case 2: QuerySalary();break;
    	default: ;
	}
	system("pause");
		
}
void ReadFromFile()
{   
    struct emp *p,*q;
    char sure[2];
   
   	printf("Are you sure ?(y/n):");
	
	scanf("%s",sure);
	if((sure[0]=='n')||(sure[0]=='N'))
	return;
	
    if(Head!=End) //清除链表的节点 
    {   //节点不为空（当Head=End时为空）
    	p=Head->next;
    	while(p!=NULL)
    	{//用q记住p的下一个的节点
		q=p->next;
		free(p); 
		p=q;
		//知道p为空
		End=Head;
		End->next=NULL;    		
		}
	 } 
    
	if((fp=fopen("emp.txt","r"))==NULL)
	{
		printf("打开文件失败！\n");
		system("pause");
		return;
	 } 
	 
	while(!feof(fp))
    {
	  p=(struct emp*)malloc (sizeof(struct emp));//创建一个节点
	  fscanf(fp,"%d%s%s%d",&p->num,p->name,p->gender,&p->salary);
	  End->next=p;//把节点p插入到链表的尾部
	  End=p;
	  End->next=NULL; 
	}	
	
	fclose(fp);
	printf("读文件成功！\n");
	system("pause");
}
void WriteToFile()
{
	struct emp *p;
	char sure[2];
	
	printf("Are you sure?(y/n):");
	scanf("%s",sure);
	if((sure[0]=='n')||(sure[0]=='N'))
	return;
	
	if((fp=fopen("emp.txt","w"))==NULL)
	{printf("Open file failure.\n");
	system("pause");
	return;
    }
	p=Head->next;
	while(p!=NULL){
	fprintf(fp,"\n%d %s %s %d",p->num,p->name,p->gender,p->salary);
	p=p->next;
    }
	fclose(fp);		
	printf("Write file successfully.\n");
	system("pause");
}
void InputEmp()
{
	struct emp *p,*q;
	int WorkNum;
	bool Repeat;//表示不重复 
	
	
	do{
		
	  do{
	  printf("工号(0=return):");
	  scanf("%d",&WorkNum);
	  if(WorkNum==0)return;//职工号为0则退出 
	  else
	  {
	  	Repeat=0;
	  	q=Head->next;
	  	while(q!=NULL)
	  	 {
	  		if( q->num==WorkNum)//如果它重复了
	  		{
			  Repeat=1;//Repeat赋值为1，ture 
	  		  printf("Emp Num repeated,Please Reinput.\n");
			}
			q=q->next;
			  
		 }
	  }
     }while(Repeat);// Repeat为真时继续循环 
	 
	
  	  p=(struct emp*)malloc (sizeof(struct emp));
  	  p->num=WorkNum;
  	  
	  printf("姓名:");
   	  scanf("%s",p->name);
      printf("性别:");
	  scanf("%s",p->gender);
     
      printf("工资:");
	  scanf("%d",&p->salary);
	//把这些记录插入链表头

/*	p->next=Head;
	Head=p;添加到链表头*/
	//一般是加到链表尾
	  End->next=p;//把节点p插入到链表的尾部
	  End=p;
	  End->next=NULL; 
     }while(1);
	 

}
void Dismiss(){
	int WokerNum;
	struct emp *p,*q;
	char sure[2];
	printf("请输入要删除的职工号：\n");
	scanf("%d",&WokerNum);
	p=Head->next;//p指向第一个有效节点 
	while((p!=NULL)&&(p->num!=WokerNum))  
    p=p->next;//p往后移 
    
    if(p==NULL)
    
    	printf("对不起，该职工号不存在\n");
   	else
    {
        printf("\n\n\t\t\t\t\t\t  职工信息如下:    \n\n\n");
    	printf("         \t\t\t        工号    姓名    性别     工资\n");
        printf("     \t\t\t\t      %3d      %3s      %3s      %3d\n",p->num,p->name,p->gender,p->salary);
        
        printf("\n\n\t\tAre you sure to delete the employee?(y/n)\n");
        scanf("%s",sure);
        if((sure[0]=='Y')||(sure[0]=='y'))
        {
            q=Head;
        	while(q->next!=p)
        		q=q->next;
        		q->next=p->next;//q的下一个节点跳过p 
        		if(End==p)	End=q;        	
				free(p);
				printf("已删除\n");
		}
        
     }
    system("pause");
}
void DisplayEmp()
{
	struct emp *p;
	p=Head->next;
	getchar();
	printf("\n\n\n     \t\t\t\t\t         职工信息如下    \n\n");
	printf("      \t\t\t\t       工号     姓名    性别     工资\n");
	while(p!=NULL)
	{
    printf("     \t\t\t\t      %3d      %3s      %3s      %3d\n",p->num,p->name,p->gender,p->salary);
		//输出一个人 
        p=p->next;
	}
	getchar();//getchar();一个也行 
}
void Exit()
{
	char sure;
	printf("Are you sure to exit?(y/n):");
	getchar();
	scanf("%c",&sure);
	if((sure=='Y')||(sure=='y'))
			exit(0);
			return;
				}
