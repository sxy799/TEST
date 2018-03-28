#include <math.h>
#include "unit.h"
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

double newton_sqrt(double n)
{
    if (n < 0) {
        printf("你输入的数是负数不能被开平方\n");
        return 0.0;

    }
    double x = 1.0;
    while(fabs(x * x - n) > EPSLON)
    {
        x = x - (x * x - n) / (2 * x);
    }
    return x;
}


int get_sum(int n)
{
    if (n <= 0)  {  printf(" 您输入的n 是负数 不符合我们的要求 \n");  return 0;}
   // if (n > INT_MAX) { printf("输入的数字超过int最大值不在判断的范围\n");return 0; }
    int sum = 0;
    for (int i=1; i < n; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
          // printf(" ****  %d \n",i);
            sum += i;
        } 
    }                        
    return sum;
}
int IsPrime(int n)
{
    if (n <= 0)  {  printf(" 您输入的n 是负数 不符合我们的要求 \n");  return 0;}
   // if (n > INT_MAX) { printf("输入的数字超过INT_MAX 不在判断的范围\n"); return 0;}
    for (int i =2; i* i < n; i++){
        if (n%i == 0)return 0;   }
    return 1;
}
int Palindrome (int x )
{
    if (x < 0) return 0;
    else if (x<10)return 1;
    else 
    {
        int num = 0;
        while(x){
            num += x % 10;
            x /= 10;
        }
        if (num == x) return 1;
        else return 0;
    }
}
int Istriangle(int a,int b,int c)
{
    // scanf("%d%d%d", &a, &b, &c);
    if (a <= 0 || b <= 0 || c <= 0){
        printf("你输入的数不是正整数\n");
        return 0;
    }
    if (a > c) {
        int tmp = a;
        a = c;
        c = tmp;
            
    }
    if (b > c) {
        int tmp =b;
        b = c;
        c = tmp;
            
    }
    if (a + b <= c) {
         //printf("It's not a triangle");
         return 0;
            
    } else {
    return 1;
    }

}
int str_len(const char *str)
{
    int i=0;
    while(str[i]!='\0') i++;
    return i;
}


long long  Fib_s(int x)
{
    if(x<=0) return 0;
    if(x == 1 || x == 2) return 1;
    if(x > 91) return 0;
    long long Fib1 = 1;
    long long Fib2 = 2;
    int i = 0;
    while(1)
    {
        i++;
        if(Fib1<=Fib2) Fib1 += Fib2;
        else Fib2 += Fib1;
        if(i+3 == x)
        {
            return Fib1 > Fib2 ? Fib1 : Fib2;
        }
    }
}

int gcd(int a,int b)
{
   if (a < b)
   {
     int tmp = a;
     a = b;
     b = tmp;
   }
    int r;
    while(b>0)
    {
         r=a%b;
         a=b;
         b=r;
    }
    return a;
}
char* new_hash(const char *str) 
{
    if (strlen(str) != 32 ){
     printf("你的输入是不合法的！！！\n");
        //:  return 0;
    }

    char *ret ;
    int len, i;
    int arr[40] = {0}, bits[40] = {0};
    len = strlen(str);
    for (i = 1; i <= len; ++i) {
        arr[i % 32] += (int)str[i - 1];
    }
   
    for (i = 0; i < 32; i++) {
        bits[i] = arr[31 - i] ^ (arr[i] << 1);
        bits[i] = bits[i] % 85 + 34;
       printf("strlen = %d\n",strlen(str));
        ret[i] = (char)(bits[i]);
    }
    return ret;
} 

double BinSearch(int p, int q) 
{
    double xmin, xmax, xmid;
    double value_min, value_max, value_mid;
    xmin = -1000;
    xmax = 1001;
    value_min = p*xmin  + q;
    value_max = p*xmax  + q;
   // printf("max : %lf   min : %lf \n",value_max,value_min) ;
    do 
    {
        xmid = (xmin + xmax) / 2;
        value_mid = p*xmid  + q;
        if (fabs(value_mid) < EPSLON)
        {   
            return xmid;
        } 
         else if (value_mid * value_min < 0.0) 
        {
            xmax = xmid;
            value_max = value_mid;
        } 
         else if (value_mid * value_max < 0.0) 
        {
            xmin = xmid;
            value_min = value_mid;
        } 
    } while (1);
    return -1;
}





