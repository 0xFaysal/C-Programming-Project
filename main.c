#include<stdio.h>
#include <windows.h>
#include<string.h>

int main(){
    char sentence[]="My name is  Faysal Ahmed .\nI am a student of Computer Science and Engineering. \nI am from Bangladesh. \nI am a Bangladeshi. \nI love my country. \nI love my family. \nI love my friends. \nI love my teachers. \nI love my university. \nI love my department. \nI love my classmates.";

    for (int i = 0; i <= strlen(sentence); ++i) {
    printf("%c",sentence[i]);
    Sleep(200);
    }
//    printf("%s",sentence);
    getchar();
    return 0;
}