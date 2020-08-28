//次方求模（快速幂取模算法）
//对于问题：求a的b次方取c的模的值，当a,b很大时，直接求解显然是不太现实的
//但是，这个问题如果使用公式就变得可解，并且容易计算。
//由公式:a^b mod c = (a mod c)^b mod c
<1>递归算法：

#include <stdio.h>
 
long long int fun (long long int a,long long int b,long long int c);
 
int main(void)
{
    long long int a,b,c;
    int n;
    scanf("%d",&n);
    while (n--)
    {
        scanf("%ld%ld%ld",&a,&b,&c);
        printf("%ld\n",fun(a,b,c));
    }
    return 0;
}
 
long long int fun(long long int a,long long int b,long long int c)
{
    long long int ans;
    ans = 1;
    if (b == 0) return 1 % c;
    if (b == 1) return a % c;
    ans = fun(a,b/2,c);
    ans = ans * ans % c;
    if (b % 2 == 1) ans = ans * a % c;
   return ans;
}





<2>循环算法：
#include <stdio.h>
int fun(long long int a,long long int b,long long int c);
int main(void)
{
	int n;
	long long int a,b,c;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%ld%ld%ld",&a,&b,&c);
	     printf("%d\n",fun(a,b,c));
	}
	return 0;
}
 
int fun(long long int a,long long int b,long long int c)
{
	int ans = 1;
	a = a % c;
	while (b > 0)
	{
		if (b % 2 == 1)
		  ans =ans * a % c;
	    a =a * a % c;
    	b /= 2;
	}
	return ans;
}    
