#include <stdio.h>
#include <string.h>

int main(){
    int i = 0, multiplicao, maior = 0, posicao;
    char numeros[951] = "73167176531330624919225119674426574742355349194934969835203127745063262395783180169848018694788518438586156078911294949545950173795833195285320880551112540698747158523863050715693290963295227443043557668966489504452445231617318564030987111217223831136222989342338030813533627661428280644448664523874930358907296290491560440772390713810515859307960866701724271218839987979087922749219016997208880937766572733300105336788122023542180975125454059475224352584907711670556013604839586446706324415722155397536978179778461740649551492908625693219784686224828397224137565705605749026140797296865241453510047482166370484403199890008895243450658541227588666881164271714799244429282308634656748139191231628245861786645835912456652947654568284891288314260769004224219022671055626321111109370544217506941658960408071984038509624554443629812309878799272442849091888458015616609791913387549920052406368991256071760605886116467109405077541002256983155200055935729725";

    int lista_numeros[strlen(numeros)];  //Criar uma lista com o tamanho da string

    for(i = 0; i < strlen(numeros); i++){    //Colocar cada numero da string na lista e já transformando para inteiro, como visto abaixo
        lista_numeros[i] = numeros[i] - 48;  //Diminuindo por 48 para converter o mesmo número de string para inteiro
    }

    for(i = 0; i < strlen(numeros) - 4; i++){  //For para ir multiplicando de 5 em 5 e comparando se é maior que a váriavel "maior"
        multiplicao = lista_numeros[i] * lista_numeros[i + 1] * lista_numeros[i + 2] * lista_numeros[i+ 3] * lista_numeros[i + 4];
        if(multiplicao > maior){  //Se for maior a váriavel "maior" receberá esse valor e a posição será salva na variável "posicao"
            maior = multiplicao;
            posicao = i;
        }
    }

    printf("O maior produto eh: %d", maior);    //Print do produto
    printf("\nPosicao inicial: %d\n", posicao); //Print da posição

    return 0;
}
