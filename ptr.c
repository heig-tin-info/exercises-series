#include <stdio.h>
#include <stdlib.h>

size_t f(int a[]) {
    return sizeof(a);
}

int main() {
    int a[10];
    printf("%ld\n", sizeof(a));
    printf("%ld\n", f(a));
}