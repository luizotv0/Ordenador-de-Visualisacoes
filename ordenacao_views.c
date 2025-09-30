#include <stdio.h>

#define N 10  // número de músicas (tamanho do vetor)

/*
  Programa: Ordenação com Bubble Sort
  Tema: Visualizações de músicas
  - Lê N valores do tipo long long (permite números na casa de bilhões)
  - Exibe o vetor original
  - Ordena em ordem crescente e exibe
  - Ordena em ordem decrescente e exibe
*/

/* 
   Função bubbleSort:
   - Parâmetros:
       v[]       : vetor de long long a ser ordenado
       n         : tamanho do vetor
       ascending : se 1 -> crescente; se 0 -> decrescente
   - Lógica:
       Percorre o vetor várias vezes comparando elementos vizinhos.
       Troca de posição se estiverem fora da ordem desejada.
       A cada passagem, o maior (ou menor) valor "bolha" para sua posição final.
*/
void bubbleSort(long long v[], int n, int ascending) {
    int i, j;
    long long aux;
    for (i = 0; i < n - 1; i++) {
        int trocou = 0; // flag para detectar se houve troca nesta passagem
        for (j = 0; j < n - i - 1; j++) {
            // Verifica se precisa trocar baseado na direção da ordenação
            if ((ascending && v[j] > v[j+1]) || (!ascending && v[j] < v[j+1])) {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
                trocou = 1; // marcou que houve troca
            }
        }
        if (!trocou) break; // Se não houve troca, vetor já está ordenado
    }
}

/* 
   Função imprimir:
   - Imprime os elementos do vetor com separador vírgula e espaço
   - Usamos %lld para long long
*/
void imprimir(long long v[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%lld", v[i]);
        if (i < n - 1) printf(", ");
    }
    printf("\n");
}

int main() {
    long long visualizacoes[N]; // vetor que guarda as visualizações (inteiros grandes)
    int i;

    // Entrada de dados
    printf("Digite o numero de visualizacoes (ate a casa de bilhoes) das %d musicas:\n", N);
    for (i = 0; i < N; i++) {
        printf("Musica %d: ", i + 1);
        while (scanf("%lld", &visualizacoes[i]) != 1) { // leitura de long long
            int c;
            while ((c = getchar()) != '\n' && c != EOF); // limpa buffer
            printf("Entrada invalida. Digite um numero inteiro valido para Musica %d: ", i + 1);
        }
    }

    // Exibe o vetor original
    printf("\nVisualizacoes originais:\n");
    imprimir(visualizacoes, N);

    // Ordena em ordem crescente
    bubbleSort(visualizacoes, N, 1);
    printf("\nVisualizacoes em ordem crescente (menor para maior):\n");
    imprimir(visualizacoes, N);

    // Ordena em ordem decrescente
    bubbleSort(visualizacoes, N, 0);
    printf("\nVisualizacoes em ordem decrescente (maior para menor):\n");
    imprimir(visualizacoes, N);

    return 0;
}
