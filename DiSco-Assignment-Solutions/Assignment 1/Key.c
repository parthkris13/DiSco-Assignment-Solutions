#include<stdio.h>
#include<string.h>
int allposs(char c[],int start,int end);
int main()
{
char c[10];
scanf("%s",c);
allposs(c,0,strlen(c));
}
int allposs(char c[],int start,int end)
{
    for(int i=start;i<=end-1;i++)
    {
        if(start==end-1)
            {
                printf("%s\n",c);
                return 0;
            }
        char z=c[i];
        c[i]=c[start];
        c[start]=z;
        allposs(c,start+1,end);
        z=c[i];
        c[i]=c[start];
        c[start]=z;
    }
}