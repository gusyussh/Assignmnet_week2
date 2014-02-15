/*====================================
 File name: exerc_2_1.c  Date: 2013‐02‐01
 Group Number: 9
 Members that contributed:
 Shireen Yusur
 Saulius Eidukas
 Hristo Spilkov
 
 Demonstration code: 41214

Uncomment function in main, depending which want to run.
 ====================================== */


#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAX 80

// read from the keyboard into an internal char buffer
char copyFunction_command(){
    
    char source[MAX];
    char buffer[MAX];

    printf("PLease enter your string\n");
    fgets(source, MAX, stdin);
    
   
    
    if((strcpy( buffer, source))== 0) {
        printf("Your input is  not copied into an internal char buffer. \n");
        return 1;
        
    } else {
         printf("Well-done !!, your input is copied into an internal char buffer %s.\n ", buffer);
        return 0;
    }
    
    return 0;
}

/************************************************************/
char copyWithoutFunction_command(){
    
    char source[MAX];
    char buffer[MAX];
    int i;
    
    printf("PLease enter your string\n");
    fgets(source, MAX, stdin);

   // copy from  source array of characters into an internal char buffer
    for (i = 0; i < MAX; i++) {
        buffer[i] = source[i];
    }
    // print it into screen
    printf("Your data stored into an internal char buffer: %s\n ", buffer);
    printf("\n");
        return 0;
}

/************************************************************/

// read from text file into array of string
char copyFunction_file(){
    
    char source[MAX]; // store the data from the text file
    char target[MAX]; // empty array
    int stat;
    
    // get the path of the text file and read it
    FILE *fp = fopen("myFile.txt", "r");
    
    
    do{
        stat = fscanf(fp, "%s", source);
        // this function copy from source to destination strcpy(destination,source)
       strcpy(target,source);
        
    // print to screen
       printf("%s ", target);
    }while( stat != EOF);
    
    
    printf("\n");
    fclose(fp);
    return 0;
    
}

/************************************************************/

// read form text file and copy it into array of string
char copyWithoutFun(){
    
    char source[MAX]; // store the data from the text file
    char target[MAX]; // empty array
    int stat;
    int i;
    
    // get the path of the text file and read it
    FILE *fp = fopen("myFile.txt", "r");
    
    
    do{
        stat = fscanf(fp, "%s", source);
        
        for (i= 0; i < MAX; i++) {
            target[i]=source[i];
            
        }
        printf("%s ", target);
        
    }while( stat != EOF);
    
    printf("\n");
    fclose(fp);
    return 0;
    
}


int main(){
	
 //  copyFunction_command();
   copyFunction_file();
 //  copyWithoutFun();
//   copyWithoutFunction_command();
  
    
    return 0;
}
