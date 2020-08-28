//输入5个整数，将它们存在数组a中，再输入一个数x，然后在数组中查找x
//如果找到，输入相应的最小下标，否则，则提示未找到 
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i,x,flag=0;//flag=0代表未找到 
	int a[5];
	
	printf("请输入5个数：\n");//输入提示
	
	for(i=0;i<5;i++)
	{
	    scanf("%d",&a[i]);
	}
	    printf("请输入要查找的数x\n");
	    scanf("%d",&x);
	for(i=0;i<5;i++)
	{
    	if(a[i]==x)
    	{
        	printf("最小下标应该是%d\n",i);
        	flag=1; 
        	break;	
		}
    }   
    if(flag==0)
   	printf("未找到！\n"); 
   
	return 0;
}
