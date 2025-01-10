#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void getInput(char cardNumber[30]);
void reverseCardNumber(char cardNumber[30], char cardNumberReversed[30], int stringLength);
void validateCard(char cardNumberReversed[30], int stringLength);

int main(void) {
    char cardNumber[30];
    char cardNumberReversed[30];

    // Input do usuário
    getInput(cardNumber);

    int stringLength = strlen(cardNumber);
    // Reverte o número do cartão
    reverseCardNumber(cardNumber, cardNumberReversed, stringLength);

    // Valida o cartão
    validateCard(cardNumberReversed, stringLength);

    return 0;
}

void getInput(char cardNumber[30]) {
    do {
        printf("Type your card number: ");
        scanf("%29s", cardNumber);
        while (getchar() != '\n'); 
    } while (cardNumber[0] == '-' || strlen(cardNumber) < 10); // Valida que o primeiro char não é '-'
}

void reverseCardNumber(char cardNumber[30], char cardNumberReversed[30], int stringLength) {
    int j = 0;

    // I tem que ser definido como stringLenght - 1 porque a função strlen() descarta o último char que no caso é o caractere nulo que existe no final das strings ("\0")
    // Se não for definido como stringLength -1, então ele irá tentar buscar um caractere inexistente, e no final não printará nada por conta desse comportamento.
    for (int i = stringLength - 1; i >= 0; i--, j++) {
        cardNumberReversed[j] = cardNumber[i];
    }
    
    cardNumberReversed[j] = '\0';
}

void validateCard(char cardNumberReversed[30], int stringLength) {
    char numbersToMultiply[30] = "";
    int sumNotMultiply, sumMultiplied, j = 0;

    for (int i = 1; i < stringLength; i += 2, j += 2) {
        sumNotMultiply += cardNumberReversed[j] - '0';
        
        int calculated = (cardNumberReversed[i] - '0') * 2;

        char temp[3];
        sprintf(temp, "%d", calculated);

        strcat(numbersToMultiply, temp);
    }

    for (int i = 0; i < strlen(numbersToMultiply) - 1; i++) {
        sumMultiplied += numbersToMultiply[i] - '0';
    }

    int result = sumMultiplied + sumNotMultiply;
    char temp[3];
    
    sprintf(temp, "%d", result);

    int i = strlen(temp) - 1;

    int isNumberValid = temp[i] - '0';

    if (isNumberValid == 0) {
        printf("Your card is valid.");
    } else {
        printf("Invalid card.");
    }
}

//Teste: 4003 6000 0000 0014