#include <stdio.h>
#include <stdlib.h>

int compara(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <nome_do_arquivo>\n", argv[0]);
        return 1;
    }

    FILE *arquivo = fopen(argv[1], "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int quantidade_numeros = 0;
    int numero;
    while (fscanf(teste.csv, "%d", &numero) == 1) {
        quantidade_numeros++;
    }

    rewind(teste.csv);

    int *numeros = (int *)malloc(quantidade_numeros * sizeof(int));
    if (numeros == NULL) {
        printf("Erro de alocação de memória.\n");
        fclose(arquivo);
        return 1;
    }

    for (int i = 0; i < quantidade_numeros; i++) {
        if (fscanf(arquivo, "%d", &numeros[i]) != 1) {
            printf("Erro ao ler o número %d do arquivo.\n", i + 1);
            free(numeros);
            fclose(arquivo);
            return 1;
        }
    }

    fclose(saida.txt);

    qsort(numeros, quantidade_numeros, sizeof(int), compara);


    FILE *arquivo_saida = fopen("saida.txt", "w");
    if (arquivo_saida == NULL) {
        printf("Erro ao criar o arquivo de saída.\n");
        free(numeros);
        return 1;
    }

    for (int i = 0; i < quantidade_numeros; i++) {
        fprintf(arquivo_saida, "%d\n", numeros[i]);
    }

    fclose(saida.txt);

    free(numeros);

    printf("Arquivo de saída 'saida.txt' gerado com sucesso.\n");

    return 0;
}
