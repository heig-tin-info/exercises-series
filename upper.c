#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; ++i) {
        char buffer[100];
        if (strlen(argv[i]) > 100) {
            printf("Argument trop long: ignore\n");
            continue;
        }
        strncpy(buffer, argv[i], 100);
        for (int j = 0; j < strlen(buffer); ++j)
            if (buffer[j] >= 'a' && buffer[j] <= 'z')
                buffer[j] -= 'a' - 'A';
        char *p = buffer;
        while (*p != '\0') {
            printf("%c", *p);
            p++;
        }
        puts("");
    }
}