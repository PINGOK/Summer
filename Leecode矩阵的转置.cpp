//矩阵的转置 
//输入一个正整数n(1<n<=6),根据下式生成一个n*n的方阵，将该方阵转置（行列互换）后输出。 
//a[i][j]=i*n+j+1(0<=i<=n-1,0<=j<=n-1)

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i,j,n,temp;
	int a[6][6];
	printf("enter n:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	    for(j=0;j<n;j++)	
    	    a[i][j]=i*n+j+1;//赋值
	//行列互换
	for(i=0;i<n;i++)
	    for(j=0;j<n;j++)	 
	    if(i<=j){//只遍历上三角阵 
	    	temp=a[i][j];
	    	a[i][j]=a[j][i];
	    	a[j][i]=temp;
		}
	//按矩阵的形式输出a
	for(i=0;i<n;i++){
	    for(j=0;j<n;j++) 
	      printf("%4d",a[i][j]);
	    printf("\n");
	 }
	return 0;
}
