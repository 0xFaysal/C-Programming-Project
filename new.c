#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>

char name[20];

void title(char name[]);
void menu();
void game(int level);
void againPlay();
int main(){
    srand(time(NULL));
    system("color 0F");
    printf("\e[36mEnter your nick name:\a");
    scanf("%s",name);
    system("cls");
    title(name);
    menu();

    getch();
}



void title(char name[]) {
    system("cls");
    system("color 11");
    printf("---------------------------------------------\n");
    printf("\t \e[32m G u e s s i n g   G a m e\e[36m\n");
    printf("\t      Hello!!\e[33m %s\t\e[36m\n",name);
    printf("---------------------------------------------\n");

}
void menu(){
    int level;
    printf(" Game level:\n");
    printf(" 1.Easy\n 2.Medium\n 3.Hard\n 4.Exit\n");
    printf("---------------------------------------------\n");
    printf("Choose your level:");
    scanf("%d",&level);
    switch (level) {
        case 1:
            game(7);
            break;
        case 2:
            game(5);
            break;
        case 3:
            game(3);
            break;
        case 4:
            exit(1);
        default:
            menu();
            break;
    }
}

void game(int level){
    int min=0,max=100;
    int number,levelLeft=level;
    title(name);
    int randomNumber= min + rand() % (max + 1 - min);


    printf("You have %d chance to guess the number to WIN.\n",level);
    for (int i = 1; i <=level ; i++) {
        printf("Enter your guess:\e[33m");
        scanf("%d",&number);
        printf("\e[36m");
        if (number==randomNumber){
            printf("\e[32mRight guess....\nYou win..........\e[36m\n");
            againPlay();
        } else{
            if((level-i)>0){

            printf("Ah hh... \nWrong Guess.....\n");
            if(number>randomNumber){
                printf("Your guess is\e[35m HIGH\e[36m!!\nTry again.......\n");
            } else{
                printf("Your guess is \e[35mLOW\e[36m!!\nTry again.......\n");
            }
            levelLeft--;
            printf("\e[31mYou have %d chance left\e[36m\n",levelLeft);
            } else{
                printf("You lose........:(\n");
                printf("The number is %d\n",randomNumber);
                againPlay();
            }
        }
    }
}
void againPlay(){
    char input;
    fflush(stdin);
    printf("Do you want to play again(y/n):\e[33m");
    scanf("%c", &input);
    printf("\e[36m");
    if (input =='y'|| input =='Y'){
        title(name);
        menu();
    } else{
        exit(1);
    }
}
