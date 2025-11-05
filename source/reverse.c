#include <stdint.h>
#include <stdio.h>

int32_t reverse(int32_t num) {
    int32_t reversed = 0;

    while (num != 0) {
        // Extraire le dernier chiffre
        int32_t digit = num % 10;

        // Ajouter ce chiffre à la valeur retournée
        reversed = reversed * 10 + digit;

        // Retirer le dernier chiffre
        num /= 10;
    }

    return reversed;
}

// Exemple d'utilisation
int main() {
    int32_t num1 = 123;
    int32_t num2 = 208478933;

    printf("Original: %d, Reversed: %d\n", num1, reverse(num1));
    printf("Original: %d, Reversed: %d\n", num2, reverse(num2));

    return 0;
}
