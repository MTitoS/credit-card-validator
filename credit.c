#include <stdio.h>
#include <string.h>

void reverseCardNumber(char cardNumber[30], char cardNumberReversed[30]);
void getInput(char cardNumber[30]);
void validateCard(char cardNumberReversed[30]);

int main(void) {
    char cardNumber[30];
    char cardNumberReversed[30];
    
    // Input do usuário
    getInput(cardNumber);

    // Reverte o número do cartão
    reverseCardNumber(cardNumber, cardNumberReversed);

    // Valida o cartão
    validateCard(cardNumberReversed);

    return 0;
}

void getInput(char cardNumber[30]) {
    do {
        printf("Type your card number: ");
        scanf("%29s", cardNumber);
        while (getchar() != '\n'); 
    } while (cardNumber[0] == '-'); // Valida que o primeiro char não é '-'
}

void reverseCardNumber(char cardNumber[30], char cardNumberReversed[30]) {
    int stringLength = strlen(cardNumber);
    int j = 0;

    // I tem que ser definido como stringLenght - 1 porque a função strlen() descarta o último char que no caso é o caractere nulo que existe no final das strings ("\0")
    // Se não for definido como stringLength -1, então ele irá tentar buscar um caractere inexistente, e no final não printará nada por conta desse comportamento.
    for (int i = stringLength - 1; i >= 0; i--, j++) {
        cardNumberReversed[j] = cardNumber[i];
    }
    
    cardNumberReversed[j] = '\0';
}

void validateCard(char cardNumberReversed[30]) {

}
