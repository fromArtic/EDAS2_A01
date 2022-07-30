#include <stdio.h>
#include <stdlib.h>

//Sub-rotinas
float K();
void KtoF(float k);

int main(){
    float k;
    int check = 0;

    printf("CONVERSAO DE KELVIN PARA FAHRENHEIT\n");
    k = K(&check);
    if(check == 1){
        KtoF(k);
    }

    system("PAUSE");
    return 0;
}

//Temperatura em kelvins
float K(int *check){
    float k;

    printf("Informe a temperatura em kelvins: ");
    scanf("%f", &k);

    //Checa se eh possivel realizar a conversao
    if(k >= 0){
        *check = 1;
        return k;
    }else{
        printf("\nERRO: A temperatura inserida (%.2f K) eh inferior ao zero absoluto, correspondente a menor temperatura possivel a ser atingida (0 K, equivalente a -459,67 graus F.).\n\n", k);
    }
}

//Conversao de Kelvin para Fahrenheit
void KtoF(float k){
    float f;

    //Formula da conversao de K para F
    f = (k * 1.8) - 459.67;

    printf("\n%.2f K para Fahrenheit: %.2f graus F.\n\n", k, f);
}
