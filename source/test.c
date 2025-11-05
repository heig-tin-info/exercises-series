#include <stdio.h>
int main() {
    int x = 2;
    int y = ++x * ++x;
    printf("%d%d", x, y);
    x = 2;
    y = x++ * ++x;
    printf("%d%d", x, y);
}