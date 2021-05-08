#include <stdio.h>
#include <math.h>

//OBS: Parte fracionária funcionando só se o número começar por zero(ex:0.03125).

//Questão 2

int main(){
    int vetor_bin[50],vetor_exp[11], exp, i=0, cont=0, cont_exp=0, cont_zeros, exp_aux, exp_resultado=0, tamanho_binario, sinal;
    float num, fracao, aux, resultado_decimal = 0;
    printf("Digite o numero(Separando com '.' se tiver parte fracionaria): ");
    scanf("%f", &num);
    float num_orig = num; //Deixar salvo o número original para usar no final.
    if(num < 0)num = -num; // Mudando o sinal para positivo para fazer as operações de exp e mantissa normalmente.
    //Transformando em binário e colocando em um vetor.
    while(num >= 1){
        vetor_bin[i] = (int)num % 2;  //Pegar o resto da divisão e colocar em cada item da lista
        i++;
        num = num/2;
        cont++; //Contador para saber o tamanho do vetor.
    }
    i=0; //zerar o i para funcionar como contador de novo.

    //Achando o expoente:
    if(vetor_bin[cont-1] == 1){ //Se o vetor começar por 1, no caso se o número for inteiro.
        exp = cont - 1 + 1023; //Somando com o deslocamento do expoente.
        while(exp >= 1){
            vetor_exp[i] = exp % 2; //Pegar o resto da divisão e colocar em cada item da lista
            i++;
            exp = exp/2;
            cont_exp++; //Para saber o tamanho do vetor.
        }
        if(cont_exp == 10){    //Caso n seja 1.
            cont_exp++;        //Incrementar o contador.
            vetor_exp[10] = 0; //E adicionar um 0 no começo do vetor.
        }
    }
    else{
        fracao = num; //Salvando o mesmo valor de num em uma nova variável para fazer os seguintes calculos sem modificar num
        do{  //Cálculo para transformar em binário a parte fracionaria e salvar o resultado em um vetor
            aux = fracao * 2;
            fracao = aux;
            vetor_exp[i] = (int)aux;
            aux = aux - (int)aux;
            fracao = fracao - (int)fracao;
            i++;
        }while(fracao != 0);  //Se váriavel fracao chegar a zero toda a parte fracionária já foi feita
        for(cont = 1;cont<i;cont++)vetor_bin[cont] = vetor_exp[cont];  //Salvando o resultado em binário em um novo vetor para ser usado no print da mantissa

        i=0; //zerar o i para funcionar como contador de novo.
        while(vetor_exp[i] != 1)i++;

        exp = 1023 - i - 1; //Número do expoente
        i=0; //zerar o i para funcionar como contador novamente.
        while(exp >= 1){
            vetor_exp[i] = exp % 2; //Pegar o resto da divisão e colocar em cada item da lista
            i++;
            exp = exp/2;
            cont_exp++; //Para saber o tamanho do vetor.
        }
    }
    //Print do resultado:
    printf("\nResultado em ponto flutuante: ");
    //If e else para salvar o sinal da operação, será usado no final quando voltar para o número original.
    if(num_orig > 0){
        sinal = 0;
        printf("%d | ", sinal);//Caso o número seja positivo, o sinal será 0.
    }
    else{ 
        sinal = 1;
        printf("%d | ", sinal);//Caso o número seja negativo, o sinal será 1.
    }
    if(num_orig >= 1 || num_orig <= -1)for(i = cont_exp - 1; i>=0; i--)printf("%d", vetor_exp[i]);//Printando ao contrário para resultar no número em binário, se o número for maior que 1 ou menor que -1.
    else for(i = cont_exp; i>=0; i--)printf("%d", vetor_exp[i]); // Se começar por 0 percorrerá dessa maneira
    printf(" | ");
    if(num>0.1){ //Print se o número for maior que 0.1
        if(num_orig >= 1 || num_orig <= -1)for(i = cont - 2; i>=0; i--)printf("%d", vetor_bin[i]);//Printando ao contrário para resultar no número em binário.
        else for(i = cont - 1; i>0; i--)printf("%d", vetor_bin[i]);
    }
    else{
        if(num_orig >= 1 || num_orig <= -1)for(i = cont - 2; i>=0; i--)printf("%d", vetor_bin[i]);//Printando ao contrário para resultar no número em binário.
        else for(i = cont - 2; i>0; i--)printf("%d", vetor_bin[i]);
    }
    //Preencher o restante da mantissa com zeros.
    cont_zeros = 52-cont;
    while(cont_zeros>=0){
        printf("%d", 0);
        cont_zeros--;
    }

    //Começando o caminho de volta para transformar em decimal:

    for(i = cont_exp - 1; i>=0; i--){ // pegando os 11 digitos do expoente .
        if(vetor_exp[i] == 1){        // conferindo quais são iguais a 1.
            exp_aux = pow(2,i);       //elevando 2 a posição do numero na lista se ele for igual a 1.
            exp_resultado += exp_aux; //somando todos os que são iguais a 1 em uma váriavel.
        }
    }
    if(num_orig >= 1 || num_orig <= -1){
        tamanho_binario = exp_resultado - 1023; //quantos digitos terão na representação em binário, subtraindo pelo deslocamento do expoente em 64 bits.
        int vetor_bin_novo[tamanho_binario + 1];//Iniciando um novo vetor com o tamanho_binario alocando espaço para o 1 que viria antes da virgula.
        vetor_bin_novo[0] = 1;                  //Colocando o primeiro 1 que viria antes ta virgula.
        for(i = 1;i <= tamanho_binario;i++){
            vetor_bin_novo[i]=vetor_bin[cont - i - 1]; //Pegando a mantissa para colocar no vetor após o 1.
        }

        for(i = 0; i <= tamanho_binario; i++){          //Percorrendo o número em binário.
            if(vetor_bin_novo[i] == 1){                 //Quando existir algum item igual a 1.
                exp_aux = pow(2,tamanho_binario - i);   //Será 2 elevado ao número da posição do item da lista se contar da direita para a esquerda.
                resultado_decimal += exp_aux;           //Somando os números que foram elevados e salvando na váriavel resultado.
            }
        }
        if(sinal == 1)resultado_decimal = -resultado_decimal;   //Se o primeiro sinal dos 64 bits for 1 significa que o número é negativo.
        printf("\nResultado de volta em decimal: %.0f", resultado_decimal);   //Print do resultado final em decimal.
    }
    else{ 
        resultado_decimal = num_orig;
        if(sinal == 1)resultado_decimal = -resultado_decimal;   //Se o primeiro sinal dos 64 bits for 1 significa que o número é negativo.
        printf("\nResultado de volta em decimal: %f", resultado_decimal);   //Print do resultado final em fracionario.
    }
    return 0;
}