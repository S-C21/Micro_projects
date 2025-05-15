#include <stdio.h>
#include <conio.h>
#include <ctype.h>
void printboard();
int checkwin();
void system();
char markchooser();
char board[] = {'0','1','2','3','4','5','6','7','8','9'};  //we add 0 so the index matches with the number:convinience 
void printboard(){
    system("cls");  //make sure that all changes take place within the same board (cls = clear the screen)
    printf("\n\n");
    printf("==== TIC-TAC-TOE ====\n\n");
    printf("       |       |       \n");
    printf("   %c   |   %c   |   %c   \n", board[1],board[2],board[3]);
    printf("_______|_______|_______\n");
    printf("       |       |       \n");
    printf("   %c   |   %c   |   %c   \n", board[4],board[5],board[6]);
    printf("_______|_______|_______\n");
    printf("       |       |       \n");
    printf("   %c   |   %c   |   %c   \n", board[7],board[8],board[9]);
    printf("       |       |       \n");
}

char markchooser(){
    char c;
    printf("Enter your prefered mark 'X' or 'O': ");
    scanf("%c",&c);
    if(tolower(c) == 'x'){
        return 'X';
    }
    else if(tolower(c) == 'o'){
        return 'O';
    }
}

int checkwin(){    //all possible combinations of winning 
    if(board[1] == board[2] && board[2] == board[3]){
        return 1;
    }
    if(board[4] == board[5] && board[5] == board[6]){
        return 1;
    }
    if(board[7] == board[8] && board[8] == board[9]){
        return 1;
    }
    if(board[1] == board[4] && board[4] == board[7]){
        return 1;
    }
    if(board[2] == board[5] && board[5] == board[8]){
        return 1;
    }
    if(board[3] == board[6] && board[6] == board[9]){
        return 1;
    }
    if(board[1] == board[5] && board[5] == board[9]){
        return 1;
    }
    if(board[3] == board[5] && board[5] == board[7]){
        return 1;
    }
    int count = 0;
    for(int i = 1; i<=9; i++){
        if(board[i] == 'X' || board[i] == 'O'){
            count++;
        }
    }
    printf("%d",count);
    if(count == 9){
        return 0;
    }
    return -1;
}

int main(){
    int player = 1,input,status = -1;
    printboard();
    
    while(status == -1){
        if(player%2 == 0){
            player = 2;
        }
        else{
            player = 1;
        }
        char mark;
        if(player == 1){
            mark = 'X';
        }
        else{
            mark = 'O';
        }
        printf("Please enter number for player %d: \n",player);
        scanf("%d",&input);
        if (input<1 || input>9){
                printf("Invalid input\n");
                continue;
        }
        if (board[input]=='X' || board[input]=='O'){
            printf("Invalid move\n");
            continue;
        }
        else{board[input] = mark;}
        printboard();
        int result = checkwin(); 
        if (result == 1){
            printf("Player %d won!\n",player);
            return;
        }else if (result == 0){
            printf("Draw!\n");
            return;
        }
        player++;   
    }

}