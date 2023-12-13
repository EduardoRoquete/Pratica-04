#include <stdio.h>
#include <stdlib.h> //system ().

#include "reverso.h"

int main() {
    //Declarar variável
    char* buffer;

    buffer = alocarMemoriaParaBuffer();
    lerDoTecladoGravarEmArquivo("pratica1.c.txt");
    buffer = lerDoArquivoArmazenarEmBuffer("pratica1.c.txt");

    // Calcular o tamanho da string recursivamente
    int tamanho = tamanhoStringRecursiva(buffer, 0);

    printf("Tamanho da string: %d\n", tamanho);

    //Calcular o reverso da string recursivamente
    reversoRecursiva(buffer, 0, tamanho-1);

    // Imprimir a string reversa
    printf("String reversa: %s\n", buffer);

    return 0;
}

