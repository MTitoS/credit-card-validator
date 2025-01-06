#include <stdio.h>
#include <string.h>

int reverseCardNumber (char cardNumber[30]);

void main (void) {
    char cardNumber[30];

    do {
        printf("Type your card number: ");
        scanf("%s", cardNumber);
        while (getchar() != '\n');

    } while (cardNumber[0] == '-');

    reverseCardNumber(cardNumber);
}

int reverseCardNumber (char cardNumber[30]) {
    char cardNumberReversed[30];
    int stringLength = strlen(cardNumber);
    int j = 0;

    // I tem que ser definido como stringLenght - 1 porque a função strlen() descarta o último char que no caso é o caractere nulo que existe no final das strings ("\0")
    // Se não for definido como stringLength -1, então ele irá tentar buscar um caractere inexistente, e no final não printará nada por conta desse comportamento.
    for (int i = stringLength - 1; i >= 0; i--, j++) {
        cardNumberReversed[j] = cardNumber[i];
    }
    
    cardNumberReversed[j] = '\0';

    printf("Credit card number reversed: %s\n", cardNumberReversed);

    return 0;
}