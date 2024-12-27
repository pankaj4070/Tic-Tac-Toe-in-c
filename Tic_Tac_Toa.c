#include <stdio.h>
char board[9]={'1','2','3','4','5','6','7','8','9'};

void display(){
    printf("\n");
    for(int i = 0 ; i < 9 ; i++){
        printf(" %c ",board[i]);
        if(i%3 != 2 ){
            printf("|");
        }
        else if(i != 8 ){
            printf("\n---|---|---\n");
        }
    }
    printf("\n\n");
}

void move(int player){
    int choice ; 
    char mark = ( player == 1 ) ? 'X' : 'O'  ;
    printf("Player %d %c Play Your Move (1 - 9 ):",player,mark);
    scanf("%d",&choice);
    if (choice < 1 || choice > 9 || board[choice - 1] == 'X' || board[choice - 1] == 'O') {
        printf("Invalid move! Try again.\n");
        move(player); 
    } 
    else {
        board[choice - 1] = mark;
    }
}

int check_win(){
    int wins[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, 
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, 
        {0, 4, 8}, {2, 4, 6}  
    };
    for (int i = 0; i < 8; i++) {
        if (board[wins[i][0]] == board[wins[i][1]] && board[wins[i][1]] == board[wins[i][2]]) {
            return (board[wins[i][0]] == 'X') ? 1 : 2; // Player 1 or 2
        }
    }
    return 0 ; 
}

int main(){
    int player = 1, winner = 0, moves = 0;

    printf("Welcome to Tic Tac Toe!\n");
    display();

    while (winner == 0 && moves < 9) {
        move(player);
        display();
        winner = check_win();
        player = (player == 1) ? 2 : 1; 
        moves++;
    }

    if(winner){
        printf("Player %d wins!\n", winner);
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}