#include "game_init.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printLine();

/*
 * Returns the first letter associated with the color of the token
 * 
 * Input: t - pointer to a token
 * Output: initial of the color of the token
 */
char print_token(token *t){
    if((*t).col== PINK) return 'P';
    if((*t).col== RED) return 'R';
    if((*t).col== BLU) return 'B';
    if((*t).col== GREEN) return 'G';
    if((*t).col== ORANGE) return 'O';
    if((*t).col== YELLOW) return 'Y';
    return '\0';
}

/*
 * Prints the board
 * 
 * Input: the board to be printed. 
 */
void print_board(square board[NUM_ROWS][NUM_COLUMNS]){
    printf("                THE BOARD\n");
    for(int i =0; i < NUM_ROWS; i++){
       
        //prints an horizontal line
        printLine();
        //prints the row number
        printf(" %d ", i);
        char c = '\0' ;
        //if the square (i,j) is occupied,
        //c is assigned the initial of the color of the token that occupies the square
        for (int j = 0; j < NUM_COLUMNS; j++){
            if(board[i][j].stack != NULL){
                c = print_token(board[i][j].stack);
            }
            //if the square (i,j) is empty
            else{
                //c is assigned 'X' if the square represents an obstacle
                if(board[i][j].type == OBSTACLE)
                    c = 'X';
                //c is assigned an empty space otherwise
                else c = ' ';
            }
            printf("| %c ", c);
        }
        printf ("|\n");
    }
    printLine();
    //prints the number of the columns at the end of the board
    printf("     0   1   2   3   4   5   6   7   8\n");
}

void printLine(){
  printf("   -------------------------------------\n");  
}

/*
 * Place tokens in the first column of the board
 * 
 * Input: board - a 6x9 array of squares that represents the board
 *        players - the array of the players
 *        numPlayers - the number of players  
 */
void place_tokens(square board[NUM_ROWS][NUM_COLUMNS], player players[], int numPlayers){
    // TO BE IMPLEMENTED
    int minNumOfTokens = 0;
    int selectedSquare = 0;

    for(int i =0;i<4;i++){
        for(int j=0;j<numPlayers;j++){
            int player = j+1;
            restart:     
            printf("Player %d please select a square\n",player);
            scanf("%d",&selectedSquare);
            if(selectedSquare > 5){
                printf("Pick a square between 0 and 5");
                goto restart;
            }
          
            board[selectedSquare][0].stack=(token *) malloc(sizeof(token));
            board[selectedSquare][0].stack->col = players[j].toke.col;
            board[selectedSquare][0].numTokens++;

            //updates the minimum number of Tokens
            if(((numPlayers * i)+ j +1) % NUM_ROWS ==0)
            minNumOfTokens++;
            print_board(board);
        }
    }
      
      print_board(board);
}


void play_game(square board[NUM_ROWS][NUM_COLUMNS], player players[], int numPlayers){
  printf("****TIME TO PLAY!****\n\n\n");
  

  for(int i=0;i<numPlayers;i++){
    int play = i+1;
    int choice;
    int tokemove,tokedest;
    printf("Player %d's turn\n",play);
    printf("Press Y to move token veritcally, N to skip\n");
    scanf(" %c",&choice); 
    if(choice == 'Y'){ 
       printf("Select the square with token of yours to move up or down:\n");
       scanf(" %d",&tokemove);
       printf("Select the destination square with your token:\n");
       scanf(" %d",&tokedest);
       board[tokedest][0].stack = board[tokemove][0].stack;
       printf("Token Moved!");
       print_board(board);
    } 
    
    int dice= (rand() % 6)+ 1; 
    printf("Rolling...");   
    printf("Dice Roll: %d\n", dice); 
    srand(time(NULL));
    
  }
}


