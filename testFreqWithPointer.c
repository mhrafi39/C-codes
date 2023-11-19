#include<stdio.h>

void freq(char *a,int *t)
{
    for(int i=0;i<26;i++)
    {
        t[*a-'a']++;
        a++;
    }

}


int main()
{
    char a[30];
    int t[26]={0};
    gets(a);
    freq(a,t);
    for(int i=0;i<26;i++)
    {
        if(t[i]!=0)
           {
               printf("%c = %d\n",('a'+i),t[i]);
           }
    }

}
