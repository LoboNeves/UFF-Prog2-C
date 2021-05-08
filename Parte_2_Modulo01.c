#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome[40];
    int idade;

    printf("Profissao = ");
    scanf("%s", nome);
    printf("Idade = ");
    scanf("%d", &idade);
    printf("Minha profissao eh: %s \n",nome);
    printf("Minha idade eh: %d \n", idade);

    return 0;
}
