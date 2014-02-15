/* ====================================
File name: exerc_2_5.c
Date: 2014‐02‐02
Group Number: 9
Members that contributed:
Saulius Eidukas
Hristo Spilkov
Shireen Yusur
Demonstration code: 42395
====================================== */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MAXNUMBER  20

// ‐‐‐‐‐‐ Function declaration   ‐‐‐‐‐‐‐‐‐‐
void create_random( int *number );
void count_frequensy(int *number, int *frequensy );
void draw_histogram(int *number );

int main ( void){
   	int table[MAX], n ;
    int frequensy[MAXNUMBER] ={0};
    srand(time(0));


create_random(table);
count_frequensy(table,frequensy);
draw_histogram(frequensy);




}

void create_random(int *number){

	int n;
	for(n=0;n<MAX;n++){
	*number = rand() % (MAXNUMBER + 1);
	*number++;
	}
}

void count_frequensy(int *table, int *frequensy){

	int i;
	int n;
	int *c;

	for(i = 0;i<=MAXNUMBER ;i++){
		c = table;
		for(n=0;n<=MAX;n++){
			if (*c == i){
				*frequensy = *frequensy +1;
			}
			*c++;
		}
	*frequensy++;
	}
}



void draw_histogram(int *number){
	int i;
	int n;
	for(i = 0; i<=MAXNUMBER+1;i++){
		if(*number != 0){
		printf("%d :", i);
		}
		
		for(n = 0;n < *number;n++){
			printf("%c", 'x' );
		}
	
		printf("\n");
		*number++;
	}
}

