//number of rows of the board
#include <stdlib.h>
#include <stdio.h>
#define SIZE 100
#define NUM_ROWS 6
//number of columns of the board
#define NUM_COLUMNS 9

//types of squares
enum stype{
    NORMAL, OBSTACLE };

//colors of tokens
enum color {
    NOCOL, RED, BLU, GREEN, YELLOW, PINK, ORANGE
};

//defines a token. 
//Note each token can be associated with a color
typedef struct token{
   enum color col; 
    
}token;

//Defines a square of the board.
typedef struct square{
    //A square can be a NORMAL or an OBSTACLE square
     enum stype type;
     //the stack of tokens that can be placed on the board square
     token stack[SIZE];      
//number of tokens of a square
     int numTokens;
     //top value for stack
     int top;
}square;

typedef struct player{
    char name[20];
    struct token toke;
    

    int numTokensLastCol;
}player;

//creating array to use as stack
struct token stack[SIZE];




/*
 * This function creates the board for the first time
 * 
 * Input: board - a 6x9 array of squares
 *
 */
void initialize_board(square board[NUM_ROWS][NUM_COLUMNS]);

/*
 * This function creates players for the first time
 * 
 * Input: the array of players to be initialized
 * Output: The number of players of the game
 *
 */
int initialize_players(struct player players[],int numPlayers );

 


