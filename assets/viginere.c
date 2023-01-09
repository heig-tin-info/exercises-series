#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_all_lowercase(char *str, size_t length)
{
    while (*(str++))
    {
        char c = *str;

        if (c < 'a' && c > 'z' && c != ' ')
        {
            return false;
        }
    }
    return true;
}

void viginere(char *message, const char *key)
{
    size_t klen = strlen(key);

    for (size_t i = 0, j = 0; i < strlen(message); i++)
    {
        char k = key[j % klen] - 'a';
        char c = message[i];
        if (c >= 'a' && c <= 'z') {
            c = 'a' + (c - 'a' + k) % 26;
            j++;
        }

        printf("%c", c);
    }
}

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        printf("Wrong number of arguments. Please try again.\n");
        return 1;
    }

    char *key = argv[1];
    char *message = argv[2];

    if (!is_all_lowercase(message, strlen(message))) {
        printf("Message must be lowercase only.");
        return 2;
    }

    if (!is_all_lowercase(key, strlen(key))) {
        printf("Key must be lowercase only.");
        return 3;
    }

    viginere(message, key);

    printf("\n");

    return 0;
}
