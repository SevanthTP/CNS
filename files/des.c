#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void sboxeacess(int [8][4][16],int [48],int *);
void binarytodecimal(int,int *);
int main(){
    int sbox[8][4][16],input[48],output[32],permutationtable[32],permutedoutput[32];
    for(int i=0;i<8;i++)
     for(int j=0;j<4;j++)
      for(int k=0;k<16;k++)
       sbox[i][j][k]=rand()%16;

 for(int i=0;i<48;i++)
  input[i]=rand()%2;

  sboxeacess(sbox,input,output);



printf("sbox:\n");
for(int i=0;i<32;i++){
 if(i%4==0) printf("\n");
   printf("%d",output[i]);
}
     
 for(int i=0;i<32;i++){
    permutationtable[i]=rand()%32;
}
  printf("permuted output:\n");
   for(int i=0;i<32;i++){
    permutedoutput[i]=output[permutationtable[i]%32];
    if(i%4==0)printf("\n");
    printf("%d",permutedoutput[i]);
   }
}
void sboxeacess(int sbox[8][4][16],int input[48],int output[32]){
    int col,row,binaryversion[4];
    for(int i=0;i<8;i++){
        int j=i*6;

        row=(input[j]<<1)|input[j+5];
        col=(input[j+3]<<1)|(input[j+2]<<2)|(input[j+1]<<3)|input[j+4];

        binarytodecimal(sbox[i][row][col],binaryversion);

        for(int k=0;k<4;k++){
            output[(i*4)+k]=binaryversion[k];
        }
    }
}
void binarytodecimal(int num,int *bin){
    for(int i=3;i>=0;i--){
        bin[i]=num%2;
        num/=2;
    }
}