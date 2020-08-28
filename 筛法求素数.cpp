//基本思想:
///用筛法求素数的基本思想是:
//把从1开始的、某一范围内的正整数从小到大顺序排列，
//1不是素数，首先把它筛掉
//剩下的数中选择最小的数是素数，然后去掉它的倍数
//依次类推，直到筛子为空时结束

#include <stdio.h>
#include <stdlib.h>
#define N 1000
 
int main(void)
{
    int i,j;
    int prime[N+1];
 
    for(i=2;i<=N;i++)
        prime[i]=1;
    for(i=2;i*i<N;i++)// 只能被1和自己整除的数才是质数，只要判断到此数的平方根即可 
    {
        if(prime[i]==1)
        {
            for(j=2*i;j<=N;j++)//对上述范围内的每一个数字，找出其倍数，并将相应的数组项 =0，表示不是质数
            {
                if(j%i==0)
                    prime[j]=0;
            }
        }
    }
 //输出 
    for(i=2;i<N;i++)
    {
        if(prime[i]==1)
        {
            printf("%4d",i);
            //换行 
            if(i%16==0)
                printf("\n");
        }
    }
    printf("\n");
    return 0;
}
