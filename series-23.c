#include <stdio.h>
#include <stdint.h>

int main() {
    int a[] = {4, 8, 15, 16, 23, 42, 66, 104, 162};
    int *p = a;

    printf("a. %d\n", *p+2);
    printf("b. %d\n", *(p+2));
    printf("c. %p\n", &a[4]-3);
    printf("d. %p\n", a + 3);
    printf("e. %ld\n", &a[7]-p);
    printf("f. %p\n", p+(*p-10));
    printf("g. %d\n", *(p+*(p+4)-a[3]));
    printf("h. %d\n", (p+1)[2]);
    printf("i. %d\n", 5[p]);
    printf("j. %ld\n", (uintptr_t)(p + 3) - (uintptr_t)a);
    printf("k. %d\n", (&a)[1][-1]);
}
