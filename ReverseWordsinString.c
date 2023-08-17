//reverse words character in string
#include<stdio.h>
#include<string.h>

int main()
{
    char str[100]= {"Hello World David"};
    int l=strlen(str);
    int j,k=0;

    for(int i=0; i<=l; i++)
    {
        if(str[i]==' '||i==l)
        {
            for(j=i-1; k<j; j--,k++)
            {
                char t=str[k];
                str[k]=str[j];
                str[j]=t;
            }
            k=i+1;
        }
    }
    puts(str);
}
