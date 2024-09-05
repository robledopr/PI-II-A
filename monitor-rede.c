#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para verificar se a string é um IPv4
int isIPv4(char endereco[]) {
    int numeros = 0, pontos = 0;
    int i, len = strlen(endereco);

    for (i = 0; i < len; i++) {
        if (isdigit(endereco[i])) {
            numeros++;
        } else if (endereco[i] == '.') {
            pontos++;
        } else {
            return 0; // Se não for número nem ponto, não é IPv4
        }
    }

    // Deve haver exatamente 3 pontos e alguns números
    return (pontos == 3 && numeros > 0);
}

// Função para verificar se a string é um IPv6
int isIPv6(char endereco[]) {
    int hexadecimais = 0, dois_pontos = 0;
    int i, len = strlen(endereco);

    for (i = 0; i < len; i++) {
        if (isxdigit(endereco[i])) {
            hexadecimais++;
        } else if (endereco[i] == ':') {
            dois_pontos++;
        } else {
            return 0; // Se não for hexadecimal nem dois pontos, não é IPv6
        }
    }

    // Deve haver pelo menos 2 dois-pontos e alguns caracteres hexadecimais
    return (dois_pontos >= 2 && hexadecimais > 0);
}

int main(){
    printf("*** PROJETO INTEGRADOR II-A***\n");
    printf("Estas são as informações do monitor de rede do grupo 1 (Micael e Robledo)\n");
    char endereco[100];
    char continuar = 's';
    while (continuar == 's') {
        // Lê o endereço IP
        printf("Informe o endereço IP: ");
        scanf("%s", endereco);
        // Verifica se é IPv4 ou IPv6
        if (isIPv4(endereco)) {
            printf("O endereço %s é IPv4.\n", endereco);
        } else if (isIPv6(endereco)) {
            printf("O endereço %s é IPv6.\n", endereco);
        } else {
            printf("O endereço %s não é válido.\n", endereco);
        }
        // Pergunta se o usuário quer verificar outro endereço
        printf("Deseja verificar outro endereço? (s/n): ");
        scanf(" %c", &continuar);
    }
    return 0;
}



