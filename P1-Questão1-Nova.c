#include <stdio.h>
#include <math.h>

//OBS: Parte fracionaria funcionando só de decimal para outras bases.

//Questão 1

int decimal = 0, base_nova = 0; //variaveis que vão ser usadas em mais de uma função, então coloquei como globais.
float fracao;

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
    int i = 0, vetor_dec[50], vetor_frac[50], cont = 0;
    float aux;
    while(num >= 1){
        vetor_dec[i] = num % base; //Criando um vetor com o resto das divisões pela base desejada.
        i++;
        num = num/base;
        cont++;                //Salvando o tamanho do vetor para ser usado no print.
    }
    
    printf("Na base %d: ", base);
    for(i = cont - 1; i >= 0; i--)printf("%d", vetor_dec[i]); //Printando da direita para a esquerda para resultar no número correto.

    cont = 0;  //Zerando o contador para poder usar de novo
    if(fracao > 0.0){  //Se o número tiver parte fracionária fará o seguinte calculo
        do{
            aux = fracao * base;  //Multiplicando a fração pela base
            fracao = aux;         
            vetor_frac[cont] = (int)aux;  //Salvando em uma lista o inteiro dessa multiplicação
            aux = aux - (int)aux;         //Diminuindo o número pelo inteiro dele para pegar a nova fração e repetir o processo
            fracao = fracao - (int)fracao;
            cont++; //Incrementando o contador
        }while(fracao != 0);  //Se váriavel fracao chegar a zero toda a parte fracionária já foi feita

        printf(".");  //print do ponto separando decimal de fracionario
        for(i = 0; i <= cont - 1; i++)printf("%d", vetor_frac[i]);  //Print da parte fracionaria
    }
}

int main(){
    int base_antiga; //base_nova ficou como global lá em cima porque precisava aparecer na função X_to_Dec.
    float num;
    printf("Digite a base do numero: ");                                       //Input da base antiga.
    scanf("%d", &base_antiga);
    printf("Digite o numero(Separando com '.' se tiver parte fracionaria): "); //Input do número.
    scanf("%f", &num);
    printf("Digite a base que deseja: ");                                      //Input da base nova.
    scanf("%d", &base_nova);

    fracao = num - (int)num; //Tirando a parte fracionaria
    num = (int)num;          //E separando a parte decimal

    if(base_antiga == 10)Dec_to_X(num, base_nova);      //Se for de decimal para outra base chamar essa função.
    else if(base_nova == 10)X_to_Dec(num, base_antiga); //Se for de outra base para decimal chamar essa função.
    else {                                       
        X_to_Dec(num, base_antiga);                     //Se não, primeiro será passado a base 10.
        Dec_to_X(decimal, base_nova);                   //E depois para a base desejada.
    }

    return 0;
}
