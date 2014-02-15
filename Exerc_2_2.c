/*====================================
 File name: exerc_2_2.c  Date: 2013‐02‐01
 Group Number: 9
 Members that contributed:
 Shireen Yusur
 Saulius Eidukas
 Hristo Spilkov
 
 Demonstration code: 47559
 ====================================== */

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*declares a constant named MAX and sets it to */
#define MAX 5

int main() {
    
    // declare variables
	int array[MAX];
	int random[MAX];
	int i;
  //  int length;
    
	/*Store the array list in a pointer*/
	int *pArray = array;
    
	/*The size of an array*/
	int size = sizeof(pArray);
    
	//printf("test %d\n", array);
    
	/*Size of array*/
	int size_of_arr = sizeof(array);
    // print the length of the array- and will print 6 include the end of line EOF or /n,since we have the length MAX =5
	//length= strlen(array);
	//printf("length  %d\n", length );
	/*seed the random number generator*/
	srand(time(NULL));
    
	// generate random numbers
	for (i = 0; i < MAX; i++) {
        
		random[i] = (rand() % 10) + 1;
		// This print for testing
		//printf("Random value %d\n", random[i]);
	}
	// store all random number in array list
	for (i = 0; i < MAX; i++) {
		array[i] = random[i];
		// This print for testing
		printf("Array value %i\n", array[i]);
	}
    
	// The value of array- address
	printf("The value of array(address)=> &array: %p\n\n", &array);
    
	// The first integer
	printf("The first integer = %i\n\n", array[0]);
    
	// The size of an integer will print 8 => OS 64-bit or 4 => OS 32-bit
	printf("The size of an integer  %i byte\n", size);
    
	//The size of array
	printf("The size of array  %i\n\n", size_of_arr);
    
	// Default values of the array
	for (i = 0; i < MAX; i++) {
		printf("Default values of the array: %i\n", array[i]);
	}
	for (i = 0; i < MAX; i++) {
		*pArray = *pArray * 2;
		*pArray++;
	}
	printf("\n");
	// Double all the values of array
	for (i = 0; i < MAX; i++) {
		printf("Double all the values of array: %i\n", array[i]);
	}
    
	return 0;
}

