//Quantidade de tinta para tanque cilindrico
#include <stdio.h>

int main(){
    int altura, raio, latas_int;
    float area, latas, custo;
    printf("Altura do cilindro:");
    scanf("%d", &altura);
    printf("Raio do cilindro:");
    scanf("%d", &raio);

    area = 2*3.14*raio*raio + 2*3.14*raio*altura;
    latas = area/15;
    custo = latas*20;
    latas_int = latas;
    printf("Qtd de latas: %d", latas_int);
    printf("\nCusto: R$%.2f", custo);
}