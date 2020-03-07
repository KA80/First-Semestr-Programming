#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//паттерн//
int pattern(char** argv){
    for (int i = 1; argv[i] != NULL; i++){
        if ((argv[i][0] != '-') && (argv[i - 1][1] != 'm'))
            return i;
    }
}

//опция//
int option(char** argv, int pat, int j){
    for (int i = pat; i < j; i++){
        if (argv[i][0] == '-') {
            switch(argv[i][1]){
                case 'v':{
                    return 1;
                }
                case 'H':{
                    return 2;
                }
                case 'h':{
                    return 3;
                }
                case 'm':{
                    if (atoi(argv[i + 1]) != 0) return 4;
                    else{
                        printf("%s: invalid max count\n", argv[0]);
                        exit(0);
                    }
                }
                case 'c':{
                    return 5;
                }
            }
        }
    }
    return 0;
}

//количество файлов//
int amountFiles(char** argv, int pat){
    int amount = 0;
    for (int i = pat + 1; argv[i] != NULL; i++) amount++;
    return amount;
}

//optionH
void H(char* filename){
    printf("%s:",filename);
}

//optionM
int M(char** argv){
    int i = 1;
    while (argv[i - 1][1] != 'm') i++;
    return atoi(argv[i]);
}

//Print
void print(FILE* file, char* filename, int optionV, int optionH, int optionM, int optionC, char* patname, int numM, char** argv){
    char string[1000][1000] = {0};
    int i = 0;
    if (file == NULL){
        printf("%s: %s: No such file or directory\n",argv[0], filename);
        return;
    }
    while(fgets(string[i], 1000, file) != NULL){
        if ((optionM == 0) && (numM == i)) break;
        if (((optionV == 0) && !strstr(string[i], patname)) || (strstr(string[i], patname) && (optionV == 1))){
            if (optionC == 1){
                if (optionH == 0) H(filename);
                printf("%s\n", string[i]);
            }
            i++;
        }
    }
    if (optionC == 0){
        if (numM >= i){
            if (optionH == 0) H(filename);
            printf("%d\n", numM);
        }
        else{
            if (optionH == 0) H(filename);
            printf("%d\n", i);
        }
    }
}

int main(int argc, char** argv) {
    int Pattern = pattern(argv);
    char PatternName[100] = {0};
    for(int i = 0; i < strlen(argv[Pattern]); i++)
        PatternName[i] = argv[Pattern][i];
    int AmountFiles = amountFiles(argv, Pattern);
    int optionH = 1; // 0 - печатает , 1 - не печатает имя файла
    int optionV = 1; // 0 - инвертировать, 1 - не инвертировать
    int optionM = 1;
    int optionC = 1;
    if (AmountFiles > 1) optionH = 0;
    for(int i = 1; i < Pattern; i++){
        // optionV = optionV && (option(argv, i, Pattern) != 1);
        if (option(argv, i, Pattern) == 1) optionV = 0;
        if (option(argv, i, Pattern) == 2) optionH = 0;
        if (option(argv, i, Pattern) == 3) optionH = 1;
        if (option(argv, i, Pattern) == 4) optionM = 0;
        if (option(argv, i, Pattern) == 5) optionC = 0;
    }
    int numM = 0;
    if (optionM == 0)
        numM = M(argv);
    if(AmountFiles == 0){
        FILE* file = stdin;
        char filename[100] = {"(standart input)"};
        print(file, filename, optionV, optionH, optionM, optionC, PatternName, numM, argv );
    }
    else{
        FILE* file[AmountFiles];
        for (int i = 0; i < AmountFiles; i++) {
            file[i] = fopen(argv[Pattern + 1 + i], "r");
            print(file[i], argv[Pattern + 1 + i], optionV, optionH, optionM, optionC, PatternName, numM, argv);
        }
    }
    return 0;
}
