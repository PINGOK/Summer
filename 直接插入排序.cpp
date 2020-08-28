//直接插入排序
//基本思想：
//和交换排序不同的是它不用进行交换操作，而是用一个临时变量存储当前值。
//当前面的元素比后面大时
//先把后面的元素存入临时变量，前面的元素的值放到后面元素位置
//再到最后把其值插入到合适的数组位置 

#include "stdio.h"

void InsertSort(int *a,int n)
{
	int tmp=0;
	for(int i=1;i<n;i++)
	{
		int j=i-1;
		if(a[i]<a[j])
		{
			tmp=a[i];
			a[i]=a[j];
			while(tmp<a[j-1])
			{
				a[j]=a[j-1];
				j--;
			}
			a[j]=tmp;
		}
	}
}
int main(int argc, char* argv[])
{
	int a[]={11,7,9,22,10,18,4,43,5,1,32};
	int n=sizeof(a)/sizeof(int);
	InsertSort(a,n);
	printf("排序好的数组为：\n");
	for(int i=0;i<n;i++){
		printf("  %d ",a[i]);
	}
	printf("\n");
	return 0;
}
