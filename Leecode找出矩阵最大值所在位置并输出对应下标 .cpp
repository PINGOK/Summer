//找出矩阵最大值所在位置并输出对应下标 

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int col,j,i,row;
	int a[3][2];
	//将输入的数存入二维数组中
	printf("input your number(6):\n");
	for(i=0;i<3;i++)
	    for(j=0;j<2;j++)
        	scanf("%d",&a[i][j]);
	//按矩阵的形式输出二维数组
    for(i=0;i<3;i++){
	    for(j=0;j<2;j++)
	        printf("%4d",a[i][j]);
    	printf("\n");
	}
	//遍历二维数组，找出最大值a[row][col]
	row=col=0;
	for(i=0;i<3;i++)
	for(j=0;j<2;j++)
		if(a[i][j]>a[row][col])
		{
		row=i;
		col=j;
    	}
    printf("max=a[%d][%d]=%d\n",row,col,a[row][col]);
	return 0;
}
