#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

#define W (30)
const double pi = 3.1415;

void display(bool tab[W][W]) {
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < W; j++)
            printf("%s ", tab[i][j] ? "•" : " ");
        printf("\n");
    }
    fflush(stdout);
}

void spiral(bool tab[W][W], int k, int r, double o) {
    for (int i = 0; i < k; i++) {
        double a = (double)W / 2 / k * i;
        int x = a * cos(r * pi * i / k + o * 2 * pi) + W / 2;
        int y = a * sin(r * pi * i / k + o * 2 * pi) + W / 2;
        tab[x][y] = 1;
    }
}

int main(void) {
    for (int angle = 0; angle < 1000; angle++, usleep(10000)) {
        bool t[W][W] = {0};
        spiral(t, 200 /* iterations */, 5 /* turns */, angle * 0.01);
        display(t);
    }
}
