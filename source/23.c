#include <stdio.h>

int main() {
    int a[] = {4, 8, 15, 16, 23, 42, 66, 104, 162};
    int *p = a;

    printf("%d\n", *(p+(*p-10)));

}
