//计算某个日期对应该年的第几天 

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int day_of_year(int year,int month,int day)
{
	int k,leap;
	int lab[2][13]={
	{0,31,28,31,30,31,30,31,30,31,31,30,31,30,31},
	{0,31,28,31,30,31,30,31,30,31,31,30,31,30,31}
	};
	//判断是否为闰年，闰年时leap=1，非闰年时leap=0
	leap=(year%4==0&&year%100!=0||year%400==0);
	//计算天数
	for(k=1;k<month;k++)
	day+=lab[leap][k];
	return day;
	 
}
int main(int argc, char *argv[]) {
	int year,month,day,a;
	printf("please input your date:\n");
	scanf("%d%d%d",&year,&month,&day);
	a=day_of_year(year,month,day);
	printf("对应该年的第%d天：\n",a);
	return 0;
}
