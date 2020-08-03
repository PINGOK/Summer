#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b,y;
	int c=0;
	printf("please input your numbers(2):\n");
	scanf("%d%d",&a,&b);
	y=a*b;
	if(a<=b){
		a=a+b;
		b=a-b;
		a=a-b;
	}
	while(a%b)
	{
		c=a%b;
		a=b;
		b=c;
	}
	y=y/b;
	printf("最大公约数是：%d,最小公倍数是：%d",b,y);
	return 0;
}
