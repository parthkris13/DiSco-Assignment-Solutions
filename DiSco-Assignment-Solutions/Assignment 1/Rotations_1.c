#include<stdio.h>
#include<string.h>
 
char ch[1000];
char temp[1000];
char rotated[1000];
int count = 0;
 
int isPalindrome(char *str){
 
        int j = 0;
        for (int i = 0,j = (strlen(str)-1) ; i<=j; ++i, --j ){
            if (str[i] != str[j]){
                return 0;
            }
        }
        return 1;
}
 
void rotate(int n, char *str){
    count = 0;
    if (isPalindrome(str)){
        printf("%s ", str);
        return;
    }
    else if (strcmp(str,rotated) == 0){
        return;
    }
    int cnt = 0;
 
    for (int i = n+1; i<strlen(str); i++){
        rotated[cnt++] = str[i];
    }
    for (int j = 0; j<=n; j++){
        rotated[cnt++] = str[j];
    }
    rotated[cnt++] = '\0';
    if (isPalindrome(rotated)){
        printf("%s ", rotated);
        return;
    }
 
    rotate(n+1, str);
   
}
 
int main(int argc, char const *argv[])
{
    scanf ("%[^\n]s", ch);
   
    for (int i = 0; i<strlen(ch)+1; i++)
    {
        if (ch[i]==' ' || ch[i]=='\0'){
            temp[count++] = '\0';
            rotate(0,temp);
        }
        else{
            temp[count++] = ch[i];
        }
    }
    printf("\n");
    return 0;
}