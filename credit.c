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
    // Se não for definido como stringLength - 1, então ele irá tentar buscar um caractere inexistente, e no final não printará nada por conta desse comportamento.
    for (int i = stringLength - 1; i >= 0; i--, j++) {
        cardNumberReversed[j] = cardNumber[i];
    }
    
    cardNumberReversed[j] = '\0';
}

void validateCard(char cardNumberReversed[30], int stringLength) {
    char numbersToMultiply[30] = "";
    int sumNotMultiply, sumMultiplied, j = 0;

    //O for vai percorrer por toda a stringlength definida já na chamada da função (tamanho da variável cardNumber)
    for (int i = 1; i < stringLength; i += 2, j += 2) {
        //Somar os números que não precisam ser multiplicados (logo, não terão mais que 1 dígito).
        sumNotMultiply += cardNumberReversed[j] - '0';
        
        //Para utilizar os números que vão ser multiplicados, ele primeiro calcula cada um e adiciona na variável calculated
        int calculated = (cardNumberReversed[i] - '0') * 2;

        //Criação de variável temporária, convertendo para char. Variável cabe apenas 2 dígitos e o operador nulo pois não há necessidade de ser maior
        char temp[3];
        sprintf(temp, "%d", calculated);

        //Como foi adicionado como char, e isso é feito a cada loop, vai concatenando as strings até terminar o for.
        strcat(numbersToMultiply, temp);
    }

    for (int i = 0; i < strlen(numbersToMultiply) - 1; i++) {
        //Percorre os números novamente para pegar dígito por dígito e então soma.
        sumMultiplied += numbersToMultiply[i] - '0';
    }

    //Calcula os dígitos multiplicados e soma com os não multiplicados lá do primeiro loop. 
    //Variável de resultado que será convertida em string e jogada na temp
    int result = sumMultiplied + sumNotMultiply;
    char temp[3];
    
    sprintf(temp, "%d", result);

    int i = strlen(temp) - 1;

    //Vai pegar apenas o último dígito (strlen - 1), transformando em int (- '0') e passando para variável.
    int isNumberValid = temp[i] - '0';

    //Explicação Harvard: If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid
    if (isNumberValid == 0) {
        printf("Your card is valid.");
    } else {
        printf("Invalid card.");
    }
}

//Teste: 4003 6000 0000 0014