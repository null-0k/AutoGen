//#coding : UTF-8
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define SIZE 16
#define HALF_SIZE (SIZE / 2)

int main () {
    setlocale(LC_ALL, "");  // ロケールを設定
    char *outputs[SIZE][SIZE]; 
    char *symbols[5][3] = {
        {"＋", "｜", "\xE3\x80\x80"}, // +|(space)
        {"＋", "ー", "\xE3\x80\x80"}, // +-(space)
        {"／", "＼", "\xE3\x80\x80"}, // /\(space)
        {"｜", "ー", "\xE3\x80\x80"}, // |-(space)
        {"／", "／", "\xE3\x80\x80"}  // //(space)
    };

    srand((unsigned int)time(NULL));
    
    //点対照のパターンを生成
    for (int i = 0; i < HALF_SIZE; i++) {
        for (int j = 0; j < HALF_SIZE; j++) {
            char *str = symbols[rand() % 5][rand() % 3];
            outputs[i][j] = str;
            outputs[i][SIZE - 1 - j] = str;
            outputs[SIZE - 1 - i][j] = str;
            outputs[SIZE - 1 - i][SIZE - 1 - j] = str;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%s", outputs[i][j]);
        }
        printf("\n");
    }

    return 0;
}

