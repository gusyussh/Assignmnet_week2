/*====================================
 File name: exerc_2_3.c  Date: 2013‐02‐01
 Group Number: 9
 Members that contributed:
 Shireen Yusur
 Saulius Eidukas
 Hristo Spilkov

 Demonstration code: 45412
 ====================================== */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 80

int two_string_cmp() {

	char string1[MAX];
	char string2[MAX];
    int compareValues;

	printf("Please enter your first string\n");
	fgets(string1, MAX, stdin);

	printf("Please enter your second string\n");
	fgets(string2, MAX, stdin);

   compareValues = strcmp(string1, string2);

    if ( compareValues == 0) {
     printf("Correct your strings are the same\n");
     } else {

     printf("Sorry your strings are different\n");
     }



	return 0;
}

int two_string_without(  char string1[] ,char string2[]) {

    int i = 0;
    bool same;


        while((string1[i] == string2[i]) && (string1[i] != '\0')  && (string2[i] != '\0')){
            i++;
    }

    // check the end of the characters in both of the input/ strings
    if (string1[i] == '\0' && string2[i] == '\0') {
        same = true;
    } else {
        same = false;
    }

    return same;

}

int main (){
    
    /* Invoke the compare string - strcmp()*/
	// two_string_cmp();
	char string1[MAX];
	char string2[MAX];
	int i = 0;
    
	printf("Please enter your first string\n");
	fgets(string1, MAX, stdin);
    
	printf("Please enter your second string\n");
	fgets(string2, MAX, stdin);
    
	// two_string_without(string1, string2);
    
	if (two_string_without(string1, string2) != true) {
        
		printf("Sorry your strings are different\n");
	} else {
		printf("Correct your strings are the same\n");
        
	}
    
    return 0;
}

