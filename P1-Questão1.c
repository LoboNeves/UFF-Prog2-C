#include <stdio.h>
#include <math.h>

//OBS: Só não consegui fazer para a parte fracionária, tanto na primeira quanto na segunda questão.

//Questão 1

int decimal = 0, base_nova = 0; //variaveis que vão ser usadas em mais de uma função, então coloquei como globais.

void X_to_Dec(int num, int base){ //Função para converter num para decimal.
    int exp = 0, resto;
    while (num != 0){
        resto = num % 10;                  //Pega o resto da divisão.
        num /= 10;                         //Divide o número por 10.
        decimal += resto * pow(base, exp); //Incrementa com o resto da divisão multiplicado por 2 elevado ao expoente.
        ++exp;                             //Incrementa o expoente.
    }
    if(base_nova == 10)printf("Na base 10: %d", decimal); //Print na base 10, somente se essa for a base desejada, se só estiver sendo usada como intermediaria não haverá print.
}

void Dec_to_X(int num, int base){ //Conversão de decimal para qualquer base.
    int i = 0, aux, resultado = 0, vetor[50], cont = 0;
    while(num >= 1){
        vetor[i] = num % base; //Criando um vetor com o resto das divisões pela base desejada.
        i++;
        num = num/base;
        cont++;                //Salvando o tamanho do vetor para ser usado no print.
    }
    printf("Na base %d: ", base);
    for(i = cont - 1; i>=0; i--)printf("%d", vetor[i]); //Printando da direita para a esquerda para resultar no número correto.
}

int main(){
    int base_antiga, num; //base_nova ficou como global lá em cima porque precisava aparecer na função X_to_Dec.
    printf("Digite a base do numero: ");        //Input da base antiga.
    scanf("%d", &base_antiga);
    printf("Digite o numero: ");                //Input do número.
    scanf("%d", &num);
    printf("Digite a base que deseja: ");       //Input da base nova.
    scanf("%d", &base_nova);

    if(base_antiga == 10)Dec_to_X(num, base_nova);      //Se for de decimal para outra base chamar essa função.
    else if(base_nova == 10)X_to_Dec(num, base_antiga); //Se for de outra base para decimal chamar essa função.
    else {                                       
        X_to_Dec(num, base_antiga);                     //Se não, primeiro será passado a base 10.
        Dec_to_X(decimal, base_nova);                   //E depois para a base desejada.
    }

    return 0;
}
