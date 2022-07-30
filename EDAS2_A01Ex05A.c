/*
a)
*/

#include <stdio.h>
#include <stdlib.h>

//Sub-rotinas
void AeB();
int euclides();
void modulo();
void printMDC();
int restart();

int main(){
    int numA, numB, mdc;
    int loop = 1;

    printf("CALCULAR MDC\n");

    while(loop == 1){
        AeB(&numA, &numB);
        mdc = euclides(&numA, &numB);
        if(mdc < 0){
            modulo(&mdc);
        }
        printMDC(numA, numB, mdc);
        loop = restart();
        printf("\n");
    }

    printf("Encerrando o programa . . .\n");
    system("PAUSE");
    return 0;
}

//Parametros A e B
void AeB(int *numA, int *numB){
    //A
    printf("Informe um valor inteiro e diferente de zero para A (caso negativo, sera considerado o seu modulo): ");
    scanf("%d", &*numA);
    while(*numA == 0){
        printf("O numero inserido deve ser diferente de zero. Informe um valor valido para A: ");
        scanf("%d", &*numA);
    }

    //B
    printf("Agora, informe um valor inteiro e diferente de zero para B (caso negativo, sera considerado o seu modulo): ");
    scanf("%d", &*numB);
    while(*numB == 0){
        printf("O numero inserido deve ser diferente de zero. Informe um valor valido para B: ");
        scanf("%d", &*numB);
    }
}

//Algoritmo de Euclides
int euclides(int *numA, int *numB){
    int num1, num2, resto;

    num1 = *numA;
    num2 = *numB;
    resto = num1 % num2;

    while(resto != 0){
        num1 = num2;
        num2 = resto;
        resto = num1 % num2;
    }

    return num2;
}

//Modulo do resultado (para caso A ou B for negativo, o MDC ainda sair positivo)
void modulo(int *mdc){
    *mdc *= -1;
}

//Exibir MDC
void printMDC(int numA, int numB, int mdc){
    printf("\n- Maximo divisor comum entre %d e %d: %d", numA, numB, mdc);
    printf("\n\n");
}

//Opcao de encerrar o programa
int restart(){
    int loop;

    printf("1 - Inserir outros valores\n");
    printf("2 - Encerrar o programa\n");
    printf("Sua escolha: ");
    scanf("%d", &loop);
    while((loop != 1) && (loop != 2)){
        printf("Informe uma opcao valida: ");
        scanf("%d", &loop);
    }

    return loop;
}
