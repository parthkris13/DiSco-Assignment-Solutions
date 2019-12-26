#include <stdio.h>
#include <string.h>
int isPalindrome(char *s,int l,int r)
{
    int left=l;
    int right=r;
    while(left<right)
    {
        if(s[left]==s[right])
        {
            left++;
            right--;
        }
        else
        return 0;
    }
    return 1;
}
void word_Bubble(char *s)
{
    int  n=strlen(s);
    int flag1,flag2;
    char temp[2000];
    for(int i=0;i<n;i++)
    {
        temp[i]=s[i];
        temp[i+n]=s[i];
    }
    for(flag1=0,flag2=n-1;flag1<n && flag2<(2*n);flag1++,flag2++)
    {
        if(isPalindrome(&temp,flag1,flag2))
        {
            for(int i=flag1;i<=flag2;i++)
            {
                printf("%c",temp[i]);
            }
            printf(" ");
            break;
        }
    }
}
int main(int argc, char *argv[])
{
    char str[1000];
    scanf("%[^\n]%*c", str);
    char *token = strtok(str, " ");
    while (token != NULL)
    {
        word_Bubble(token);
        token = strtok(NULL, " ");
    }
    return 0;
}