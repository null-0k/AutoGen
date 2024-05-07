//#coding : UTF-8
#include <stdio.h>
#include <time.h>

#define SIZE 16
#define HALF_SIZE (SIZE / 2)

int main () {
    srand((unsigned int)time(NULL));
    char *outputs[SIZE][SIZE]; 
    char *symbols[3] = {"+", "|"," "};

    for (int i = 0; i < HALF_SIZE; i++) {
        for (int j = 0; j < HALF_SIZE; j++) {
            char *str = symbols[rand() % 3]; 
            outputs[i][j] = str;
            outputs[i][SIZE - 1 - j] = str;
            outputs[SIZE - 1 - i][j] = str;
            outputs[SIZE - 1 - i][SIZE - 1 - j] = str;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%s ", outputs[i][j]);
        }
        printf("\n");
    }

    return 0;
}
