#include <stdio.h>
#include <time.h>

// Função para ordenar o array usando Selection Sort
// O Selection Sort percorre o array várias vezes, procurando o menor (ou maior) valor em cada iteração 
// e o coloca na posição correta, até que toda a lista esteja ordenada.
void selectionSort(int arr[], const int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i; // Índice do menor elemento encontrado
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Troca os elementos
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Função para ordenar o array usando Insertion Sort
// O Insertion Sort trabalha "inserindo" cada elemento na posição correta em uma parte do array
// que já está ordenada. É similar ao processo de ordenar cartas de baralho em mãos.
void insertionSort(int arr[], const int n) {
    for (int i = 1; i < n; i++) {
        int chave = arr[i], j = i - 1;
        // Move elementos maiores que a chave para uma posição à frente
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];  // Mover para a direita
            j--;  // Decrementar j, não usar o operador j--
        }
        arr[j + 1] = chave; // Insere a chave na posição correta
    }
}

// Função para ordenar o array usando Bubble Sort
// O Bubble Sort compara elementos adjacentes do array e os troca de lugar caso estejam fora de ordem.
// O maior (ou menor) elemento "borbulha" para o final do array a cada iteração.
void bubbleSort(int arr[], const int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) { // Se o elemento atual é maior, faz a troca
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Função para ordenar o array usando Merge Sort
// O Merge Sort utiliza o conceito de "dividir para conquistar". O array é repetidamente dividido ao meio até que
// as sublistas contenham apenas um elemento, e então as sublistas são unidas de volta em uma ordem ordenada.
void mergeSort(int arr[], const int l, const int r) {
    if (l < r) {
        int m = l + (r - l) / 2;  // Ponto médio
        mergeSort(arr, l, m);      // Ordena a primeira metade
        mergeSort(arr, m + 1, r);  // Ordena a segunda metade
        
        // Mesclagem das duas metades
        int n1 = m - l + 1, n2 = r - m, L[n1], R[n2];
        for (int i = 0; i < n1; i++) L[i] = arr[l + i];
        for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
        
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
        }
        while (i < n1) arr[k++] = L[i++]; // Copia elementos restantes de L, se houver
        while (j < n2) arr[k++] = R[j++]; // Copia elementos restantes de R, se houver
    }
}

// Função para ordenar o array usando Quick Sort
// O Quick Sort escolhe um "pivô" e particiona o array em dois sub-arrays, um com elementos menores que o pivô
// e outro com elementos maiores. Depois, os sub-arrays são ordenados recursivamente.
void quickSort(int arr[], const int baixo, const int alto) {
    if (baixo < alto) {
        int pivo = arr[alto], i = (baixo - 1);
        for (int j = baixo; j < alto; j++) {
            if (arr[j] <= pivo) { // Coloca os elementos menores que o pivô à esquerda
                int temp = arr[++i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[alto];
        arr[alto] = temp;
        int pi = i + 1; // Índice final do pivô
        
        // Recursão à esquerda e à direita do pivô
        quickSort(arr, baixo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}

// Função para ordenar o array usando Heap Sort
// O Heap Sort constrói uma estrutura de heap (uma árvore binária) onde o maior elemento fica na raiz,
// e então retira esse elemento e reconstrói o heap até que todos os elementos estejam ordenados.
// Função para ordenar o array usando Heap Sort
void heapify(int arr[], int n, int i) {
    int maior = i; // Inicializa o maior como raiz
    int esquerda = 2 * i + 1; // Índice da esquerda
    int direita = 2 * i + 2; // Índice da direita

    // Verifica se o filho à esquerda existe e é maior que a raiz
    if (esquerda < n && arr[esquerda] > arr[maior]) {
        maior = esquerda;
    }

    // Verifica se o filho à direita existe e é maior que o maior até agora
    if (direita < n && arr[direita] > arr[maior]) {
        maior = direita;
    }

    // Se o maior não for a raiz, troca e continua o heapify
    if (maior != i) {
        int temp = arr[i];
        arr[i] = arr[maior];
        arr[maior] = temp;

        // Recursivamente chama heapify na sub-árvore afetada
        heapify(arr, n, maior);
    }
}

void heapSort(int arr[], const int n) {
    // Constrói o heap (ordem dos elementos não garantida ainda)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extrai elementos do heap um por um
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual para o final
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Chama heapify na raiz
        heapify(arr, i, 0);
    }
}


// Função para exibir o array
void exibirArray(const int arr[], const int n) {
    printf("Array ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função para exibir o menu e executar o algoritmo selecionado
void menu() {
    int arr[] = {189, 314, 92, 930, 22, 190, 8000, 2910, 910, 189, 999, 199, 100, 1000, 10000, 50000, 100000}; // Array inicial
    const int n = sizeof(arr) / sizeof(arr[0]);
    int escolha;

    do {
        printf("\nEscolha o algoritmo de ordenação:\n");
        printf("1. Selection Sort\n2. Insertion Sort\n3. Bubble Sort\n");
        printf("4. Merge Sort\n5. Quick Sort\n6. Heap Sort\n7. Sair\nOpção: ");
        
        // Verifica se a entrada é válida
        if (scanf("%d", &escolha) != 1 || escolha < 1 || escolha > 7) {
            printf("Entrada inválida! Tente novamente.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
            continue;
        }

        // Marca o início do tempo de execução
        clock_t inicio = clock();
        
        // Processa a opção escolhida
        switch (escolha) {
            case 1: selectionSort(arr, n); break;
            case 2: insertionSort(arr, n); break;
            case 3: bubbleSort(arr, n); break;
            case 4: mergeSort(arr, 0, n - 1); break;
            case 5: quickSort(arr, 0, n - 1); break;
            case 6: heapSort(arr, n); break;
            case 7: printf("Saindo do programa...\n"); return;
            default: break;
        }

        // Calcula o tempo de execução do algoritmo
        double tempoExecucao = ((double)(clock() - inicio)) / CLOCKS_PER_SEC;
        printf("Tempo de execução: %.6f segundos\n", tempoExecucao); // Exibe o tempo com 6 casas
        exibirArray(arr, n);

    } while (escolha != 7);
}

int main() {
    menu();
    return 0;
}
