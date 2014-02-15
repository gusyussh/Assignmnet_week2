/* ==================================== 
File name: exerc_2_6.c 
Date: 2014‐02‐02
Group Number: 9
Members that contributed: 
Saulius Eidukas
Shireen Yusur
Hristo Spilkov
Demonstration code: 45046
====================================== */ 
#include <stdio.h>
#define MAX 5

int input (int list [] , int number);
void initQue (int list []);
void removeNumber(int list[]);
void printList(int list[]);

int queue[MAX];

int main(int argc, const char * argv[])
{
    initQue(queue);
    printList(queue);
    input(queue, 3);
    input(queue, 5);
    input(queue, 6);
    input(queue, 4);
    input(queue, 3);
    input(queue, 8);
    printList(queue);
    removeNumber(queue);
    removeNumber(queue);
    removeNumber(queue);
    printList(queue);

}

int input (int list[] , int number){
    int i;
    for (i=0; i<MAX; i++) {
        if(list[i]==-1){
            list[i]=number;
            return 1;
            break;
        }
    }
    return 0;
}

void initQue (int list []){
    int i ;
    for (i=0; i<MAX; i++) {
        list[i]=-1;
    }
}
void removeNumber(int list[]){
    int temp[MAX];
    initQue(temp);
    int i;
    for (i=1; i<MAX; i++) {
        input(temp, queue[i]);
    }
    initQue(queue);
    for (i=0; i<MAX; i++) {
        input(queue, temp[i]);
    }
}
void printList(int list[]){
    int i;
    for (i=0; i<MAX; i++) {
        printf("%d ",list[i]);
    }
    printf("\n");
}
