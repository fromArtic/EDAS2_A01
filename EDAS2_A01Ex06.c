#include <stdio.h>
#include <stdlib.h>

#define MAX 20 //Valor limite da sequencia

//Sub-rotinas
int ordemN();
void fibonacci();

int main(){
    printf("SEQUENCIA DE FIBONACCI\n");
    int n = ordemN();
    fibonacci(n);

    system("PAUSE");
    return 0;
}

//Recebe por quantos numeros a sequencia sera composta
int ordemN(){
    int n;

    printf("Informe por quantos numeros a sequencia sera composta: ");
    scanf("%d", &n);
    while((n <= 0) || (n > MAX)){
        if(n <= 0){
            printf("ERRO: A sequencia deve conter ao menos 1 numero. Insira um valor valido: ");
            scanf("%d", &n);
        }
        if(n > MAX){
            printf("ERRO: O valor inserido supera o limite de %d numeros. Insira um valor valido: ", MAX);
            scanf("%d", &n);
        }
    }

    return n;
}

//Criacao da sequencia
void fibonacci(int n){
    int termo1 = 0, termo2 = 1, proxTermo, i;

    printf("\nSequencia de Fibonacci de ordem %d:\n", n);

    for(i = 1; i <= n; i++){
        if(i < n){
            printf("%d, ", termo1);
        }
        else if(i = n){
            printf("%d", termo1);
        }
        proxTermo = termo1 + termo2;
        termo1 = termo2;
        termo2 = proxTermo;
    }

    printf("\n\n");
}
