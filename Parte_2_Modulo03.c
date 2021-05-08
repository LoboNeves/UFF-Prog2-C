#include <stdio.h>

/*
// for
int main(){
    int N, i, SOMA;
    SOMA = 0;

    printf("Digite um numero = ");
    scanf("%d", &N);
    for(i=1;i<=N;i++)
        SOMA += i;
    printf("A soma eh %d", SOMA);
    return 0;
}


//Ler n numeros e retornar quantos são negativos

#include <stdlib.h>

int main(){
    int numero, cont, neg = 0;
    
    for(cont=0;cont<10;cont++){
        printf("Digite um numero: ");
        scanf("%d", &numero);
        if (numero<0) neg++;
    }
    printf("\nTem %d numeros negativos", neg);
    return 0;
}

// while

int main(){
    int Y, X, QUAD;

    printf("Digite um numero:");
    scanf("%d",&Y);
    X = 1;
    QUAD = 1;
    while(QUAD<=Y){
        X++;
        QUAD = X * X;
    }
    printf("O numero eh: %d", X);
    return 0;
}



// do while

#include <math.h>

int main(){
    int num, soma = 0, cont = 0;
    float media;

    printf("\nDigite um inteiro positivo. Digite <0> para encerrar:");
    scanf("%d",&num);

    if (num!=0){
        do{
            if(num%2==0){
                soma += num;
                cont ++;
            }
            printf("\nDigite um inteiro positivo. Digite <0> para encerrar:");
            scanf("%d",&num);
        }while(num!=0);
        if(cont>0){
            media = (float)soma/cont;
            printf("\nA media eh %.2f",media);
        }
        else printf("\nNenhum valor par encontrado");
    }
    return 0;
}
*/

//Exercicio 1

#include <math.h>

int main(){
    float nota1, nota2, nota3, media_alunos = 0, media_geral = 0;
    int num_alunos = 1, decisao;

    printf("Digite as 3 notas do aluno:");
    scanf("%f%f%f",&nota1, &nota2, &nota3);
    media_alunos = (nota1 + nota2 + nota3)/3;
    media_geral = media_alunos/num_alunos;
    printf("Deseja entrar com as notas de outro aluno?Digite (1) ou (0):");
    scanf("%d",&decisao);

    if(decisao == 1){
        num_alunos += 1;
        printf("Digite as 3 notas do aluno:");
        scanf("%f%f%f",&nota1, &nota2, &nota3);
        media_alunos += (nota1 + nota2 + nota3)/3;
        media_geral = media_alunos/num_alunos;
        printf("\nDeseja entrar com as notas de outro aluno?Digite (s) ou (n):");
        scanf("%d", &decisao);
    }
    if(decisao == 0){
        printf("Numero de alunos: %d",num_alunos);
        printf("\nMedia dos alunos: %.1f",media_geral);
    }
    return 0;
}