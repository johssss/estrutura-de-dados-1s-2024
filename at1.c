#include <stdio.h>
#include <stdlib.h>

// Função para ordenar os números em ordem crescente
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    printf("Digite a quantidade de numeros: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Erro: Nenhum numero informado.\n");
        return 1;
    }

    int *numeros = (int *)malloc(n * sizeof(int));

    printf("Digite os numeros:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &numeros[i]);
    }

    // Calculando a média
    double media = 0;
    for (i = 0; i < n; i++) {
        media += numeros[i];
    }
    media /= n;

    // Ordenando os números
    bubbleSort(numeros, n);

    // Imprimindo os resultados
    printf("\nQuantidade de numeros: %d\n", n);
    printf("Valor medio dos numeros: %.2f\n", media);
    printf("Menor numero: %d\n", numeros[0]);
    printf("Maior numero: %d\n", numeros[n - 1]);
    printf("Numeros em ordem crescente:");
    for (i = 0; i < n; i++) {
        printf(" %d", numeros[i]);
    }
    printf("\n");

    free(numeros); // Liberando a memória alocada

    return 0;
}
