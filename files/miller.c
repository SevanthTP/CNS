#include<stdio.h>
#include<stdlib.h>
long long int modulo(int base,int pw,int mod){
    long long int i,a=1;
    for(i=0;i<pw;i++){
        a=a*base;
    }
    return a%mod;
}
int miller(int p){
    long long int m,b,a=2,k=0;
    if(p<2){
        return 0;
    }
    if((p!=2) && (p%2==0)){
        return 0;
    }

    m=p-1;
    while((m%2)==0){
        m/=2;
        k++;
    }
    b=modulo(a,m,p);
    if(b==1){
        return 1;
    }

    while(b!=1 && b!=p-1 && k>0){
        b=modulo(b,2,p);
        if(b==0){
            return 0;
        }
        k--;
    }
    if(b==p-1){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    int n;
    printf("enter a number: ");
    scanf("%d",&n);
    if(miller(n)){
        printf("%d is prime",n);
    }else{
        printf("%d is not prime",n);
    }
    return 0;
}