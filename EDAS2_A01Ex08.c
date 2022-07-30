#include <stdio.h>
#include <stdlib.h>

#define MAX 50000 //Maximo de carros

//Registro Carro
typedef struct{
    char marca[15];
    int ano;
    char cor[10];
    float preco;
}Carro;

//Sub-rotinas
int menu();
Carro cadastro();
void consultaPreco();
void consultaMarca();
void consultaCaracteristicas();

int main(){
    Carro carros[MAX];
    int contadorCarros = 0, choice;

    do{
        choice = menu();
        if((choice < 0) || (choice > 4)){
            printf("\nESCOLHA INVALIDA.\n");
            system("PAUSE");
        }
        switch(choice){
            case 1:
                carros[contadorCarros] = cadastro(&contadorCarros);
                break;
            case 2:
                consultaPreco(carros, contadorCarros);
                break;
            case 3:
                consultaMarca(carros, contadorCarros);
                break;
            case 4:
                consultaCaracteristicas(carros, contadorCarros);
                break;
            case 0:
                printf("\nEncerrando o programa . . .\n");
        }
    }
    while(choice != 0);

    system("PAUSE");
    return 0;
}

//Menu de opcoes
int menu(){
    int choice;
    system("CLS");
    printf("AUTOMOBILIARIA - MENU DE OPCOES\n\n");
    printf("1. Cadastrar veiculo\n");
    printf("2. Listar veiculos abaixo do preco informado\n");
    printf("3. Consultar veiculos de uma marca especifica\n");
    printf("4. Procurar por veiculos com caracteristicas especificas\n");
    printf("0. Sair\n\n");
    printf("Insira sua escolha: ");
    scanf("%d", &choice);
    return choice;
}

//1. Cadastrar veiculo
Carro cadastro(int *contadorCarros){
    Carro carro;

    if(*contadorCarros >= MAX){
        printf("\nO limite maximo de carros cadastrados (%d) foi atingido.\n", MAX);
        system("PAUSE");
    }else{
        getchar();
        printf("\n");
        //Marca
        printf("Marca: ");
        gets(carro.marca);
        //Ano
        printf("Ano de lancamento: ");
        scanf("%d", &carro.ano);
        //Cor
        getchar();
        printf("Cor: ");
        gets(carro.cor);
        //Preco
        printf("Preco: R$");
        scanf("%f", &carro.preco);

        printf("\nCADASTRO CONCLUIDO COM SUCESSO.\n");
        system("PAUSE");
        *contadorCarros = *contadorCarros + 1;
        return carro;
    }
}

//2. Listar veiculos abaixo do preco informado
void consultaPreco(Carro carros[], int contadorCarros){
    float precoMax;
    int i, count = 0, check = 0;

    if(contadorCarros > 0){
        system("CLS");
        printf("CONSULTA POR PRECO\n");
        printf("Valor maximo: R$");
        scanf("%f", &precoMax);

        for(i = 0; i < contadorCarros; i++){
            if(carros[i].preco <= precoMax){
                check = 1;
                count++;
                printf("\n%d. %s (R$%.2f)\n", count, carros[i].marca, carros[i].preco);
                printf("Ano de lancamento: %d\n", carros[i].ano);
                printf("Cor: %s\n", carros[i].cor);
            }
        }
        if(check == 0){
            printf("\nNao foram encontrados registros compativeis ao valor informado (R$%.2f).\n", precoMax);
        }
    }else{
        printf("\nAinda nao ha qualquer veiculo registrado.\n");
    }

    printf("\n");
    system("PAUSE");
}

//3. Consultar veiculos de uma marca especifica
void consultaMarca(Carro carros[], int contadorCarros){
    char marcaDesignada[15];
    int i, count = 0, check = 0;

    if(contadorCarros > 0){
        system("CLS");
        getchar();
        printf("CONSULTA POR MARCA\n");
        printf("Informe a marca que deseja consultar: ");
        gets(marcaDesignada);

        for(i = 0; i < contadorCarros; i++){
            if(stricmp(carros[i].marca, marcaDesignada) == 0){
                check = 1;
                count++;
                printf("\n%d. %s\n", count, carros[i].marca);
                printf("Ano de lancamento: %d\n", carros[i].ano);
                printf("Cor: %s\n", carros[i].cor);
                printf("Preco: R$%.2f\n", carros[i].preco);
            }
        }
        if(check == 0){
            printf("\nNao foram encontrados registros associados a marca informada.\n");
        }
    }else{
        printf("\nAinda nao ha qualquer veiculo registrado.\n");
    }

    printf("\n");
    system("PAUSE");
}

//4. Procurar por veiculos com caracteristicas especificas
void consultaCaracteristicas(Carro carros[], int contadorCarros){
    char marcaDesignada[15];
    int anoDesignado;
    char corDesignada[10];
    int i, count = 0, check = 0;

    if(contadorCarros > 0){
        system("CLS");
        getchar();
        printf("BUSCA AVANCADA\n");
        //Marca
        printf("Marca: ");
        gets(marcaDesignada);
        //Ano
        printf("Ano: ");
        scanf("%d", &anoDesignado);
        //Cor
        getchar();
        printf("Cor: ");
        gets(corDesignada);

        for(i = 0; i < contadorCarros; i++){
            if(stricmp(carros[i].marca, marcaDesignada) == 0){
                if(carros[i].ano == anoDesignado){
                    if(stricmp(carros[i].cor,corDesignada) == 0){
                        check = 1;
                        count++;
                        printf("\n%d. Preco: R$%.2f\n", count, carros[i].preco);
                    }
                }
            }
        }
        if(check == 0){
            printf("\nNao foram encontrados registros compativeis com as informacoes especificadas.\n");
        }
    }else{
        printf("\nAinda nao ha qualquer veiculo registrado.\n");
    }

    printf("\n");
    system("PAUSE");
}
