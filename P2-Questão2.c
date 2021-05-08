#include <stdio.h>
#include <math.h>

void Retira(int *argolas, int n, int tamanho_lista);  //Prototipo das funções recursivas colocadas antes do main para uma encontrar a outra na hora de ser chamada em recursividade
void Insere(int *argolas, int n, int tamanho_lista);
void Num_Movimentos(int x);  //Prototipo da função para cálculo do número de movimentos

int main(){
    int n, OP, i;
    printf("Digite o numero de argolas: "); 
    scanf("%d", &n);    //Input do número de argolas
    int argolas[n];     //Criando lista com o tamanho do número de argolas
    
    //Escolhendo a operação
    printf("Digite a operacao: Insercao(1) ou Retirada(2)\n");
    scanf("%d", &OP);
    if(OP == 1){                            //Se a operação for igual a 1
        for(i = 0;i < n; i++){              //Cada item da lista passará a ser 0
            argolas[i] = 0;
            printf("%d", argolas[i]);       //Printar listas antes de começar a operação, só com números '0'
        }
        printf("\n");
        Insere(argolas, n, n);              //Chamada da função de inserção
        Num_Movimentos(n);                  //Chamada da função que retorna o número de movimentos
    }
    else if(OP == 2){                       //Se a operação for igual a 2
        for(i = 0;i < n; i++){              //Cada item da lista passará a ser 1
            argolas[i] = 1;
            printf("%d", argolas[i]);       //Printar listas antes de começar a operação, só com números '1'
        }
        printf("\n");
        Retira(argolas, n, n);              //Chamada da função de retirada
        Num_Movimentos(n);                  //Chamada da função que retorna o número de movimentos
    }
    else printf("Operacao invalida");       //Se a operação não for 1 nem 2, printará operação inválida

    return 0;
}

void Num_Movimentos(int x){                                         //Função para cálculo e print do número de movimentos necessários
    x = (pow(2, x + 1) - 2 + ((pow(-1, x + 1) + 1)/2))/3;
    printf("\nTotal de movimentos: %d", x);
}

void Retira(int *argolas, int n, int tamanho_lista){                //Função para retirada das argolas, a váriavel tamanho_lista serve para não perder o tamanho original da lista logo que n vai ser decrementando sucessivas vezes
    int i; //contador

    if(n == 1){                                                     //Se tamanho igual a 1
        argolas[tamanho_lista - 1] = 0;                             //Primeiro item igual a 0
        for(i = 0;i < tamanho_lista; i++)printf("%d", argolas[i]);  //Print da lista
        printf("\n");
    }

    else if(n == 2){                                                //Se tamanho igual a 2
        argolas[tamanho_lista - 2] = 0;                             //Segundo item igual a 0
        for(i = 0;i < tamanho_lista; i++)printf("%d", argolas[i]);  //Print da lista
        printf("\n");
        argolas[tamanho_lista - 1] = 0;                             //Depois primeiro item igual a 0 também
        for(i = 0;i < tamanho_lista; i++)printf("%d", argolas[i]);  //Print da lista
        printf("\n");
    }

    else{                                                           //Se o tamanho não for igual a 1 nem 2
        Retira(argolas, n - 2, tamanho_lista);                      //Iniciar procedimento recursivo chamando a mesma função de retirada no tamanho de n-2
        argolas[tamanho_lista - n] = 0;                             //Enesimo termo igual a 0
        for(i = 0;i < tamanho_lista; i++)printf("%d", argolas[i]);  //Print da lista
        printf("\n");
        Insere(argolas, n - 2, tamanho_lista);                      //Chamar função de inserção no tamanho de n-2 
        Retira(argolas, n - 1, tamanho_lista);                      //Chamar função de retirada no tamanho de n-1
    }
}

void Insere(int *argolas, int n, int tamanho_lista){                //Função para inserção das argolas, a váriavel tamanho_lista serve para não perder o tamanho original da lista logo que n vai ser decrementando sucessivas vezes(de novo)
    int i; //contador

    if(n == 1){                                                     //Se tamanho igual a 1
        argolas[tamanho_lista - 1] = 1;                             //Primeiro item igual a 1
        for(i = 0;i < tamanho_lista; i++)printf("%d", argolas[i]);  //Print da lista
        printf("\n");
    }

    else if(n == 2){                                                //Se tamanho igual a 2
        argolas[tamanho_lista - 1] = 1;                             //Primeiro item igual a 1
        for(i = 0;i < tamanho_lista; i++)printf("%d", argolas[i]);  //Print da lista
        printf("\n");
        argolas[tamanho_lista - 2] = 1;                             //Depois segundo item igual a 1 também
        for(i = 0;i < tamanho_lista; i++)printf("%d", argolas[i]);  //Print da lista
        printf("\n");
    }

    else{                                                           //Se o tamanho não for igual a 1 nem 2
        Insere(argolas, n - 1, tamanho_lista);                      //Iniciar procedimento recursivo chamando a mesma função de inserção no tamanho de n-1
        Retira(argolas, n - 2, tamanho_lista);                      //Chamar função de retirada no tamanho de n-2
        argolas[tamanho_lista - n] = 1;                             //Enesimo termo igual a 1
        for(i = 0;i < tamanho_lista; i++)printf("%d", argolas[i]);  //Print da lista
        printf("\n");
        Insere(argolas, n - 2, tamanho_lista);                      //Chamar função de inserção no tamanho de n-2
    }
}
