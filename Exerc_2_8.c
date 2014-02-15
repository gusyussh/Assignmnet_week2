/* ==================================== 
File name: exerc_2_8.c 
Date: 2014‐02‐02
Group Number: 9
Members that contributed: 
Saulius Eidukas
Shireen Yusur
Hristo Spilkov
Demonstration code: 41768
====================================== */ 

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>


#define MAX_COINS 13


const int HUMAN = 0;
const int COMPUTER = 1;

/* ------------- IO --------------- */

/*
 * human_choice
 * Get human choce as an int from stdin.
 * Clears stdin.
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int human_choice(int pile);

/*
 * write_winner
 * Write winner as a string on stdout.
 * in: Values HUMAN or COMPUTER.
 * out:
 */
void write_winner( int player );

/*
 * play_again
 * Ask human if he/she wants to play
 * another round. If 'n' or 'N' selected
 * (single char) return false else true.
 * Clears stdin.
 * in:
 * out: true or false
 */
int play_again();

/* ---------------- Logic ----------------*/

/*
 * computer_choice
 * Get computers choice (including some AI,
 * if 4 coins or less left, function makes a
 * smart choice else random).
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int computer_choice(int pile);

/*
 * toggle
 * Switches player, if HUMAN in COMPUTER out
 * etc.
 * in:  actual player
 * out: next player
 */
int toggle( int player );

/* --------------------- Utilities -------------*/
void clear_stdin();
bool askToContinue();

/***************************************************
 *
 *    MAIN
 *
 ***************************************************/
int main()
{
    bool run = true;
    int pile,			/* This is how many coins we have */
    player,             /* Who is playing? */
    n_coins;			/* Number of coins taken */
    
    srand( time(0) );	/* Setup random */
    
    printf("Välkommen till NIM by ...\n");
    
    pile = MAX_COINS;		/* Set start values (= init) */
    player = HUMAN;
    
    /*
     *  Program main loop
     */
    while (run) {
        
    while( true ) {
        
        printf("Det ligger %d  mynt i högen\n", pile );
        
        if( player == HUMAN ){
            n_coins = human_choice(pile);
        }else{
            n_coins = computer_choice(pile);
            printf("- Jag tog %d\n", n_coins);
        }
        pile -= n_coins;
        player = toggle( player );
        
        if( pile <= 1 ){
            break;
        }
    }
    /*
     * end main loop
     */
    
    write_winner( player );
        
        run = askToContinue();
        pile=MAX_COINS;
    }
    
    printf("Avslutat\n");
    
    return 0;
}

/******************************************************
 *
 *  DEFINITIONS
 *
 ******************************************************/


void clear_stdin()
{
    while( getchar() != '\n' ){
        ;
    }
}

int human_choice(int pile)
{
    int coins = 0;
    while (coins<1 || coins>3) {
        printf("Enter the ammount of coins you wish to take (1-3) :");
        scanf( "%d", &coins);
        clear_stdin();
    }
    return coins;
}

int computer_choice(int pile)
{
    int coins;
    switch (pile) {
        case 4:
            coins = 3;
            break;
        case 3:
            coins = 2;
            break;
        case 2:
            coins = 1;
            break;
        default:
            coins = (rand() % 3) + 1;
            break;
    }
    return coins;
}

void write_winner(int player )
{
    if (player==1) {
        printf("Congratulations, you win!\n");
    }else if (player==0)
    printf("Sorry! I won!\n");
}

int play_again()
{
    return 0;
}

int toggle( int player )
{
    if (player == HUMAN)
        return COMPUTER;
    else return HUMAN;
}
bool askToContinue(){
    char choice;
//    clear_stdin();
    
    printf("Do you want to play again (y/n) :");
    scanf( " %c", &choice);
    if (choice=='n' || choice=='N') {
        return false;
    }else if(choice=='y' || choice=='Y'){
             return true;
    }
    return false;
}
