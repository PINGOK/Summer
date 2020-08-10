//康托展开 
//首先，了解什么是康托展开？ 
//康托展开是一个全排列到一个自然数的双射，常用于构建hash表时的空间压缩 
//设有n个数（1,2,3,4,...,n),可以有组成不同（n！种）的排列组合
//康托展开表示的就是当前排列组合在n个不同元素的全排列中的名次
//原理：
//S=a[n]*(n-1)!+a[n-1]*(n-2)!+....+a[i]*(i-1)!+...+a[1]*0!
//其中，a[i]为整数，且0<=a[i]<=i,0<=i<n
//表示当前元素排第几个，这就是康托展开 

//举例说明：比如34152的康托展开式为：
//首位3在所有未出现的数字中排第3 (1,2)
//所以a[5]=2 (小于3的有2个)
//第二位4在所有未出现的数字中排第三(1,2)
//所以a[4]=2 (小于4的有2个)
//同理a[3]=0 a[2]=1 a[2]=0
//X=a[5](5-1)!+a[4](4-1)!+a[3](3-1)!+a[2](2-1)!+a[1](7-1)!
//X=24!+23!+02! +11 ! +00!
//X=61
//那么在341 52小的全排列有61个，那么341 52排在全排列的第62个。
//康托展开就是上述的描述。

#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */ 
//此函数为生成1到n的阶乘表
int jiecheng(int n)
{
	if(n<=1)
    	return 1;
	else 
    	return (jiecheng(n-1)*n);

 } 

int main(int argc, char *argv[]) {
	int count=0,i=0,j=0,k=0,sum=0;
	int n[100];
	char s[100];
	char input;
	//获取所有的元素：1,2,3,4..... 
	printf("请输入你的数字(位数在100以内）:\n");
	while(scanf("%c",&input))
	{
	     if(input=='\n')  break;
             else
            {
        	s[count]=input;
        	count++;
	    }
	}
	printf("您输入的数字一共%d位数\n\n",count);
	//求元素的排序：例如第一个元素需要和剩下的n-1个比较
	//第二个要和剩下的n-2个元素比较，以此类推...
	for(i=0;i<count;i++)
	{
		printf("第%d个元素是%c\n",i+1,s[i]);
		for(j=i+1;j<count;j++)//开始比较
		{
			  if(s[i]>s[j])
		   	{   printf("在所有未出现的数字比它小的有%d个 \n分别是%c\t%c\n",j,s[i],s[j]);
			    	k++;
		   	}
		 } 
		printf("小于这个数的有%d个，所以展开式中n[%d]的值为%d\n\n",k,i,k);
		n[i]=k;//小于这个数的有k个，所以n[i]=k 
		k=0;
	 } 
	//输出结果：输入的数是全排列中第几个大的数
	for(j=count-1;j>=0;j--)
	{
		sum+=jiecheng(j)*n[k];
		printf("第%d次：sum=n[%d]*(%d)!=%d*%d=%d\n\n",k,k,k-1,jiecheng(j),n[k],sum);
		k++;
	 } 
	 printf("那么比这个数小的全排列有%d个，那这个数排在全排列的第%d个。\n因此这个数是第%d大的数\n",sum,sum+1,sum+1);
	return 0;
}
