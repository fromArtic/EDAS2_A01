/*
b)
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 50 //Valor limite da sequencia

//Sub-rotinas
int tamanhoVetor();
int parametros();
int euclides();

int main(){
    int mdc, i;

    printf("CALCULAR MDC\n");

    //Criacao do vetor
    int n = tamanhoVetor();
    int vetor[n];

    //Parametros do vetor
    printf("\nInforme somente valores inteiros e positivos para comporem a sequencia.\n");
    for(i = 0; i < n; i++){
        vetor[i] = parametros(i);
    }

    //Calculo do MDC
    mdc = euclides(vetor[0], vetor[1]);
    for(i = 2; i < n; i++){
        mdc = euclides(vetor[i], mdc);
    }

    //Resultado
    printf("\nRESULTADO: %d\n\n", mdc);

    system("PAUSE");
    return 0;
}

//Recebe por quantos numeros a sequencia sera composta
int tamanhoVetor(){
    int n;

    printf("Informe por quantos numeros a sequencia sera composta: ");
    scanf("%d", &n);

    while((n <= 1) || (n > MAX)){
        if(n <= 1){
            printf("ERRO: A sequencia deve conter ao menos 2 numeros. Insira um valor valido: ");
            scanf("%d", &n);
        }
        if(n > MAX){
            printf("ERRO: O valor inserido supera o limite de %d numeros. Insira um valor valido: ", MAX);
            scanf("%d", &n);
        }
    }

    return n;
}

//Recebe os numeros que compoem a sequencia
int parametros(int i){
    int num;

    printf("numero %d: ", i + 1);
    scanf("%d", &num);
    while(num <= 0){
        printf("ERRO: O numero inserido deve ser positivo. Informe um valor valido: ");
        scanf("%d", &num);
    }

    return num;
}

//Algoritmo de Euclides
int euclides(int numA, int numB){
    int resto;

    resto = numA % numB;

    while(resto != 0){
        numA = numB;
        numB = resto;
        resto = numA % numB;
    }

    return numB;
}
