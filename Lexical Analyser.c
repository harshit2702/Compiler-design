#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

const char *keywords[] = { "if", "else", "while", "for", "do", "int", "float", "char", "double", "return" };
const int num_keywords = 10;

int is_keyword(char *str) {
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}
char *operators[] = {"+","-","*","/","%","^"};
int is_operator(char *str) {
    for (int i = 0; i < 6; i++) {
        if (strcmp(str, operators[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void lexicalanalyser(char *code){
    int i =0;
    char *p = " ";
    char *p1 = "\0";
    char *p2 = ";";

    while(code[i]){
    if(isdigit(code[i])){
            char num[100];
            int j=0;
            num[j++] = code[i];
            i++;
            while (isdigit(code[i])) {
                num[j++] = code[i];
                i++;
            }
            num[j] = '\0';
            printf("NUMBER %s\n", num);
        }
    else if (isalpha(code[i])) {
            char word[100];
            int j = 0 ;
            word[j++] = code[i];
            i++;
            while (isalpha(code[i])) {
                word[j++] = code[i];
                i++;
            }
            word[j]= '\0';
            if(is_keyword(word)){
                printf("keyword %s\n", word);
            }else{
                printf("identifier %s\n", word);
            }
    }
    else if((code[i] != *p) && (code[i] != *p1) && (code[i] != *p2)){
        char Operator[10];
        int j = 0;
        Operator[j++] = code[i];
        i++;
        while(code[i] != *p){
            Operator[i++] = code[i];
            i++;
        }
        Operator[j] = '\0';
        printf("Operator %s\n",Operator);
    }
    else{
        i++;
    }
    }
}
int main()
{
    char *p = "int a = 20;";
    lexicalanalyser(p);
    return 0;
}