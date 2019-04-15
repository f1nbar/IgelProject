#include "game_init.h"
#include <stdio.h>


/*
 * This function creates the board for the first time
 * 
 * Input: board - a 6x9 array of squares
 *
 */
void initialize_board(square board[NUM_ROWS][NUM_COLUMNS]){
   
    for (int i =0; i< NUM_ROWS; i++){
        for(int j =0; j < NUM_COLUMNS; j++){
            //creates an obstacle square at positions (0,3), (1,6), (2,4), (3,5), (4,2) and (5,7)
            if((i == 0 && j==3) || (i == 1 && j == 6) || (i ==2 && j ==4) 
                    || (i == 3 && j ==5) || (i==4 && j==2) || (i==5 && j==7)){
                board[i][j].type = OBSTACLE;
            } else{
                //creates a normal square otherwise
                board[i][j].type = NORMAL;
            }
            board[i][j].stack = NULL;
        }
    }
}
    
    
 /*
 * This function creates players for the first time
 * 
 * Input: the array of players to be initialized
 * Output: The number of players of the game
 */

int initialize_players(player players[],int numPlayers){
    int nump;
    char tempname[10];
    innp:
    printf("Enter the number of players: \n");
    scanf("%d",&nump);
    //stores number of players
     numPlayers = nump;
    //get char clears the white space after scanf so fgets() works from the first loop interation
    getchar();

//if statement to ensure that there are between 2 and 6 players
    if(nump < 2 || nump > 6){
        printf("There must be between 2 and 6 players\n");
        goto innp;
    }
    int loop = nump + 1;
    //for loop in order to name players and store those player names in the struct "players"
 for(int i=1; i<loop;i++){ 

        printf("Enter Player %d's name:",i);
        fgets(players[i].name,20,stdin);

        printf("%s",players[1].col);

    }
    //assigning player colors
     players[1].col = RED;
     players[2].col = BLU;
     players[3].col = ORANGE;
     players[4].col = PINK;
     players[5].col = GREEN;
     players[6].col = YELLOW;

     printf("player 3's color: %d",players[3].col);

    
    //outputs total players
    printf("Total Players: %d\n",numPlayers);
     return numPlayers;
}
    
