#include <stdio.h>

long long int fibo(int n)
{
    if(n==0 || n==1)
    return n;
    
    long long int f=fibo(n-1)+fibo(n-2);
    return f;
}

int main()
{
    int n;
    scanf("%d",&n);
    
    printf("%d\n",fibo(n));
}