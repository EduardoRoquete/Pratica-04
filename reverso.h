#include <stdio.h>
#include <stdlib.h>

char* alocarMemoriaParaBuffer() {
    char* buffer;
    buffer = (char*)malloc(sizeof(char) * 256);
    if (buffer == NULL) {
        printf("Erro ao alocar memória para o buffer.");
        exit(1);
    }
    return buffer;
}

void lerDoTecladoGravarEmArquivo(char caminhoDoArquivo[256]) {
    // Declarar variável
    int ch;
    char* buffer;
    buffer = alocarMemoriaParaBuffer();

    /*
    * Ler a string a partir do teclado e armazenar em arquivo.
    */
    // Abrir o arquivo em modo leitura e escrita
    FILE* arquivo = fopen(caminhoDoArquivo, "w");

    // Verificar se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        exit(1); // Terminar o programa com erro
    }

    // Ler a string e armazenar no arquivo
    printf("\nInforme a linha para o arquivo:\n");
    while ((ch = getchar()) != '\n')
        putc(ch, arquivo);
    putc('\n', arquivo);

    // Fechar o arquivo
    fclose(arquivo);
}

char* lerDoArquivoArmazenarEmBuffer(char caminhoDoArquivo[256]) {
    // Declarar variável
    int i, ch;
    char* buffer;
    buffer = alocarMemoriaParaBuffer();

    /*
    * Ler a string a partir do arquivo e armazenar em um buffer na memória principal.
    */
    // Abrir o arquivo em modo leitura e escrita
    FILE* arquivo = fopen(caminhoDoArquivo, "r");

    // Verificar se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        exit(1); // Terminar o programa com erro
    }

    // Ler a string do arquivo
    i = 0;
    while ((ch = getc(arquivo)) != '\n')
        buffer[i++] = ch;
    buffer[i] = '\0';

    // Fechar o arquivo
    fclose(arquivo);

    return buffer;
}

// Função recursiva para calcular o tamanho da string
int tamanhoStringRecursiva(char* buffer, int posicao) {
    // Caso base: se o caractere atual for o final da string ('\0'), retorne 0
    if (buffer[posicao] == '\0') {
        return 0;
    } else {
        // Chamada recursiva para o restante da string e adicione 1 ao resultado
        return 1 + tamanhoStringRecursiva(buffer, ++posicao);
    }
}

// Função recursiva para inverter a string
void reversoRecursiva(char buffer[256], int inicio, int fim) {
    // Caso base: se o início for maior ou igual ao fim, não há mais caracteres para trocar
    if (inicio >= fim) {
        return;
    } else {
        // Troca os caracteres nas posições inicio e fim
        char aux = buffer[inicio];
        buffer[inicio] = buffer[fim];
        buffer[fim] = aux;

        // Chamada recursiva para o restante da string
        reversoRecursiva(buffer, inicio + 1, fim - 1);
    }
}
