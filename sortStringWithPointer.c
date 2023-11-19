#include <stdio.h>

int length(char *a)
{
    int len = 0;
    while (*a)
    {
        a++;
        len++;
    }
    return len;
}

void sort(char *s)
{
    int len=length(s);

    for (int i=0;i<len-1;i++)
    {
        for (int j=0;j<len-i-1;j++)
        {
            if (*(s+j)>*(s+j+1))
            {
                char temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
}
void concat(char *a,char *b)
{
    while(*a)
    {
        a++;
    }
    while(*b)
    {
        *a=*b;
        b++;
        a++;

    }

}

int main()
{
    char a[30], b[30];
    gets(a);
    gets(b);

    sort(a);
    sort(b);

    concat(a,b);

    sort(a);

    printf("%s\n", a);


    return 0;
}

