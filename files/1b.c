#include<stdio.h>
#include<string.h>
int main(){
    char pt[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char ct[] = "ZYXWVUTSRQPONMLKJIHGFEDCBAzyxwvutsrqponmlkjihgfedcba";
    char p[20],c[20],r[20]={'\0'};
    printf("enter the message\n");
    scanf("%s",&p);
    int i,j;

    for(i=0;p[i]!='\0';i++){
        for(j=0;j<52;j++){
            if(p[i]==pt[j]){
             c[i]=ct[j];
             break;
            }
        }
    }
    printf("\nencryption %s",c);

    for(i=0;c[i]!='\0';i++){
        for(j=0;j<52;j++){
            if(c[i]==ct[j]){
            r[i]=pt[j];
            break;
        }
        }
    }
    printf("\ndecryption %s",r);
}