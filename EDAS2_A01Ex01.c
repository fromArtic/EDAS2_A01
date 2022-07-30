#include <stdio.h>
#include <stdlib.h>

#define MAX 50 //Maximo de contas
#define numeroTAM 9 //Quantidade de digitos do numero da conta

//Registro Conta
typedef struct{
    char nome[35];
    char numeroConta[numeroTAM];
    float saldo;
    char consulta[35];
}Conta;

//Sub-rotinas
int menu(); //Menu de opcoes
Conta cadastrarConta(); //1. Cadastramento da conta
void removerConta(); //2. Remocao da conta
void deposito(); //3. Deposito
void saque(); //4. Saque
void consulta(); //5. Consulta
void buscarCliente(); //Requisicao do nome ou numero da conta
void checkMultiplasContas(); //Escolha entre possiveis multiplas contas (p/ saque e deposito)

int main(){
    Conta contas[MAX];
    int choice, contadorContas = 0;

    do{
        //Menu de opcoes
        choice = menu();
        if((choice < 0) || (choice > 5)){
            printf("\nESCOLHA INVALIDA.\n");
            system("PAUSE");
        }
        switch(choice){
            //Cadastramento da conta
            case 1:
                if((contadorContas < MAX)){
                    contas[contadorContas] = cadastrarConta(contas);
                    contadorContas++;
                }else{
                    printf("\nO limite maximo de contas cadastradas (%d) foi atingido.\n", MAX);
                    system("PAUSE");
                }
                break;
            //Remocao da conta
            case 2:
                if(contadorContas > 0){
                    buscarCliente(choice);
                    removerConta(contas, contadorContas);
                }else{
                    printf("\nVoce deve ter ao menos uma conta cadastrada para acessar as outras opcoes.\n");
                    system("PAUSE");
                }
                break;
            //Deposito
            case 3:
                if(contadorContas > 0){
                    buscarCliente(choice);
                    checkMultiplasContas(contas, contadorContas);
                    deposito(contas, contadorContas);
                }else{
                    printf("\nVoce deve ter ao menos uma conta cadastrada para acessar as outras opcoes.\n");
                    system("PAUSE");
                }
                break;
            //Saque
            case 4:
                if(contadorContas > 0){
                    buscarCliente(choice);
                    checkMultiplasContas(contas, contadorContas);
                    saque(contas, contadorContas);
                }else{
                    printf("\nVoce deve ter ao menos uma conta cadastrada para acessar as outras opcoes.\n");
                    system("PAUSE");
                }
                break;
            //Consulta
            case 5:
                if(contadorContas > 0){
                    buscarCliente(choice);
                    consulta(contas, contadorContas);
                }else{
                    printf("\nVoce deve ter ao menos uma conta cadastrada para acessar as outras opcoes.\n");
                    system("PAUSE");
                }
                break;
            //Sair
            case 0:
                printf("\nEncerrando o programa . . .\n");
        }
    }
    while(choice != 0);

    system("PAUSE");
    return 0;
}

//Menu de opcoes
int menu(int choice){
    system("CLS");
    printf("BANCO - MENU DE OPCOES\n\n");
    printf("1. Cadastramento da conta\n");
    printf("2. Remocao da conta\n");
    printf("3. Deposito\n");
    printf("4. Saque\n");
    printf("5. Consulta\n");
    printf("0. Sair\n\n");
    printf("Insira sua escolha: ");
    scanf("%d", &choice);
    return choice;
}

//1. Cadastramento da conta
Conta cadastrarConta(Conta contas[]){
    Conta conta;
    int i, check = 0;

    getchar();
    printf("\n");

    //Nome
    printf("Informe o nome que deseja registrar na conta: ");
    gets(conta.nome);

    //Numero
    printf("Insira o numero da conta (%d digitos): ", numeroTAM);
    gets(conta.numeroConta);
    for(i = 0; i < MAX; i++){
        //Quantidade de digitos invalida
        while(strlen(conta.numeroConta) != numeroTAM){
            printf("ERRO: O numero da conta deve possuir %d digitos. Insira um numero valido para a conta: ", numeroTAM);
            gets(conta.numeroConta);
        }
        //Numero ja vinculado a outra conta
        if(stricmp(contas[i].numeroConta, conta.numeroConta) == 0){
            check = 1;
            while(check == 1){
                printf("ERRO: O numero inserido ja esta vinculado a outra conta. Insira outro numero: ");
                gets(conta.numeroConta);
                if(stricmp(contas[i].numeroConta, conta.numeroConta) != 0){
                    check = 0;
                }
            }
        }
    }

    //Saldo
    printf("Insira o saldo: R$");
    scanf("%f", &conta.saldo);

    printf("\nCADASTRO CONCLUIDO COM SUCESSO.\n");
    system("PAUSE");
    return conta;
}

//2. Remocao da conta
void removerConta(Conta contas[], int contadorContas){
    Conta conta;
    int i, check = 0;

    printf("\n");

    for(i = 0; i < contadorContas; i++){
        if((stricmp(contas[i].numeroConta, conta.consulta) == 0)){
            strcpy(contas[i].nome, "null");
            strcpy(contas[i].numeroConta, "551081737");
            contas[i].saldo = 0;
            printf("Operacao concluida, a conta foi removida do sistema.\n");
            check++;
        }
        if((stricmp(contas[i].nome, conta.consulta) == 0)){
            printf("ERRO: informe somente o NUMERO da conta que deseja remover.\n");
            check++;
            break;
        }
    }

    if(check == 0){
        printf("Nao foram encontrados registros sobre o nome ou numero informado.\n");
    }

    system("PAUSE");
}

//3. Deposito
void deposito(Conta contas[], int contadorContas){
    Conta conta;
    int i, check = 0;
    float deposito;

    for(i = 0; i < contadorContas; i++){
        if(stricmp(contas[i].numeroConta, conta.consulta) == 0){
            check++;
            system("CLS");
            printf("REALIZAR DEPOSITO BANCARIO\n\n");
            printf("Nome do cliente: %s - Numero da conta: %s\n", contas[i].nome, contas[i].numeroConta);
            printf("Saldo atual: R$%.2f\n\n", contas[i].saldo);
            printf("Informe a quantia que deseja depositar: R$");
            scanf("%f", &deposito);
            while(deposito < 0){
                printf("\nERRO: Voce nao pode depositar uma quantia negativa sobre seu saldo.\n");
                printf("Informe uma quantia valida que deseja depositar: R$");
                scanf("%f", &deposito);
            }
            if(deposito >= 0){
                contas[i].saldo += deposito;
            }
            printf("\nDEPOSITO EFETUADO COM SUCESSO.\n");
            break;
        }
    }

    if(check == 0){
        printf("\nNao foram encontrados registros sobre o nome ou numero informado.\n");
    }

    system("PAUSE");
}

//4. Saque
void saque(Conta contas[], int contadorContas){
    Conta conta;
    int i, check = 0;
    float saque;

    for(i = 0; i < contadorContas; i++){
        if(stricmp(contas[i].numeroConta, conta.consulta) == 0){
            check++;
            system("CLS");
            printf("REALIZAR SAQUE\n\n");
            printf("Nome do cliente: %s - Numero da conta: %s\n", contas[i].nome, contas[i].numeroConta);
            printf("Saldo atual: R$%.2f\n\n", contas[i].saldo);
            printf("Informe a quantia que deseja sacar: R$");
            scanf("%f", &saque);
            while(saque > contas[i].saldo){
                printf("\nERRO: Voce nao pode sacar uma quantia maior que seu proprio saldo.\n");
                printf("Informe uma quantia valida que deseja sacar: R$");
                scanf("%f", &saque);
            }
            if(saque <= contas[i].saldo){
                contas[i].saldo -= saque;
            }
            printf("\nSAQUE EFETUADO COM SUCESSO.\n");
            break;
        }
    }

    if(check == 0){
        printf("\nNao foram encontrados registros sobre o nome ou numero informado.\n");
    }

    system("PAUSE");
}
//5. Consulta
void consulta(Conta contas[], int contadorContas){
    Conta conta;
    int i, check = 0;

    system("CLS");
    printf("DADOS DA CONTA\n\n");

    for(i = 0; i < contadorContas; i++){
        if((stricmp(contas[i].nome, conta.consulta) == 0) || (stricmp(contas[i].numeroConta, conta.consulta) == 0)){
            printf("Nome do cliente: %s\n", contas[i].nome);
            printf("Numero da conta: %s\n", contas[i].numeroConta);
            printf("Saldo: R$%.2f\n\n", contas[i].saldo);
            check++;
        }
    }

    if(check == 0){
        printf("Nao foram encontrados registros sobre o nome ou numero informado.\n\n");
    }

    system("PAUSE");
}

//Requisicao do nome ou numero da conta
void buscarCliente(int choice){
    Conta conta;

    getchar();
    printf("\n");

    if(choice == 2){
        printf("Informe o numero da conta que deseja remover: ");
    }
    if(choice == 3){
        printf("Informe o nome ou numero da conta na qual deseja aplicar o deposito: ");
    }
    if(choice == 4){
        printf("Informe o nome ou numero da conta na qual deseja efetuar o saque: ");
    }
    if(choice == 5){
        printf("Informe o nome ou numero da conta a ser consultada: ");
    }

    gets(conta.consulta);
    return conta;
}

//Checa, caso o cliente tenha informado um nome, qual conta vinculada deseja sacar ou depositar
void checkMultiplasContas(Conta contas[], int contadorContas){
    Conta conta;
    int i;

    for(i = 0; i < contadorContas; i++){
        if(stricmp(contas[i].nome, conta.consulta) == 0){
        system("CLS");

        for(i = 0; i < contadorContas; i++){
            if(stricmp(contas[i].nome, conta.consulta) == 0){
                printf("Nome do cliente: %s", contas[i].nome);
                break;
            }
        }

        printf("\n\nCONTAS REGISTRADAS");

        for(i = 0; i < contadorContas; i++){
            if(stricmp(contas[i].nome, conta.consulta) == 0){
                printf("\n- %s", contas[i].numeroConta);
            }
        }

        printf("\n\nInsira o numero da conta que deseja acessar: ");
        gets(conta.consulta);
        return conta;
        break;
        }
    }
}
