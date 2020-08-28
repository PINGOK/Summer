C语言求圆周率π（三种方法）
1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
float s=1;
float pi=0;
float i=1.0;
float n=1.0;
while(fabs(i)>=1e-6){
pi+=i;
n=n+2;
// 这里设计的很巧妙，每次正负号都不一样 
s=-s; 
i=s/n;
}
pi=4*pi;
printf("pi的值为：%.6f\n",pi);

return 0;
}


2
#include <stdio.h>
#include <math.h>
int main(){
    float pi=1;
    float n=1;
    int j;
    for(j=1;j<=100;j++,n++){
        if(j%2==0){
            pi*=(n/(n+1));
        }else{
            pi*=((n+1)/n);
        }
    }
    pi=2*pi;
    printf("pi的值为：%.7f\n",pi);

    return 0;
}



3
#include <stdio.h>
#include <math.h>
int main(){
float term,result=1;
int n;
for(n=2;n<=100;n+=2){
term=(float)(n*n)/((n-1)*(n+1));
result*=term;
}
printf("pi的值为：%f\n", 2*result);
return 0;
}
