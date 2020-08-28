//假设一对兔子的成熟期是一个月，即一个月可长成成兔
//那么，如果每对成兔每个月都生一对小兔，一对新生的小兔从第二个月起就开始生兔子，试问从一对兔子开始繁殖，以后每个月会有多少对兔子？
#include <stdio.h>
int main()
{
    int i,tu1,tu2,tu3,m;
    tu1=1;
    tu2=1;
    printf("请输入月份数\n");
    scanf("%d",&m);
    if(m==1||m==2)
    {
        printf("有一对兔子");
    }
    else if(m>2)
    {
        for(i=3;i<=m;i++)
        {
            tu3=tu1+tu2;
            tu1=tu2;
            tu2=tu3;
        }
        printf("%d 月的兔子数为：%d\n",m,tu3);
    }
    return 0;
}
