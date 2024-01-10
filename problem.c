#include<stdio.h>

char box[3][3] = {{'1', '2', '3'},
                  {'4', '5', '6'},
                  {'7', '8', '9'}};

void box_cng(int num,char arr[3][3],char ch) {
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
void print_arr(char arr[3][3]){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c  ", arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int a=9;
    while (a>0){
        print_arr(box);
        printf("Enter the number of the box you want to change: ");
        int num;
        fflush(stdin);
        scanf("%d",&num);
        if(num>9 || num<1){
            printf("Invalid input\n");
            continue;
        }
        box_cng(num,box,'x');
        a--;
    }
    return 0;
}














//    printf("\t |\t   |\n"
//           "    1    |    2    |   3\n"
//           "\t |\t   |\n"
//           "---------|---------|---------\n"
//           "\t |\t   |\n"
//           "    4    |    5    |   6\n"
//           "\t |\t   |\n"
//           "---------|---------|--------\n"
//           "\t |\t   |\n"
//           "    7    |    8    |   9\n"
//           "\t |\t   |\n");
