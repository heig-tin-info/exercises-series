#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
int main() {
    int columns = 10;
    assert(columns < UINT8_MAX);
    uint8_t (*grid)[][columns] = calloc(sizeof(uint8_t), columns * columns);
    assert(grid != NULL);

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            printf("%d ", (*grid)[i][j]);
        }
        printf("\n");
    }
}