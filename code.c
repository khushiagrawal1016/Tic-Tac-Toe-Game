#include <stdio.h>
#include <stdbool.h>

void init_board();
void print_board();
void make_move(char player);
bool check_if_valid(int row, int col);
char board[3][3];

void init_board(){
    int i, j;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            board[i][j] = '.';
        }
    }
}

void print_board(){
    int i, j;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

bool check_if_valid(int row, int col){
    if (board[row][col] == '.'){
        return true;
    }
    else {
        return false;
    }
}

void make_move(char player){
    int row = 0, col = 0;
    
    do {
        printf("\n %c, make a move!\n ", player);
        scanf("%d%d", &row, &col);
        
        if(!(check_if_valid(row - 1, col - 1))){
            printf("Not a valid move, try again!\n ");
        }
    } while (!(check_if_valid(row - 1, col - 1)));
    board[row - 1][col - 1] = player; 
}

int main(void){
    char player = 'X';
    bool running = true;
    int move = 0;
    init_board();
    print_board();
    while (running){
        if (move % 2 == 0){
            player = 'X';
        }
        else {
            player = 'O';
        }
        switch (player){
            case 'X':
                make_move(player);
            break;
            case 'O':
                make_move(player);
            break;
        }
        move++;
        if (move == 9){
            running = false;
        }
        print_board();
    }
    printf("Thanks for playing!\n ");
  
  return 0;
}
