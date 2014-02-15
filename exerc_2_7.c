/* ==================================== 
File name: exerc_2_7.c
Date: 2014‐02‐02
Group Number: 9
Members that contributed: 
Saulius Eidukas
Shireen Yusur
Hristo Spilkov
Demonstration code: 43360
====================================== */ 

#include <stdio.h>
#include <string.h>

void readPersnmr(char *persnr);
void controlDigit();
int processDigits(int n);

char persnr[11];
int lastdigit;
int sum = 0;

int main(){
    int run=1;
    while (run==1) {
        printf("Enter personal number : ");
        scanf("%s", &*persnr);
        if(persnr[0]=='q')
            break;
        readPersnmr(persnr);
        lastdigit = (persnr[9] - '0');
        controlDigit();
    }
}

void readPersnmr(char *persnr){
//  printf("The personal number entered is %lu chars long : %s\n",strlen(persnr), persnr);
    if(sum!=0)
        sum =0;
    int i;
    for (i = 0; i<(strlen(persnr) - 1); i++) {
//        printf("%d\n", (processDigits(((int)persnr[i]-'0')*2)));
        sum = sum + (processDigits(((int)persnr[i]-'0')*2));
        if(i!=(strlen(persnr) - 2)){
//            printf("%d\n", ((int)persnr[(i+1)]-'0'));
            sum = sum + ((int)persnr[(i+1)]-'0');
            i++;
        }
    }
}
int processDigits (int n){
    int temp;
    if(n>10){
        temp = n - 9;
    }else if(n==10){
        temp = 1;
    }else if(n==0){
        temp = 0;
    }else{
        temp=n;
    }
    return temp;
}
void controlDigit(){
//    printf("%d %d %d\n", lastdigit, (10 - (sum %10)), sum);
    if (lastdigit == (10 - (sum %10)) || (10 - (sum %10)) == 10)
        printf("The personal number is correct! \n");
    else
        printf("The personal number is wrong! \n");
}
