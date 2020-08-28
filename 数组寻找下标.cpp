//输入一个正整数n（1<n<=10)，再输入n个整数，将它们存入数组a中 
//1.找出数组的最小值和它对应的下标 
//2.将最小值与第一个数交换，输出交换后的n个数 
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i,n,index=0,temp;//初始化index=0为先另a[0]是最小值 
	int a[10];
	printf("输入你的数字n(1,10]:\n");
	scanf("%d",&n);
	printf("输入要存入数组的n个数字：\n");
	//将输入的数字存入数组中 
    for(i=0;i<n;i++)
	{
    	scanf("%d",&a[i]);   	
	}
	//找到最小的值和它对应的下标并输出 
	for(i=1;i<n;i++)
	{
		if(a[i]<a[index])
		index=i;//交换最小值下标，即a[i]是新的最小值 
	}
	printf("最小值是 %d \t 下标是 %d \n",a[index],index);
	//交换a[index]与a[0]
	temp=a[index];
	a[index]=a[0];
	a[0]=temp;
	//输出交换后的数组 
	printf("将最小值与第一个数交换后的数组：\n"); 
	for(i=0;i<n;i++)
	{
		printf("  %d",a[i]); 
	}
	
	 
	return 0;
}
