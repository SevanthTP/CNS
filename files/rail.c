#include<stdio.h>
#include<string.h>
int main(){
    int len,rails,col=0,row=0,dir=1;
    char str[1000],code[1000][1000];
    printf("enter the seceret msg:\n");
    fgets(str,sizeof(str),stdin);

    len=strlen(str);
    printf("enter the no of rails:\n");
    scanf("%d",&rails);

    for(col=0;col<len;col++){
        code[row][col]=str[col];
        row+=dir;
        if(row==0 || row==rails-1) dir*=-1;
    }

    printf("cipher:\n");
    for(int i=0;i<rails;i++){
        for(int j=0;j<len;j++){
            if(code[i][j]!=0)
            printf("%c",code[i][j]);
           // printf("\n");
        }
    }
}