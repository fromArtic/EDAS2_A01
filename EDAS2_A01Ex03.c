#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;

    printf("SIMULACAO DO JOGO DA TORRE DE HANOI\nNumero de discos: ");
    scanf("%d", &n);

    while(n < 1){
        printf("\nERRO: Eh necessario ao menos um disco para o inicio do jogo.\nInsira um valor valido: ");
        scanf("%d", &n);
    }

    printf("\nINICIO: ha %d disco(s) no pino A.\n", n);
    moverDisco(n, 'A', 'B', 'C');
    printf("\n\nCONCLUSAO: todos os discos foram movidos para o pino C.");

    printf("\n\nEncerrando simulacao . . .\n");
    system("PAUSE");
    return 0;
}

/*
n: discos
origem: pino A
aux: pino B
destino: pino C
*/
void moverDisco(int n, char origem, char aux, char destino){
    if(n >= 1){
        moverDisco(n - 1, origem, destino, aux);
        printf("\n- Disco %d: %c -> %c", n, origem, destino);
        moverDisco(n - 1, aux, origem, destino);
    }
}
