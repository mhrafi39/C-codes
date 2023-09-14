//Prime Factors of a number  recursively

#include<stdio.h>

void primefac(int n,int i)
{
    if(n==0)
        return;
    if(n%i==0)
    {
        printf("%d ",i);
        primefac(n/i,i);
    }
    else
        primefac(n,i+1);
}

int main()
{
    printf("Enter a number for prime factors of that number ");
    int num;
    scanf("%d",&num);
    printf("Prime Factors are : ");
    primefac(num,2);

    return 0;
}
