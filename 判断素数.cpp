//判断素数
//
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	int i,m,j;
	int count=0;
	printf("Enter a number:\n");
	scanf("%d",&m);
	printf("\n在0-您输入的数中间有这些素数： \n"); 
	for(j=2;j<=m;j++)//从0到m间每个数需要进行是否为素数的判断
	{ 
    	    for(i=2;i<=j/2;i++)//取值范围可以缩小为[2，j/2]，数学上证明，还可以是[2，（j）^(1/2)] 
    	    {
		if(j%i==0)	break;//若j能被某个i整除，则j不是素数，提前结束循环
	    }	
	    if(i>j/2)
	    {
	 	// 若循环正常结束，则说明j不能被任一个i整除 
     	    printf("%6d   ",j);//则输出素数j，最大位数定为6 
            count++;
	    if(count%5==0)
                { 
         	 printf("\n");//满足五个数一行就转行 
        	} 
            }
        }
	return 0;
}
