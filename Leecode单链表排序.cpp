//已知一个正整数组成的无序序列，个数未知，但至少有一个元素
//你的任务是建立一个单链表，并使用该链表存储这个正整数序列
//然后将这个链表进行排序，使得排序后的链表为递增序列。

//但必须是通过修改结点的指针域来进行排序，而不是对结点的数据域进行修改

//你的任务是建立一个单链表，并使用该链表存储这个正整数序列
//然后将这个链表进行排序，使得排序后的链表为递增序列。
//正整数的输入用-1作为结束标志，注意-1不算这个正整数序列中的元素（不要统计-1）。
//在排序的过程中，你可以自己选择排序算法
//输入与输出要求:注意最后一个元素后只有换行符。
//程序运行效果:输出经过排序后的链表，每个元素后有一个空格已知一个正整数组成的无序序列。程序结束后要释放所有节点占据的空间，个数未知，但至少有一个元素 

#include<stdio.h>
#include<stdlib.h>
struct  node{  //链表的节点
          struct node *pnext;
          int data;
};
struct node *create()//创建链表
{
          struct node *phead=0,*ptail=0,*ptmp;
          int ele;
          printf("Please input a list(end by -1):\t");
          scanf("%d",&ele);
          while(ele!=-1)
          {
                    ptmp=(struct node*)malloc(sizeof(struct node));
                    ptmp->data=ele;
                    ptmp->pnext=NULL;
                    //接入链表，该链表是不带头结点的链表
                    if(phead==NULL)//接入第一个节点
                              phead=ptail=ptmp;
                    else//接入第二个节点
                    {
                              ptail->pnext=ptmp;
                              ptail=ptmp;
                    }
                    scanf("%d",&ele);
          }
          return phead;
}
void sort(struct node *p)//根据节点的数据域对链表节点进行冒泡排序
{
          struct node* pt=p->pnext;
          struct node*ptmp=p;
          struct node* ptag=NULL;
          int tmp;
         while(pt!=NULL)
          {
                    for(ptmp=p;ptmp->pnext!=ptag;ptmp=ptmp->pnext)
                    {
                              if(ptmp->data > ptmp->pnext->data)//数据交换
                              {
                                        tmp=ptmp->data;
                                        ptmp->data=ptmp->pnext->data;
                                        ptmp->pnext->data=tmp;
                              }
                    }
                    ptag=ptmp->pnext;
                    pt=pt->pnext;
          }
}
void list(struct node* p)//输出链表
{
          struct node *ptmp=p;
          printf("The new list is:");
          while(ptmp->pnext!=NULL)
          {
                    printf("%d ",ptmp->data); //输出非最后一个元素，留出空格
                    ptmp=ptmp->pnext;
          }
          printf("%d\n",ptmp->data); //输出最还一个元素,并换行
}
int  main()
{
          struct node* pint;
          pint=create();
          sort(pint);
          list(pint);
          return 0;
}
