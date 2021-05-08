/*
//for percorrendo vetores
#include <stdio.h>

int main(){
    float media[10], soma=0, media_geral;
    int i,maior = 0;

    for(i=0;i<10; i++){
        printf("Digite o valor da media do aluno:");
        scanf("%f", &media[i]);
        soma += media[i];
    }
    media_geral = soma/10;

    for(i=0;i<10;i++){
        if(media[i]>media_geral)maior +=1;
    }

    printf("A media geral da turma foi %.1f\n", media_geral);
    printf("%d alunos tiveram nota maior que a media", maior);
    return 0;
}

// exemplo usando vetores
#include <stdio.h>
#include <string.h>

int main(){
    char produto[3][20];
    int estoque[3], cod, quant;
    float preco[3];

    strcpy(produto[0], "caneta");
    strcpy(produto[1], "lapis");
    strcpy(produto[2], "borracha");
    estoque[0] = 1000;
    preco[0] = 2.50;
    estoque[1] = 2000;
    preco[1] = 2.99;
    estoque[2] = 550;
    preco[2] = 4.10;
    printf("Digite o codigo do produto:");
    scanf("%d", &cod);
    printf("\nDigite a quantidade:");
    scanf("%d", &quant);
    estoque[cod] += quant;
    printf("O produto %s contem %d unidades",produto[cod], estoque[cod]);
    return 0; 
}

//Pares e impares

#include <stdio.h>

int main(){
    int i, res, numeros[10], pares=0, impares=0;

    for(i=0;i<10;i++){
        printf("Digite um numero:");
        scanf("%d", &numeros[i]);
        if(numeros[i]>=0){
            res = numeros[i]%2;
            if(res==0)pares++;
            else impares ++;
        }
        else {
            printf("O numero tem que ser positivo\n");
            i--;
        }
    }
    printf("%d numeros pares e %d numeros impares",pares,impares);
    return 0;
}

//Exercicio: Busca sequencial

#include <stdio.h>

int main(){
    int i, cont = 0, x, A[10] = {1,2,3,4,5,5,5,8,9,10};

    printf("Digite o valor de x:");
    scanf("%d", &x);
    for(i=0;i<10;i++){
        if(A[i]==x)cont +=1;
    }
    if(cont != 0)printf("x esta na lista A e aparece %d vez(es)", cont);
    else printf("x nao esta na lista A");
    return 0;
}

//Bubble sort

#include <stdio.h>

int main(){
    int n, i, j, aux, cont;
    //Definir tamanho da lista por input do usuário
    printf("Digite o valor de n:");
    scanf("%d", &n);
    int lista[n];
    for(i=0;i<n;i++){
        printf("Digite o valor do item da lista:");
        scanf("%d", &lista[i]);
    }
    //print da lista antes da ordenação
    printf("lista antiga:");
    for(i=0;i<n;i++){
        printf("%d ", lista[i]);
    }
    //bubble sort
    for(cont=1;cont<n;cont++){
        for(i=0;i<n-1;i++){
            if(lista[i]>lista[i+1]){
                aux = lista[i];
                lista[i] = lista[i+1];
                lista[i+1] = aux;
            }
        }
    }
    //print da lista depois da ordenação
    printf("\nlista nova:");
    for(i=0;i<n;i++){
        printf("%d ", lista[i]);
    }

    return 0;
}

//Merge de vetores

#include <stdio.h>

int main(){
    int n1, n2, i, cont, aux;
    //Definir tamanho da lista  A por input do usuário
    printf("Digite o valor de n1:");
    scanf("%d", &n1);
    int A[n1];
    for(i=0;i<n1;i++){
        printf("Digite o valor do item da lista A:");
        scanf("%d", &A[i]);
    }
    //bubble sort da lista A
    for(cont=1;cont<n1;cont++){
        for(i=0;i<n1-1;i++){
            if(A[i]>A[i+1]){
                aux = A[i];
                A[i] = A[i+1];
                A[i+1] = aux;
            }
        }
    }
    //Definir tamanho da lista  B por input do usuário
    printf("Digite o valor de n2:");
    scanf("%d", &n2);
    int B[n2];
    for(i=0;i<n2;i++){
        printf("Digite o valor do item da lista B:");
        scanf("%d", &B[i]);
    }
    //bubble sort da lista B
    for(cont=1;cont<n2;cont++){
        for(i=0;i<n2-1;i++){
            if(B[i]>B[i+1]){
                aux = B[i];
                B[i] = B[i+1];
                B[i+1] = aux;
            }
        }
    }
    //Merge das listas A e B na lista C
    int n3 = n1 + n2;
    int C[n3];
    for(i=0;i<n1;i++)C[i]=A[i];
    for(i=n2;i<n3;i++)C[i]=B[i-n2];
    //bubble sort da lista C
    for(cont=1;cont<n3;cont++){
        for(i=0;i<n3-1;i++){
            if(C[i]>C[i+1]){
                aux = C[i];
                C[i] = C[i+1];
                C[i+1] = aux;
            }
        }
    }
    //Print da lista C
    printf("\nlista C:");
    for(i=0;i<n3;i++){
        printf("%d ", C[i]);
    }
    
    return 0;
}

*/

//Matriz transposta
#include <stdio.h>

int main(){
    int m,n,i,j;

    printf("Digite a ordem da matriz:");
    scanf("%d%d", &m,&n);
    //Criação e preenchimento da matriz A por input
    int A[m][n];
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("Digite o elemento da matriz:");
            scanf("%d", &A[i][j]);
        }
    }
    //Criação da matriz transposta
    int B[n][m];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)B[i][j]=A[j][i];
    }
    //Print da matriz normal
    printf("Matriz normal:");
    for(i=0;i<m;i++){
        printf("\n");
        for(j=0;j<n;j++){
            printf("%d",A[i][j]);
        }
    }
    //Print da matriz Transposta
    printf("\nMatriz Transposta:");
    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<m;j++){
            printf("%d",B[i][j]);
        }
    }
    return 0;
}