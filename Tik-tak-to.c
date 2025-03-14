//write code for make a game tik-tak-to
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>



//player name
char player1[20];
char player2[20];
//box for tik-tak-to
char box[3][3] = {{'1', '2', '3'},
                  {'4', '5', '6'},
                  {'7', '8', '9'}};
int box_x[3][3] = {{0, 0, 0},
                   {0, 0, 0},
                   {0, 0, 0}};
int box_o[3][3] = {{0, 0, 0},
                   {0, 0, 0},
                   {0, 0, 0}};


void box_cng(int num, char arr[3][3], char ch) {
    if (num == 1) {
        arr[0][0] = ch;
    } else if (num == 2) {
        arr[0][1] = ch;
    } else if (num == 3) {
        arr[0][2] = ch;
    } else if (num == 4) {
        arr[1][0] = ch;
    } else if (num == 5) {
        arr[1][1] = ch;
    } else if (num == 6) {
        arr[1][2] = ch;
    } else if (num == 7) {
        arr[2][0] = ch;
    } else if (num == 8) {
        arr[2][1] = ch;
    } else if (num == 9) {
        arr[2][2] = ch;
    } else {
        printf("Invalid input\n");

    }
}


void cng_to_num(char arr1[3][3], int arr2[3][3], char ch) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr1[i][j] == ch) {
                arr2[i][j] = 1;
            }
        }
    }
}

int check(int num) {
    switch (num) {
        case 1:
            if (box[0][0] == 'X' || box[0][0] == 'O') {
                return 0;
            }
            break;
        case 2:
            if (box[0][1] == 'X' || box[0][1] == 'O') {
                return 0;
            }
            break;
        case 3:
            if (box[0][2] == 'X' || box[0][2] == 'O') {
                return 0;
            }
            break;
        case 4:
            if (box[1][0] == 'X' || box[1][0] == 'O') {
                return 0;
            }
            break;
        case 5:
            if (box[1][1] == 'X' || box[1][1] == 'O') {
                return 0;
            }
            break;
        case 6:
            if (box[1][2] == 'X' || box[1][2] == 'O') {
                return 0;
            }
            break;
        case 7:
            if (box[2][0] == 'X' || box[2][0] == 'O') {
                return 0;
            }
            break;
        case 8:
            if (box[2][1] == 'X' || box[2][1] == 'O') {
                return 0;
            }
            break;
        case 9:
            if (box[2][2] == 'X' || box[2][2] == 'O') {
                return 0;
            }
            break;
        default:
            return 1;
    }
    return 1;
}

int check_to_win(int arr[3][3]) {
    int i;
    for (i = 0; i < 3; i++) {
        if (arr[i][0] == 1 && arr[i][1] == 1 && arr[i][2] == 1) {
            return 1;
        }
    }
    for (i = 0; i < 3; i++) {
        if (arr[0][i] == 1 && arr[1][i] == 1 && arr[2][i] == 1) {
            return 1;
        }
    }
    if (arr[0][0] == 1 && arr[1][1] == 1 && arr[2][2] == 1) {
        return 1;
    }
    if (arr[0][2] == 1 && arr[1][1] == 1 && arr[2][0] == 1) {
        return 1;
    }
    return 0;
}

void print_box() {
    printf("\t |\t   |\n"
           "    %c    |    %c    |   %c\n"
           "\t |\t   |\n"
           "---------|---------|---------\n"
           "\t |\t   |\n"
           "    %c    |    %c    |   %c\n"
           "\t |\t   |\n"
           "---------|---------|--------\n"
           "\t |\t   |\n"
           "    %c    |    %c    |   %c\n"
           "\t |\t   |\n", box[0][0], box[0][1], box[0][2], box[1][0], box[1][1], box[1][2], box[2][0], box[2][1],
           box[2][2]);

}

void title(char name1[20],char name2[20]) {
    system("cls");
    printf("--------------------------------------------\n");
    printf("\t   T i k - T a k - T o e\n");
    printf("\t\t%s is O\n",name1);
    printf("\t\t%s is X\n",name2);
    printf("--------------------------------------------");
    printf("\n");
}
void game(){
    int a = 9;
    int input;

    while (a > 0) {
        title(player1,player2);
        print_box();
        if (a % 2 != 0) {
            printf("%s turn,Enter input: ", player1);
        } else {
            printf("%s turn,Enter input: ", player2);
        }
        fflush(stdin);
        scanf("%d", &input);
        if (input > 9 || input < 1) {
            continue;
        }
        printf("\n");
        if ((check(input))) {
            if (a % 2 == 0) {
                box_cng(input, box, 'X');//x
            } else {
                box_cng(input, box, 'O');//o
            }
            cng_to_num(box, box_x, 'X');
            cng_to_num(box, box_o, 'O');
            if (check_to_win(box_x) || check_to_win(box_o)) {
                if (check_to_win(box_x)) {
                    title(player1,player2);
                    print_box();
                    printf("%s  WIN the Match\n", player2);
                    break;
                } else if (check_to_win(box_o)) {
                    title(player1,player2);
                    print_box();
                    printf("%s  WIN the Match\n", player1);
                    break;
                } else {
                    title(player1,player2);
                    print_box();
                    printf("No one win\n");
                }
            }
            a--;
        } else {
            continue;
        }
    }

}

int main() {
    printf("Enter player1 name:");
    scanf("%s", player1);
    printf("Enter player2 name:");
    scanf("%s", player2);
    title(player1,player2);
    game();
    getch();
    return 0;
}