/* ==================================== 
File name: exerc_2_4.c
Date: 2014‐02-02 
Group Number: 9
Members that contributed: 
Saulius Eidukas 
Hristo Spilkov
Shireen Yusur
Demonstration code: 45006 
====================================== */ 
#include <stdio.h>
#include <string.h>
#define MAX 20
int palindrome(char *word);
int main(){
char input[MAX];
int result ;

printf("Please enter word and press enter: ");
fgets(input,MAX,stdin);
strtok(input,"\n"); //remove \n at the end of input
result = palindrome(input);

if(result == 1){
	printf("Word %s is a palindrome.\n",input);
}
else{
	printf("Word %s is not a palindrome.\n",input);
}
return 0;
}

int palindrome(char *word){

//gets range of the input	
char *start = word;
char *end = start + strlen(word) - 1 ; // -1 to remove \0 from the end.
char *middle = start + (strlen(word) /2 -1); //midlle of the word

while(start != middle){
	if(*start == *end ){
		*start++;
		*end--;
	}
	else{
		return 0;}
}	
return 1;
}
