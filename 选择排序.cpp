//选择法排序：
//输入一个正整数n(1<n<=10),再输入n个整数，用选择排序法将它们从小到大排序后输出 

//步骤：
//1.在未排序的n个数(a[0]~a[n-1])中找到最小的数，将它与a[0]交换；
//2.在剩下的为排序的n-1个数(a[1]~a[n-1])中找到最小的数，将它与a[1]交换；
//......
//n-1.在剩下未排序的两个数(a[n-2]~a[n-1])中找到最小数，将它与a[n-2]交换
 
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i,index,k,n,temp;
	int a[10];//定义一个数组，它有10个整型元素
	printf("输入n:\n");
	scanf("%d",&n);
	printf("输入n个数：\n");
	// 将输入的数依次赋值给数组a中的n个元素a[0]~a[n-1]
    for(i=0;i<n;i++)
	{
    	scanf("%d",&a[i]);   	
	}
	//对n个数进行排序
	for(k=0;k<n-1;k++)//最小值在0~n-2之间
	{
		index=k;
		for(i=k+1;i<n;i++)//寻找最小值所在下标
		{
			if(a[i]<a[index])//发现新的最小值就交换 
	        	index=i;
	    } 
	        	//最小值与下标为k的元素交换 
	    temp=a[index];
        a[index]=a[k];
        a[k]=temp;   	
    } 
    printf("排序后的数组：\n");
    for(i=0;i<n;i++)
    {
    	printf("   %d",a[i]);
	}
    
	return 0;
}
