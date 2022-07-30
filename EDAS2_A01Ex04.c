#include <stdio.h>
#include <stdlib.h>

//b)
int main(){
    int permutCheck = 1; //Checa se eh (1) ou nao (0) permutacao
    int a, b, c;

    printf("CHECAR POR PERMUTACAO\n");
    printf("Insira dois digitos inteiros (separados por espaco): ");
    scanf("%d %d", &a, &b);

    for(c = 1; c <= 9; c++){
        if(contadigitos(a, c) != contadigitos(b, c)){
            permutCheck = 0;
        }
    }

    if(permutCheck == 1){
        printf("\nRESULTADO: %d eh permutacao de %d.\n\n", a, b);
    }
    else{
        printf("\nRESULTADO: %d nao eh permutacao de %d.\n\n", a, b);
    }

    system("PAUSE");
    return 0;
}

//a)
int contadigitos(int x, int y){
    int conta = 0, resto;

    while(x != 0){
        resto = x % 10;
        x /= 10;
        if(resto == y){
            conta++;
        }
    }

    return conta;
}
