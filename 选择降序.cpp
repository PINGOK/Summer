// 选择降序
//以序列首元素为基准位置
//每次将其与后面元素依次比较
//挑选最大或最小的那个数在基准位置上
//比较结束后，将基准位置设置为该位置的下一个位置
//重复上述操作
//直到基准位置为最后一个位置结束，此时序列排列完成 

#include "stdafx.h"

int main(int argc, char* argv[])
{
	int i,j,index,temp,a[10];
	printf("enter 10 numbers:");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(j=0;j<9;j++)
	{
		index=j;
		for(i=j+1;i<10;i++)
			if(a[i]<a[index])//比较平均成绩
				index=i;
			temp=a[index];//交换数组元素 
			a[index]=a[j];
			a[j]=temp;
	}
	//输出排序后的信息 
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");

	return 0;
}
