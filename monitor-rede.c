
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int IPv4(char endereco[]) {       // Função para verificar se a string é um IPv4
    int numeros = 0, pontos = 0, i, tamanho = strlen(endereco);
    for (i = 0; i < tamanho; i++) {
        if (isdigit(endereco[i])) {
            numeros++;
        } else if (endereco[i] == '.') {
            pontos++;
        } else {
            return 0; // Se não for número nem ponto, não é IPv4
        }
    }
    return (pontos == 3 && numeros > 0);            // Deve haver exatamente 3 pontos e alguns números
}

int IPv6(char endereco[]) {           // Função para verificar se a string é um IPv6
    int hexadecimais = 0, dois_pontos = 0, i, tamanho = strlen(endereco);
    for (i = 0; i < tamanho; i++) {
        if (isxdigit(endereco[i])) {
            hexadecimais++;
        } else if (endereco[i] == ':') {
            dois_pontos++;
        } else {
            return 0; // Se não for hexadecimal nem dois pontos, não é IPv6
        }
    }
    return (dois_pontos >= 2 && hexadecimais > 0);              // Deve haver pelo menos 2 dois-pontos e alguns caracteres hexadecimais
}

int main(){
    printf("*** PROJETO INTEGRADOR II-A***\n");
    printf("Estas são as informações do monitor de rede do grupo 1 (Micael e Robledo)\n");
    char endereco[100];
    int continuar = 1;
    while (continuar == 1) {
        printf("Informe o endereço IP: ");         // Lê o endereço IP
        scanf("%s", endereco);
        if (IPv4(endereco)) {                 // Verifica se é IPv4 ou IPv6
            printf("O endereço %s é IPv4.\n", endereco);
        } else if (IPv6(endereco)) {
            printf("O endereço %s é IPv6.\n", endereco);
        } else {
            printf("O endereço %s informado não é válido.\n", endereco);
        }
        printf("\n\nPara verificar outro endereco, digite 1. Para sair, digite 0.\n\n");          // Pergunta se o usuário quer verificar outro endereço
        scanf("%d", &continuar);
    }
    return 0;
}

