#include <stdio.h>;
#include <string.h>;
#include <math.h>;

void main (void) {

    int cardNumber;

    do {
        printf("Type your card number:");
        scanf("%d",&cardNumber);
        while (getchar() != '\n');

    } while (cardNumber < 0);

    validateCard(cardNumber);
}

void validateCard (cardNumber) {
    int cardNumberReversed;

    for (int i = 0; i < cardNumber; i++) {
        cardNumberReversed;
    }
}