#include <stdio.h>

/*
// if simples
int main(){
    int N1, N2, N3, MAIOR;
    printf("Digite tres numeros:");
    scanf("%d%d%d",&N1,&N2,&N3);
    MAIOR = N1;
    if(N2 > MAIOR)MAIOR = N2;
    if(N3 > MAIOR)MAIOR = N3;
    printf("Maior dos tres: %d", MAIOR);
    return 0;
}

// if composto
int main(){
    int A, B, R, OP;
    printf("Digite dois inteiros:");
    scanf("%d%d",&A,&B);
    printf("Digite 1 para SOMAR ou 2 para SUBTRAIR:");
    scanf("%d",&OP);
    if (OP == 1){
        R = A + B;
        printf("SOMA: %d", R);
    }
    if (OP == 2){
        R = A - B;
        printf("SUBTRACAO: %d", R);
    }
    return 0;   
}

//outro exemplo
int main(void){
    float M;
    char CONC;
    printf("Emissao do conceito final dada a media\n");
    printf("Informe a media alcancada pelo aluno:");
    scanf("%f", &M);
    if (M < 6.0)
        CONC = 'D';
    else if(M < 7.5)
        CONC = 'C';
    else if(M < 9.0)
        CONC = 'B';
    else CONC = 'A';
    printf("Conceito: %c",CONC);
    return 0;
}

// switch
int main(){
    int OP;
    float R, raio;
    scanf("%f",&raio);
    scanf("%d",&OP);
    switch(OP){
        //Calcula perímetro
        case 1: R = 2 * 3.1416 * raio;
            printf("O perimetro eh %f", R);
            break;
        // Calcula área
        case 2: R = 3.1416 * raio * raio;
            printf("A area eh %f", R);
            break;
        default: printf("Operacao incorreta");
    }
    return 0;
}
*/

//exercicios

#include <math.h>
int main(){
    int OP;
    float l, R;
    printf("Digite o valor de l:");
    scanf("%f",&l);
    printf("Digite o valor de OP:");
    scanf("%d",&OP);
    switch(OP){
        case 1: R = pow(l,3);
            printf("Volume do cubo: %f", R);
            break;
        case 2: R = (6 * pow(l,2) * sqrt(3))/4;
            printf("Volume do prisma: %f", R);
            break;
        case 3: R = pow(l,3)/3;
            printf("Volume da piramide: %f", R);
            break;
        default: printf("Operacao incorreta!");
    }
    return 0;
}