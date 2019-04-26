#include "game_init.h"
#include <stdio.h>

/*
 * This function creates the board for the first time
 * 
 * Input: board - a 6x9 array of squares
 *
 */
void initialize_board(square board[NUM_ROWS][NUM_COLUMNS])
{

    for (int i = 0; i < NUM_ROWS; i++)
    {
        for (int j = 0; j < NUM_COLUMNS; j++)
        {
            //creates an obstacle square at positions (0,3), (1,6), (2,4), (3,5), (4,2) and (5,7)
            if ((i == 0 && j == 3) || (i == 1 && j == 6) || (i == 2 && j == 4) || (i == 3 && j == 5) || (i == 4 && j == 2) || (i == 5 && j == 7))
            {
                board[i][j].type = OBSTACLE;
            }
            else
            {
                //creates a normal square otherwise
                board[i][j].type = NORMAL;
            }
            board[i][j].stack[0].col = NOCOL;
        }
    }
    //assigns top value for stack to -1 for all squares on board
    for (int i = 0; i < NUM_ROWS; i++)
    {
        for (int j = 0; j < NUM_COLUMNS; j++)
        {
            board[i][j].top = -1;
        }
    }
}

/*
 * This function creates players for the first time
 * 
 * Input: the array of players to be initialized
 * Output: The number of players of the game
 */

int initialize_players(player players[], int numPlayers)
{
    int nump;
    char tempname[10];
innp:
    printf("Enter the number of players: \n");
    scanf("%d", &nump);
    //stores number of players
    numPlayers = nump;
    //get char clears the white space after scanf so fgets() works from the first loop interation
    getchar();

    //if statement to ensure that there are between 2 and 6 players
    if (nump < 2 || nump > 6)
    {
        printf("There must be between 2 and 6 players\n");
        goto innp;
    }
    int loop = nump + 1;
    //for loop in order to name players and store those player names in the struct "players"
    for (int i = 1; i < loop; i++)
    {

        printf("Enter Player %d's name:", i);
        fgets(players[i].name, 20, stdin);
        strtok(players[i].name, "\n"); 
    }
    //assigning player colors
    players[0].toke.col = RED;
    players[1].toke.col = BLU;
    players[2].toke.col = GREEN;
    players[3].toke.col = YELLOW;
    players[4].toke.col = PINK;
    players[5].toke.col = ORANGE;

    //switch statement to let players know their color
    switch (nump)
    {
    case 2:
        printf("%s = RED\n",players[0].name);
        printf("%s = BLUE\n",players[1].name);
        break;
    case 3:
        printf("%s = RED\n",players[0].name);
        printf("%s = BLUE\n",players[1].name);
        printf("%s = GREEN\n",players[2].name);
        break;
    case 4:
        printf("%s = RED\n",players[0].name);
        printf("%s = BLUE\n",players[1].name);
        printf("%s = GREEN\n",players[2].name);
        printf("%s = YELLOW\n",players[3].name);
        break;
    case 5:
        printf("%s = RED\n",players[0].name);
        printf("%s = BLUE\n",players[1].name);
        printf("%s = GREEN\n",players[2].name);
        printf("%s = YELLOW\n",players[3].name);
        printf("%s = PINK\n",players[4].name);
        break;
    case 6:
        printf("%s = RED\n",players[0].name);
        printf("%s = BLUE\n",players[1].name);
        printf("%s = GREEN\n",players[2].name);
        printf("%s = YELLOW\n",players[3].name);
        printf("%s = PINK\n",players[4].name);
        printf("%s = ORANGE\n",players[5].name);
        break;
    }

    //outputs total players
    printf("Total Players: %d\n", numPlayers);
    return numPlayers;
}
