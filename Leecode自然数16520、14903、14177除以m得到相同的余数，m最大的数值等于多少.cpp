//自然数16520、14903、14177除以m得到相同的余数，m最大的数值等于多少？

//对于同一个除数，如果两个整数同余，那么他们的差就一定能被这个数整除
//三个数字比较大，但是他们对于m同余，那么当中任意两个数字的差必然是m倍数，要求m的最大的数值可以转化位求他们的三个差的最大公约数，从而降低计算的难度
//6520-14903=1617=3×7的平方×11，16520-14177=2343=3×11×71，//14903-14177=726=2×3×11的平方，三个差的最大公约数是3×11=33,m的最大数字等于33.

//思路比较简单：
//第一步：输入三个数
//第二部：求三个数的差
//第三部：先求前两个数的最大公约数t,再求t和第三个数的最大公约数（求最大公余数可借助辗转相除法）
//以下代码适合求n个大数的最大m值：

#include<stdio.h>
#define Max 100
int num[Max];//存储三个大数
int val[Max];//存储排序后的三个大数
int End[Max];//存储三个数相减的差
int n,i;
void init(int num[],int * n)
{
	int i = 0;
	printf("请输入元素的个数：");
	scanf("%d",n);
	for(i=0;i<*n;i++)
	{
		printf("请输入第%d个元素：",i+1);
		scanf("%d",&num[i]);
	}
}
	//辗转相除法求余数
int qiuYushu(int a,int b)
{
	int r = a % b;
	if(r==0)
	return b;
	else
	return qiuYushu(b,r);
}
 
void function(int num[],int n)
{
.
	int i = 0,j = 0,k = 0;
	//val中存储的是这几个大数做减法的差值
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			val[k] = num[i] - num[j];
			if(val[k]>0)
			val[k] = val[k];
			else
				val[k] = 0 - val[k];
			k++;
		}
	}
	//求val[0]和val[1]求最大公约数，然后再对t和val[i](i>=2)求最大公约数，一直到最后一个，得出val数组中的最大公约数即为所求！
	int t = qiuYushu(val[0],val[1]);
	for(i=2;i<n;i++)
	{
		t = qiuYushu(val[i],t);
	}
	printf("%d是这%d个数的最大m\n",t,n);
}
 
 
 
int main()
{
	init(num,&n);
 
	function(num,n);
 
	return 0;
}
