// coding : UTF-8
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define SIZE 16
#define HALF_SIZE (SIZE / 2)
#define SYMBOL_ROWS 5
#define SYMBOL_COLS 3

// The symbols array uses full-width Japanese characters
const char *symbols[SYMBOL_ROWS][SYMBOL_COLS] = {
    {"＋", "｜", "　"}, // + | space
    {"＋", "ー", "　"}, // + - space
    {"／", "＼", "　"}, // / \ space
    {"｜", "ー", "　"}, // | - space
    {"／", "／", "　"}  // / / space
};

void draw() {
    // Initialize all elements to NULL
    const char *output[SIZE][SIZE] = {0}; 

    int id_symbol = rand() % SYMBOL_ROWS;
    
    // Generate a point-symmetric pattern
    for (int i = 0; i < HALF_SIZE; i++) {
        for (int j = 0; j < HALF_SIZE; j++) {
            const char *str = symbols[id_symbol][rand() % SYMBOL_COLS];

            output[i][j] = str;
            output[i][SIZE - 1 - j] = str;
            output[SIZE - 1 - i][j] = str;
            output[SIZE - 1 - i][SIZE - 1 - j] = str;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%s", output[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    srand((unsigned int)time(NULL));

    draw();

    return 0;
}

