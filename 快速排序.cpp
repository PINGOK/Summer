//快速排序 
//算法描述：
//取排序中的任一元素作为基准值
//将待排序集合分割成两个子序列
//左边的序列比基准值小，右边的序列比基准值大
//然后对左右子序列重复上述步骤，直到排完为止 

#include "stdio.h"
void swap(int *x,int *y)
{
	int ret=*x;
	*x=*y;
	*y=ret;
}
//分治法把数组分成两份
int patition(int *a,int left,int right)
{
	int j=left;//用来遍历数组
	int i=j-1;//用来指向小于基准元素的位置
	int key=a[right];//基准元素
	//从左到右遍历数组，小于基准的放左边，反之放右边
	for(;j<right;++j)
	{
		if(a[j]<=key)
	    	swap(&a[j],&a[++i]);
	 } 
	 //把基准元素放中间
	 swap(&a[right],&a[++i]);
	
	//返回数组中间位置
	return i; 
}

//快速排序
void quickSort(int *a,int left,int right)
{
	if(left>=right)
    	return;
	int mid=patition(a,left,right);
	quickSort(a,left,mid-1);
	quickSort(a,mid+1,right);
 } 
 
 
int main(int argc, char* argv[])
{
	int a[]={10,6,5,7,12,8,1,3,11,4,2,9,16,13,15,14};
	int n=sizeof(a)/sizeof(int);
	quickSort(a,0,n-1);
	printf("排序好的数组为：\n");
	for(int l=0;l<n;l++)
	{
	    printf("%d ",a[l]);
	} 
	printf("\n");

	return 0;
}
