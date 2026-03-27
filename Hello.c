#include<stdio.h>

char board[3][3];
void initboard() {
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j]=' ';
        }
    }
}
void printboard() {
    printf("\n");
    for(int i=0;i<3;i++){
            printf(" %c | %c | %c ",board[i][0],board[i][1],board[i][2]);
    
            if(i!=2) printf("\n---|---|---\n");

        }
    printf("\n");

}
 int checkwin() {
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!=' '){
            return 1;
        }
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=' ' ){
            return 1;
        }
    }
        if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=' '){
            return 1;
        }
        if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!=' '){
            return 1;
        }
        return 0;
    }
    int main() {
        int row,col,turn=0;
        char player;

        initboard();
        while(1){
            printboard();
            player=(turn%2==0)?'x':'0';
            printf("player %c, enter row and column (0-2): ",player);
            scanf("%d%d",&row,&col);
            if(board[row][col]!=' '){
                printf("cell already occupied,try again.\n");
                continue;
            }
            board[row][col]=player;
            turn++;
            if(checkwin()){
                printboard();
                printf("player %c wins!\n",player);
                break;
            }
            if(turn==9){
                printboard();
                printf("it is a draw!\n");
                break;
            }
            
        }
        return 0;
    }
 