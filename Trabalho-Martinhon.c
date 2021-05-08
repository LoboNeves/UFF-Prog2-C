#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//OBS:Testado no VScode e em mais 3 compiladores online para ter certeza de que estava funcionando

int main(){
    long int tamanho_vetor, min, max, i;

    printf("Digite o tamanho do vetor:");       
    scanf("%li", &tamanho_vetor);               //Input do tamanho do vetor
    printf("Digite o valor minimo do vetor:");
    scanf("%li", &min);                         //Input do valor mínimo
    printf("Digite o valor maximo do vetor:");
    scanf("%li", &max);                         //Input do valor máximo

    long int vetor_original[tamanho_vetor];     //Vetor original com o tamanho dado por input
    long int vetor_bubble[tamanho_vetor];       //Cópias do vetor para usar ponteiros em cada função sem alterar o vetor original
    long int vetor_insertion[tamanho_vetor]; 
    long int vetor_selection[tamanho_vetor];
    long int vetor_merge[tamanho_vetor];
    long int vetor_quick[tamanho_vetor];
    long int vetor_shell[tamanho_vetor];
    long int vetor_counting[tamanho_vetor];
    long int vetor_random_quick[tamanho_vetor];

    void Gera_Vetor_Aleatorio(long int *A, long int min, long int max, long int N); //Protótipos de funções
    void Bubble_Sort(long int *A, long int N);
    void Insertion_Sort(long int *A, long int N);
    void Selection_Sort(long int *A, long int N);
    void Merge_Sort(long int *A, long int min, long int max);
    void Merge(long int *A, long int min, long int max, long int meio);
    void Count_Merge_Sort(long int *A, long int min, long int max);
    void Quick_Sort(long int *A, long int min, long int max);
    void Count_Quick_Sort(long int *A, long int min, long int max);
    void Shell_Sort(long int *A, long int N);  //Além dos metódos pedidos consegui adicionar o Shell sort como bônus
    void Counting_Sort(long int *A, long int N, long int max);
    int particao_pivot(long int *A, long int min, long int max);
    void Random_Quick_Sort(long int *A, long int min, long int max);
    void Count_Random_Quick_Sort(long int *A, long int min, long int max);

    Gera_Vetor_Aleatorio(vetor_original, min, max, tamanho_vetor); //Gerando números aleatórios no vetor original

    for(i = 0;i < tamanho_vetor;i++)vetor_bubble[i]=vetor_original[i];      //Realizando as cópias do vetor para cada operação
    for(i = 0;i < tamanho_vetor;i++)vetor_insertion[i]=vetor_original[i];
    for(i = 0;i < tamanho_vetor;i++)vetor_selection[i]=vetor_original[i];
    for(i = 0;i < tamanho_vetor;i++)vetor_merge[i]=vetor_original[i];
    for(i = 0;i < tamanho_vetor;i++)vetor_quick[i]=vetor_original[i];
    for(i = 0;i < tamanho_vetor;i++)vetor_shell[i]=vetor_original[i];
    for(i = 0;i < tamanho_vetor;i++)vetor_counting[i]=vetor_original[i];
    for(i = 0;i < tamanho_vetor;i++)vetor_random_quick[i]=vetor_original[i];

    Bubble_Sort(vetor_bubble, tamanho_vetor);               //Chamadas das funções de ordenação
    Selection_Sort(vetor_selection, tamanho_vetor);
    Insertion_Sort(vetor_insertion, tamanho_vetor);
    Count_Merge_Sort(vetor_merge, 0, tamanho_vetor - 1);
    Count_Quick_Sort(vetor_quick, 0, tamanho_vetor - 1);
    Count_Random_Quick_Sort(vetor_random_quick, 0, tamanho_vetor - 1);
    Counting_Sort(vetor_counting, tamanho_vetor, tamanho_vetor - 1);
    printf("\n\nBonus:\n");
    Shell_Sort(vetor_shell, tamanho_vetor);
    
    return 0;
}

void Gera_Vetor_Aleatorio(long int *A, long int min, long int max, long int N){  //Função para gerar o vetor de números aleatórios
    long int intervalo, i ;
    srand(time(NULL)); // Para gerar números distintos a cada repetição
    intervalo = max - min + 1; // Calcula tamanho do intervalo
    for (i=0;i<=N-1;i++)A[i] = min + (rand() % intervalo); // Gera vetor de N inteiros aleatoriamente no intervalo
}

void Bubble_Sort(long int *A, long int N){  //Função para calculo do tempo e execução do Bubble Sort
    clock_t t_inicial, t_final;
    double tempo;
    int cont, i, aux;

    t_inicial = clock(); // dispara contador de ciclos do relógio

    for(cont=0;cont<N;cont++){    //Execução do Bubble Sort
        for(i=0;i<N-1;i++){
            if(A[i]>A[i+1]){
                aux = A[i];
                A[i] = A[i+1];
                A[i+1] = aux;
            }
        }
    }

    t_final = clock(); // finaliza contador de ciclos do relógio

    tempo = (double)(t_final-t_inicial)/CLOCKS_PER_SEC*1000;
    printf("Tempo em Bubble Sort: %lf milisegundos", tempo); // retorna tempo em milisegundos
}

void Insertion_Sort(long int *A, long int N){  //Função para calculo do tempo e execução do Insertion Sort
    clock_t t_inicial, t_final;
    double tempo;
    int cont, i, aux;

    t_inicial = clock(); // dispara contador de ciclos do relógio

    for(cont=1;cont<N;cont++){            //Execução do Insertion Sort
        aux = A[cont];
        i = cont - 1;
        while (i >= 0 && A[i] > aux){
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = aux;
    }

    t_final = clock(); // finaliza contador de ciclos do relógio

    tempo = (double)(t_final-t_inicial)/CLOCKS_PER_SEC*1000;
    printf("\nTempo em Insertion Sort: %lf milisegundos", tempo); // retorna tempo em milisegundos
}

void Selection_Sort(long int *A, long int N){ //Função para calculo do tempo e execução do Selection Sort
    clock_t t_inicial, t_final;
    double tempo;
    int cont, i, aux, min, temp;

    t_inicial = clock(); // dispara contador de ciclos do relógio

    for (i=0;i<N-1;i++){                //Execução do Selection Sort
        min = i;
        for (cont=i+1;cont<N;cont++){
            if(A[cont]<A[min]){ 
                min = cont;
            }
        }
        temp = A[min];
        A[min] = A[i];
        A[i] = temp;
    }

    t_final = clock(); // finaliza contador de ciclos do relógio

    tempo = (double)(t_final-t_inicial)/CLOCKS_PER_SEC*1000;
    printf("\nTempo em Selection Sort: %lf milisegundos", tempo); // retorna tempo em milisegundos
}

void Merge(long int *A, long int min, long int meio, long int max){  //Função que realiza o merge
    int i, j, k, lista[max + 1]; //Criação de lista com o mesmo tamanho do vetor original

    i = min;   //Criação de contadores para o merge
    j = meio;
    k = 0;

    while (i < meio && j <= max) {  
        if (A[i] <= A[j])           //Enquanto a primeira metade for menor incrementa i e coloca o item na lista
        lista[k++] = A[i++];
        else                        //Se não incrementa j e coloca o item da segunda metade na lista
        lista[k++] = A[j++];
    }
    
    while (i < meio)lista[k++] = A[i++]; //Copiando os que restaram

    while (j <= max)lista[k++] = A[j++]; //Copiando os que restaram

    for (i = min; i <= max; i++)A[i] = lista[i - min]; //Passando tudo para o vetor indicado na função
}

void Merge_Sort(long int *A, long int min, long int max){ //Função de execução do Merge Sort 
    if(min < max){
        int meio = (min + max)/ 2; //Achando o meio
 
        Merge_Sort(A, min, meio);     //As duas funções Merge_Sort a partir de cada metade do vetor
        Merge_Sort(A, meio + 1, max);
 
        Merge(A, min, meio + 1, max);    //Chamada da função para juntar os vetores em um só novamente
    }
}

void Count_Merge_Sort(long int *A, long int min, long int max){ //Função feita para contar o Merge_Sort sem o contador cair na recursividade
    clock_t t_inicial, t_final;
    double tempo;

    t_inicial = clock(); // dispara contador de ciclos do relógio

    Merge_Sort(A, min, max);

    t_final = clock(); // finaliza contador de ciclos do relógio

    tempo = (double)(t_final-t_inicial)/CLOCKS_PER_SEC*1000;
    printf("\nTempo em Merge Sort: %lf milisegundos", tempo); // retorna tempo em milisegundos
}

void Quick_Sort(long int *A, long int min, long int max){ //Função de execução do Quick Sort
    int i, j, x, aux;
     
    i = min;                   //Salvando min e max em outras variáveis para incrementações e decrementações sem alterar o valor original
    j = max;
    x = A[(min + max) / 2];    //Posição do meio do vetor
     
    while(i <= j){
        while(A[i] < x && i < max){  //Enquanto a posição for menor que a metade do vetor e o valor do item da posição for menor que o maximo incrementa o i
            i++;
        }
        while(A[j] > x && j > min){  //Caso contrário decrementa o j
            j--;
        }
        if(i <= j){    //Se i for menor ou igual a j mudar A[i] com A[j], incrementando o i e decrementando o j até um alcançar o outro
            aux = A[i];
            A[i] = A[j];
            A[j] = aux;
            i++;
            j--;
        }
    }
     
    if(j > min){    //Se j for menor que o minimo fazer o Quick_Sort dos dois
        Quick_Sort(A, min, j);
    }
    if(i < max){    //Se i for menor que o maximo fazer o Quick_Sort dos dois também
        Quick_Sort(A, i, max);
    }
}

void Count_Quick_Sort(long int *A, long int min, long int max){ //Função feita para contar o Quick_Sort sem o contador cair na recursividade
    clock_t t_inicial, t_final;
    double tempo;

    t_inicial = clock(); // dispara contador de ciclos do relógio

    Quick_Sort(A, min, max);

    t_final = clock(); // finaliza contador de ciclos do relógio

    tempo = (double)(t_final-t_inicial)/CLOCKS_PER_SEC*1000;
    printf("\nTempo em Quick Sort: %lf milisegundos", tempo); // retorna tempo em milisegundos
}

void Shell_Sort(long int *A, long int N){  //Função para calculo do tempo e execução do Shell Sort
    clock_t t_inicial, t_final;
    double tempo;
    int i , j , x, aux = 1;

    t_inicial = clock(); // dispara contador de ciclos do relógio
    
    while(aux < N) {  //Execução do Shell Sort
        aux = 3*aux+1;
    }
    while(aux > 1){
        aux /= 3;
        for(i = aux; i < N; i++){
            x = A[i];
            j = i - aux;
            
            while (j >= 0 && x < A[j]){
                A[j + aux] = A[j];
                j -= aux;
            }
            A[j + aux] = x;
        }
    }

    t_final = clock(); // finaliza contador de ciclos do relógio

    tempo = (double)(t_final-t_inicial)/CLOCKS_PER_SEC*1000;
    printf("\nTempo em Shell Sort: %lf milisegundos", tempo); // retorna tempo em milisegundos
}

void Counting_Sort(long int *A, long int N, long int max){  //Função para calculo do tempo e execução do Counting Sort
    clock_t t_inicial, t_final;
    double tempo;
    int i, j, k;  //Contadores
    int baldes[max];

    t_inicial = clock(); // dispara contador de ciclos do relógio

    for(i = 0; i < max; i++)baldes[i] = 0;  //Execução do Counting Sort

    for(i = 0; i < N; i++)baldes[A[i]]++;

    for(i = 0, j = 0; j < max; j++){
        for(k = baldes[j]; k > 0; k--)A[i++] = j;
    }

    t_final = clock(); // finaliza contador de ciclos do relógio

    tempo = (double)(t_final-t_inicial)/CLOCKS_PER_SEC*1000;
    printf("\nTempo em Counting Sort: %lf milisegundos", tempo); // retorna tempo em milisegundos
}

int particao_pivot(long int *A, long int min, long int max){  //Função que fara a separação por pivor aleatório
    int pivotIndex = min + rand()%(max - min + 1); //gera um número aleatório como pivot
    int pivot, j, aux;  //varíaveis para salvar o pivot, contador e auxiliar na troca de valores
    int i = min - 1;

    pivot = A[pivotIndex];  //pegando o pivot da posição gerada aleatóriamente

    aux = A[pivotIndex];    //Trocando A[pivotIndex] por A[max]
    A[pivotIndex] = A[max];
    A[max] = aux;

    for(j = min; j < max; j++){
        if(A[j] < pivot){
            i++;
            aux = A[i];
            A[i] = A[j];
            A[j] = aux;
        }
    }

    aux = A[i+1];   //Trocando A[i + 1] por A[max]
    A[i+1] = A[max];
    A[max] = aux;

    return i + 1; //Retornar para ser usado na função abaixo
}
 
void Random_Quick_Sort(long int *A, long int min, long int max){ //Função de execução do Random_Quick_Sort
    int j;
    if (min < max){
        j = particao_pivot(A, min, max);  //Fazendo a partição por pivot aleatório
        Random_Quick_Sort(A, min, j-1);
        Random_Quick_Sort(A, j+1, max);
    }
}

void Count_Random_Quick_Sort(long int *A, long int min, long int max){ //Função feita para contar o Random_Quick_Sort_Sort sem o contador cair na recursividade
    clock_t t_inicial, t_final;
    double tempo;

    t_inicial = clock(); // dispara contador de ciclos do relógio

    Random_Quick_Sort(A, min, max);

    t_final = clock(); // finaliza contador de ciclos do relógio

    tempo = (double)(t_final-t_inicial)/CLOCKS_PER_SEC*1000;
    printf("\nTempo em Random Quick Sort: %lf milisegundos", tempo); // retorna tempo em milisegundos
}