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
char print_token(token t)
{
    if ((t).col == PINK)
        return 'P';
    if ((t).col == RED)
        return 'R';
    if ((t).col == BLU)
        return 'B';
    if ((t).col == GREEN)
        return 'G';
    if ((t).col == ORANGE)
        return 'O';
    if ((t).col == YELLOW)
        return 'Y';
    return '\0';
}

/*
 * Prints the board
 * 
 * Input: the board to be printed. 
 */
void print_board(square board[NUM_ROWS][NUM_COLUMNS])
{
    printf("                THE BOARD\n");
    for (int i = 0; i < NUM_ROWS; i++)
    {

        //prints an horizontal line
        printLine();
        //prints the row number
        printf(" %d ", i);
        char c = '\0';
        //if the square (i,j) is occupied,
        //c is assigned the initial of the color of the token that occupies the square
        for (int j = 0; j < NUM_COLUMNS; j++)
        {
            if (board[i][j].stack[0].col != NOCOL)
            {
                c = print_token(board[i][j].stack[board[i][j].top]);
            }
            //if the square (i,j) is empty
            else
            {
                //c is assigned 'X' if the square represents an obstacle
                if (board[i][j].type == OBSTACLE)
                    c = 'X';
                //c is assigned an empty space otherwise
                else
                    c = ' ';
            }
            printf("| %c ", c);
        }
        printf("|\n");
    }
    printLine();
    //prints the number of the columns at the end of the board
    printf("     0   1   2   3   4   5   6   7   8\n");
}

void printLine()
{
    printf("   -------------------------------------\n");
}

/*
 * Place tokens in the first column of the board
 * 
 * Input: board - a 6x9 array of squares that represents the board
 *        players - the array of the players
 *        numPlayers - the number of players  
 */
void place_tokens(square board[NUM_ROWS][NUM_COLUMNS], player players[], int numPlayers)
{

    int minNumOfTokens = 0;
    int selectedSquare = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < numPlayers; j++)
        {
            int player = j + 1;
        restart:
            printf("Player %d please select a square\n", player);
            scanf("%d", &selectedSquare);
            if (selectedSquare > 5)
            {
                printf("Pick a square between 0 and 5\n");
                goto restart;
            }
            //if statement to make sure all empty squares are filled
            if (j > 5 && board[selectedSquare][0].stack[board[selectedSquare][0].top].col == NOCOL)
            {
                printf("You must fil all other squares first\n");
                goto restart;
            }

            //ifstatement to ensure that player chooses smallest stack
            if (j > 5 && board[selectedSquare][0].numTokens == minNumOfTokens && board[selectedSquare][0].stack == NOCOL || j > 5 && board[selectedSquare][0].stack[board[selectedSquare][0].top].col != players[j].toke.col)
            {
                printf("You must choose the smallest stack\n");
                goto restart;
            }

            //if statement to make sure that players can stack on their own color
            if (board[selectedSquare][0].stack[board[selectedSquare][0].top].col == players[j].toke.col && board[selectedSquare][0].stack[board[selectedSquare][0].top].col != NOCOL)
            {
                printf("Cannot stack on same color!\n");
                goto restart;
            }
            board[selectedSquare][0].top = board[selectedSquare][0].top + 1;
            board[selectedSquare][0].stack[board[selectedSquare][0].top].col = players[j].toke.col;
            board[selectedSquare][0].numTokens++;

            //updates the minimum number of Tokens
            if (((numPlayers * i) + j + 1) % NUM_ROWS == 0)
                minNumOfTokens++;
            print_board(board);
        }
    }
    print_board(board);
}

void play_game(square board[NUM_ROWS][NUM_COLUMNS], player players[], int numPlayers)
{
    int i = 0;
    printf("****TIME TO PLAY!****\n\n\n");;
    //for loop based on the number of players
   while(i < numPlayers)
    {
        int choice;
        int tokemove, tokedest; //assigning variables to move tokens
        int play = i + 1;
        printf("Player %d 's turn\n", play);
        //asks players if they wish to move their token vertically
        printf("Press Y to move token vertically, N to skip\n");
        scanf(" %c", &choice);
        //if statement based on player choice
        if (choice == 'N' || 'n')
        {
            goto roll;
        }
        if (choice == 'Y' || 'y')
        {

        again:
            printf("Select the square with token of yours to move up or down:\n");
            scanf(" %d", &tokemove);
            if (board[tokemove][0].stack[board[tokemove][0].top].col != players[i].toke.col)
            {
                printf("Not one of your tokens!");
                goto again;
            }
        newdest:
            printf("Select the destination square with your token:\n");
            scanf(" %d", &tokedest);
            int tokedestplus = tokemove + 1;
            int tokedestminus = tokemove - 1;
            //ensures that player can only move token up or down one square
            if (tokedest > tokedestplus || tokedest < tokedestminus)
            {
                printf("Can only move one up or one down\n");
                goto newdest;
            }
            //moves token on board
            //implement pop and push
            board[tokedest][0].top = board[tokedest][0].top + 1;
            board[tokemove][0].top = board[tokemove][0].top - 1;
            board[tokedest][0].stack[board[tokedest][0].top].col = players[i].toke.col;
            printf("Token moved to row %d\n", tokedest);
            //prints board
            print_board(board);
        }
    roll:
        srand(time(NULL));
        int dice = (rand() % 5) + 1;
        int move;
        printf("Rolling...");
        printf("Dice Roll: %d\n", dice);
        printf("Pick a column so that a token in %d moves across:\n", dice);
        scanf("%d", &move);
         if (board[dice][move].stack[board[dice][move].top].col == NOCOL)
        {
            printf("No token to move accross! Pick again!\n");
            i++;
        }
       
        int moveacc = move + 1;
        //implement pop and push

        board[dice][move].top = board[dice][move].top + -1;
        board[dice][moveacc].top = board[dice][moveacc].top + 1;
        board[dice][moveacc].stack[board[dice][moveacc].top].col = players[i].toke.col;
              i++;
              if (i >= numPlayers){
              i = 0;
             }
        print_board(board);
       
           }
        }
    


