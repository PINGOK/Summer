//整数逆序输出

//将一个从键盘输入的整数存放到一个数组中，通过程序的运行按照数组中的逆序输出该整数，利用递归的方法解决问题。
//设计函数实现数据的逆序存放，设定形参数组接收实参数组的地址，来存储数据的每一位
//函数体采用递归的方式解决问题，因此考虑递归进行的条件
//例如，把数据 n 存放到数组 s 中，若 n 是一位数，则存放 n 到数组中；若 n 不是一位数，则存放 n/10 到数组中。

//问题解决的难点在于找到数据的存放地址，通过不断地取余和整除 10 来得到数据的每一位
//为了实现数据的逆序存放，每一次整除 10 的时候，同时把存放数据的数组地址后移
//这样得到的第一位数存放在数组的最后一位……通过依次前移，即递归的回归，实现整个数据的存放。通过函数 convert() 实现字符串中的数字的逆序转换。

#include <stdio.h>
int convert(char s[],int n)
{
    int i;
    if((i=n/10)!=0)
         convert(s+1,i);
    *s=n%10+'0';
    return 0;
}

int main()
{
    int num;
    char str[10]=" ";
    printf("input integer data：");
    scanf("%d",&num);
    convert(str,num);
    printf("output string：\n");
    puts(str);
    return 0;
}
