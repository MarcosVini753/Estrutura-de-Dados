// g++ try.cpp -O2 -Wall; type stdin | ./a > stdout
#include <bits/stdc++.h>
// Função heapify (coração do HeapSort)
void heapify(int arr[], int n, int i) {
    int largest = i;       // trata a raiz passada como o maior
    int left = 2 * i + 1;  // Filho da esquerda
    int right = 2 * i + 2; // Filho da direita

    // Se o filho da esquerda é maior que a raiz
    if (left < n && arr[left] > arr[largest]) largest = left;

    // Se o filho da direita é maior 
    if (right < n && arr[right] > arr[largest]) largest = right;
   
    if (largest != i) { // Se o maior não é a raiz
        // Troca a raiz com o maior
        int aux = arr[i];
        arr[i] = arr[largest];
        arr[largest] = aux;

        // Aplica heapify na subárvore 
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {

    // Constrói a ávore heap
    for (int i = n/2 - 1; i >= 0; i--) heapify(arr, n, i);

    // Extrai os elementos do heap um por um
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz (maior elemento) para o final
        int aux = arr[0];
        arr[0] = arr[i];
        arr[i] = aux;

        // Aplica heapify no heap reduzido
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]); 
    printf("\n");
}

int main() {
    int n; scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Array recebido: "); printArray(arr, n);

    heapSort(arr, n);
    
    printf("Array ordenado: "); printArray(arr, n);

    return 0;
}
