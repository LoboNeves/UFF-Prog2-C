/*
// Exercício "O que será impresso ?"

#include <stdio.h>

int main(){
    int a=3, b=2, *p=NULL, *q=NULL;

    p=&a;               //p recebe endereço de a
    q=p;                //q também
    *q = *q + 1;        //O conteúdo do endereço de a é somado a 1, então a=4
    q=&b;               //q passa a apontar para o endereço de b
    b=b+1;              //b é somado a 1, então b=3
    printf("%d\n",*q);  //conteúdo de q=b=3
    printf("%d\n",*p);  //conteúdo de p=a=4
}

//Merge com funções
#include <stdio.h>
//Variaveis globais que serão usadas em mais de uma função
int n1, n2, i, cont, aux;

void ordenacao(int *x, int length){
    //bubble sort
    for(cont=0;cont<length;cont++){
        for(i=0;i<length-1;i++){
            if(x[i]>x[i+1]){
                aux = x[i];
                x[i] = x[i+1];
                x[i+1] = aux;
            }
        }
    }
}

void merge(int *x, int *y){
    //Criação da lista B com merge dos items da lista A1 e A2
    int n3 = n1 + n2;
    int B[n3];
    for(i=0;i<n1;i++)B[i]=x[i];
    for(i=n1;i<n3;i++)B[i]=y[i-n1];

    //Bubble sort inverso
    for(cont=1;cont<n3;cont++){
        for(i=0;i<n3-1;i++){
            if(B[i]<B[i+1]){
                aux = B[i];
                B[i] = B[i+1];
                B[i+1] = aux;
            }
        }
    }

    printf("Lista B:");
    for(i=0;i<n3;i++)printf("%d ", B[i]);
}

int main(){
    //Criação das listas com tamanho e items por input
    printf("Digite o valor de n1:");
    scanf("%d", &n1);
    int A1[n1];
    for(i=0;i<n1;i++){
        printf("Digite o valor do item da lista:");
        scanf("%d", &A1[i]);
    }
    printf("Digite o valor de n2:");
    scanf("%d", &n2);
    int A2[n2];
    for(i=0;i<n2;i++){
        printf("Digite o valor do item da lista:");
        scanf("%d", &A2[i]);
    }
    //Funções de bubble sort em cada lista, podendo fazer com qualquer tamanho
    ordenacao(A1, n1);
    ordenacao(A2, n2);
    //Merge das listas printando de forma decrescente
    merge(A1, A2);

    return 0;
}
*/

//Algoritmos para ordenação

#include <stdio.h>
int n, i, cont, aux;

void bubblesort(int *x){
    for(cont=0;cont<n;cont++){
        for(i=0;i<n-1;i++){
            if(x[i]>x[i+1]){
                aux = x[i];
                x[i] = x[i+1];
                x[i+1] = aux;
            }
        }
    }
}

void insertion(int *x){
    for(cont=1;cont<n;cont++){
        aux = x[cont];
        i = cont - 1;
        while (i >= 0 && x[i] > aux){
            x[i + 1] = x[i];
            i = i - 1;
        }
        x[i + 1] = aux;
    }
}

void selection(int *x){
    int min, temp;
    for (i=0;i<n-1;i++){
        min = i;
        for (cont=i+1;cont<n;cont++){
            if(x[cont]<x[min]){ 
                min = cont;
            }
        }
        temp = x[min];
        x[min] = x[i];
        x[i] = temp;  
    }
}

int main(){
    int OP;
    //Criando a lista com tamanho e itens por input
    printf("Digite o valor de n:");
    scanf("%d", &n);
    int lista[n];
    for(i=0;i<n;i++){
        printf("Digite o valor do item da lista:");
        scanf("%d",&lista[i]);
    }
    //Escolhendo a operação
    printf("Digite a operacao: Bubble Sort(1) Insertion(2) Selection(3)\n");
    scanf("%d", &OP);
    switch(OP){
        case 1: 
            bubblesort(lista);
            for(i=0;i<n;i++)printf("%d ", lista[i]);
            break;
        case 2: 
            insertion(lista);
            for(i=0;i<n;i++)printf("%d ", lista[i]);
            break;
        case 3:
            selection(lista);
            for(i=0;i<n;i++)printf("%d ", lista[i]);
            break;
        default: printf("Operacao incorreta!");    
    }
    return 0;
}