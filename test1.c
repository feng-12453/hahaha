#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{   char a[]="Dian";
    char b[]="Quit";
    char input[100];
    int ans1,ans2;

    while(1){
    printf("请输入：");
    fgets(input,100,stdin);

    int len =strlen(input);
    if (len>0 && input[len-1]=='\n'){
        input[len-1]='\0';
    }

    ans1=strcmp(input,a);
    ans2=strcmp(input,b);

     if (ans1==0)
    {
        printf("2002\n");
    }else if(ans2==0){
        exit(0);   
    }else {
    
        printf("Error\n");
    }
}

    return 0;
}