#include <stdio.h>
#include <stdlib.h>

#define MAX 100 //Maximo de contatos

//Registro Contato
typedef struct{
    char nome[64];
    char email[64];

    struct{
        char rua[64];
        int numero;
        char complemento[64];
        char bairro[64];
        int cep;
        char cidade[64];
        char estado[64];
        char pais[64];
    }endereco;

    struct{
        int ddd;
        int numero;
    }telefone;

    struct{
        int dia;
        int mes;
        int ano;
    }aniversario;

    char especial[64];
}Contato;

//Sub-rotinas
int menu();
Contato cadastro();
void buscaNome();
void buscaMes();
void buscaDiaMes();
void ordemAlfabetica();
void excluirContato();
void exibirAgenda();

int main(){
    Contato contatos[MAX];
    int contadorContatos = 0, choice;

    do{
        choice = menu();
        if((choice < 0) || (choice > 7)){
            printf("\nESCOLHA INVALIDA.\n");
            system("PAUSE");
        }
        switch(choice){
            case 1:
                contatos[contadorContatos] = cadastro(&contadorContatos, contatos);
                break;
            case 2:
                buscaNome(contatos, contadorContatos);
                break;
            case 3:
                buscaMes(contatos, contadorContatos);
                break;
            case 4:
                buscaDiaMes(contatos, contadorContatos);
                break;
            case 5:
                ordemAlfabetica(contatos, contadorContatos);
                break;
            case 6:
                excluirContato(contatos, &contadorContatos);
                break;
            case 7:
                exibirAgenda(contatos, contadorContatos);
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
    printf("AGENDA TELEFONICA DIGITAL - MENU DE OPCOES\n\n");
    printf("1. Registrar novo contato\n");
    printf("2. Buscar contato por nome\n");
    printf("3. Buscar contato por mes de aniversario\n");
    printf("4. Buscar contato por dia e mes de aniversario\n");
    printf("5. Listar contatos por ordem alfabetica\n");
    printf("6. Excluir contato\n");
    printf("7. Exibir agenda completa\n");
    printf("0. Sair\n\n");
    printf("Insira sua escolha: ");
    scanf("%d", &choice);
    return choice;
}

//1. Registrar novo contato
Contato cadastro(int *contadorContatos, Contato contatos[]){
    Contato contato;

    if(*contadorContatos >= MAX){
        printf("\nO total de contatos registrados (%d) foi atingido.\n", MAX);
        system("PAUSE");
    }else{
        getchar();
        printf("\n-- NOVO CONTATO --\n\n");
        //Nome
        printf("Nome: ");
        gets(contato.nome);
        //E-mail
        printf("E-mail: ");
        gets(contato.email);
        //Rua
        printf("\nRua: ");
        gets(contato.endereco.rua);
        //Numero da casa
        printf("Numero da casa: ");
        scanf("%d", &contato.endereco.numero);
        //Complemento
        getchar();
        printf("Complemento: ");
        gets(contato.endereco.complemento);
        //Bairro
        printf("Bairro: ");
        gets(contato.endereco.bairro);
        //CEP
        printf("CEP: ");
        scanf("%d", &contato.endereco.cep);
        //Cidade
        getchar();
        printf("Cidade: ");
        gets(contato.endereco.cidade);
        //Estado
        printf("Estado: ");
        gets(contato.endereco.estado);
        //Pais
        printf("Pais: ");
        gets(contato.endereco.pais);
        //DDD
        printf("\nDDD: ");
        scanf("%d", &contato.telefone.ddd);
        //Numero do celular
        printf("Numero do celular (somente digitos): ");
        scanf("%d", &contato.telefone.numero);
        //Dia em que nasceu
        printf("\nDia em que nasceu: ");
        scanf("%d", &contato.aniversario.dia);
        while((contato.aniversario.dia <= 0) || (contato.aniversario.dia > 31)){
            printf("ERRO: Insira um numero valido. Dia em que nasceu: ");
            scanf("%d", &contato.aniversario.dia);
        }
        //Mes em que nasceu
        printf("Mes em que nasceu (somente digitos): ");
        scanf("%d", &contato.aniversario.mes);
        while((contato.aniversario.mes <= 0) || (contato.aniversario.mes > 12)){
            printf("ERRO: Insira um numero valido. Mes em que nasceu: ");
            scanf("%d", &contato.aniversario.mes);
        }
        //Ano em que nasceu
        printf("Ano em que nasceu: ");
        scanf("%d", &contato.aniversario.ano);
        //Observacao especial
        getchar();
        printf("Observacao especial: ");
        gets(contato.especial);

        printf("\nCADASTRO CONCLUIDO COM SUCESSO.\n");
        system("PAUSE");
        *contadorContatos = *contadorContatos + 1;
        return contato;
    }
}

//2. Buscar contato por nome
void buscaNome(Contato contatos[], int contadorContatos){
    char nomeDesignado[64];
    int i, count = 0, check = 0;

    if(contadorContatos > 0){
        system("CLS");
        getchar();
        printf("BUSCA POR NOME\n");
        printf("Informe o nome que deseja buscar: ");
        gets(nomeDesignado);

        for(i = 0; i < contadorContatos; i++){
            if(stricmp(contatos[i].nome, nomeDesignado) == 0){
                check = 1;
                count++;
                printf("\n%d. %s\n", count, contatos[i].nome);
                printf("- E-mail: %s\n", contatos[i].email);
                printf("- Rua: %s\n", contatos[i].endereco.rua);
                printf("- Numero da casa: %d\n", contatos[i].endereco.numero);
                printf("- Complemento: %s\n", contatos[i].endereco.complemento);
                printf("- Bairro: %s\n", contatos[i].endereco.bairro);
                printf("- CEP: %d\n", contatos[i].endereco.cep);
                printf("- Cidade: %s\n", contatos[i].endereco.cidade);
                printf("- Estado: %s\n", contatos[i].endereco.estado);
                printf("- Pais: %s\n", contatos[i].endereco.pais);
                printf("- DDD: %d\n", contatos[i].telefone.ddd);
                printf("- Numero do celular: %d\n", contatos[i].telefone.numero);
                printf("- Dia em que nasceu: %d\n", contatos[i].aniversario.dia);
                printf("- Mes em que nasceu: %d\n", contatos[i].aniversario.mes);
                printf("- Ano em que nasceu: %d\n", contatos[i].aniversario.ano);
                printf("- Observacao especial: %s\n", contatos[i].especial);
            }
        }
        if(check == 0){
            printf("\nNao foram encontrados registros associados ao nome informado.\n");
        }
    }else{
        printf("\nAinda nao ha contatos registrados.\n");
    }

    printf("\n");
    system("PAUSE");
}

//3. Buscar contato por mes de aniversario
void buscaMes(Contato contatos[], int contadorContatos){
    int mesDesignado;
    int i, count = 0, check = 0;

    if(contadorContatos > 0){
        system("CLS");
        getchar();
        printf("BUSCA POR MES DE ANIVERSARIO\n");
        printf("Informe o mes que deseja buscar (somente digitos): ");
        scanf("%d", &mesDesignado);

        for(i = 0; i < contadorContatos; i++){
            if(contatos[i].aniversario.mes == mesDesignado){
                check = 1;
                count++;
                printf("\n%d. %s\n", count, contatos[i].nome);
                printf("- E-mail: %s\n", contatos[i].email);
                printf("- Rua: %s\n", contatos[i].endereco.rua);
                printf("- Numero da casa: %d\n", contatos[i].endereco.numero);
                printf("- Complemento: %s\n", contatos[i].endereco.complemento);
                printf("- Bairro: %s\n", contatos[i].endereco.bairro);
                printf("- CEP: %d\n", contatos[i].endereco.cep);
                printf("- Cidade: %s\n", contatos[i].endereco.cidade);
                printf("- Estado: %s\n", contatos[i].endereco.estado);
                printf("- Pais: %s\n", contatos[i].endereco.pais);
                printf("- DDD: %d\n", contatos[i].telefone.ddd);
                printf("- Numero do celular: %d\n", contatos[i].telefone.numero);
                printf("- Dia em que nasceu: %d\n", contatos[i].aniversario.dia);
                printf("- Mes em que nasceu: %d\n", contatos[i].aniversario.mes);
                printf("- Ano em que nasceu: %d\n", contatos[i].aniversario.ano);
                printf("- Observacao especial: %s\n", contatos[i].especial);
            }
        }
        if(check == 0){
            printf("\nNao foram encontrados registros associados ao mes informado.\n");
        }
    }else{
        printf("\nAinda nao ha contatos registrados.\n");
    }

    printf("\n");
    system("PAUSE");
}

//4. Buscar contato por dia e mes de aniversario
void buscaDiaMes(Contato contatos[], int contadorContatos){
    int diaDesignado, mesDesignado;
    int i, count = 0, check = 0;

    if(contadorContatos > 0){
        system("CLS");
        getchar();
        printf("BUSCA POR DIA E MES DE ANIVERSARIO\n");
        printf("Informe o dia que deseja buscar: ");
        scanf("%d", &diaDesignado);
        printf("Agora, informe o mes que deseja buscar (somente digitos): ");
        scanf("%d", &mesDesignado);

        for(i = 0; i < contadorContatos; i++){
            if(contatos[i].aniversario.dia == diaDesignado){
                if(contatos[i].aniversario.mes == mesDesignado){
                    check = 1;
                    count++;
                    printf("\n%d. %s\n", count, contatos[i].nome);
                    printf("- E-mail: %s\n", contatos[i].email);
                    printf("- Rua: %s\n", contatos[i].endereco.rua);
                    printf("- Numero da casa: %d\n", contatos[i].endereco.numero);
                    printf("- Complemento: %s\n", contatos[i].endereco.complemento);
                    printf("- Bairro: %s\n", contatos[i].endereco.bairro);
                    printf("- CEP: %d\n", contatos[i].endereco.cep);
                    printf("- Cidade: %s\n", contatos[i].endereco.cidade);
                    printf("- Estado: %s\n", contatos[i].endereco.estado);
                    printf("- Pais: %s\n", contatos[i].endereco.pais);
                    printf("- DDD: %d\n", contatos[i].telefone.ddd);
                    printf("- Numero do celular: %d\n", contatos[i].telefone.numero);
                    printf("- Dia em que nasceu: %d\n", contatos[i].aniversario.dia);
                    printf("- Mes em que nasceu: %d\n", contatos[i].aniversario.mes);
                    printf("- Ano em que nasceu: %d\n", contatos[i].aniversario.ano);
                    printf("- Observacao especial: %s\n", contatos[i].especial);
                }
            }
        }
        if(check == 0){
            printf("\nNao foram encontrados registros associados a data informada.\n");
        }
    }else{
        printf("\nAinda nao ha contatos registrados.\n");
    }

    printf("\n");
    system("PAUSE");
}

//5. Listar contatos por ordem alfabetica
ordemAlfabetica(Contato contatos[], int contadorContatos){
    Contato contatosAZ[MAX], aux[MAX];
    int i, j, count = 0;

    if(contadorContatos > 0){
        system("CLS");
        printf("CONTATOS A-Z\n");

        //Copia o vetor contatos para contatosAZ, mantendo intacta a ordem do vetor principal
        for(i = 0; i < contadorContatos; i++){
            contatosAZ[i] = contatos[i];
        }

        //Reordena o vetor contatosAZ em ordem alfabetica
        for(i = 0; i < contadorContatos; i++){
            for(j = 0; j < contadorContatos; j++){
                if(strcmp(contatosAZ[i].nome, contatosAZ[j].nome) < 0){
                    aux[i] = contatosAZ[i];
                    contatosAZ[i] = contatosAZ[j];
                    contatosAZ[j] = aux[i];
                }
            }
        }

        //Lista os contatos
        for(i = 0; i < contadorContatos; i++){
            count++;
            printf("\n%d. %s\n", count, contatosAZ[i].nome);
            printf("- E-mail: %s\n", contatosAZ[i].email);
            printf("- Rua: %s\n", contatosAZ[i].endereco.rua);
            printf("- Numero da casa: %d\n", contatosAZ[i].endereco.numero);
            printf("- Complemento: %s\n", contatosAZ[i].endereco.complemento);
            printf("- Bairro: %s\n", contatosAZ[i].endereco.bairro);
            printf("- CEP: %d\n", contatosAZ[i].endereco.cep);
            printf("- Cidade: %s\n", contatosAZ[i].endereco.cidade);
            printf("- Estado: %s\n", contatosAZ[i].endereco.estado);
            printf("- Pais: %s\n", contatosAZ[i].endereco.pais);
            printf("- DDD: %d\n", contatosAZ[i].telefone.ddd);
            printf("- Numero do celular: %d\n", contatosAZ[i].telefone.numero);
            printf("- Dia em que nasceu: %d\n", contatosAZ[i].aniversario.dia);
            printf("- Mes em que nasceu: %d\n", contatosAZ[i].aniversario.mes);
            printf("- Ano em que nasceu: %d\n", contatosAZ[i].aniversario.ano);
            printf("- Observacao especial: %s\n", contatosAZ[i].especial);
        }
    }else{
        printf("\nAinda nao ha contatos registrados.\n");
    }

    printf("\n");
    system("PAUSE");
}

//6. Excluir contato
void excluirContato(Contato contatos[], int *contadorContatos){
    char nomeDesignado[64], emailDesignado[64];
    int i, check = 0;

    if(*contadorContatos > 0){
        system("CLS");
        getchar();
        printf("EXCLUIR CONTATO\n");
        printf("Informe o nome do contato que deseja excluir: ");
        gets(nomeDesignado);
        printf("Agora, informe o e-mail do contato que deseja excluir: ");
        gets(emailDesignado);

        for(i = 0; i < *contadorContatos; i++){
            if(stricmp(contatos[i].nome, nomeDesignado) == 0){
                if(stricmp(contatos[i].email, emailDesignado) == 0){
                    while(i < *contadorContatos){
                        contatos[i] = contatos[i + 1];
                        i++;
                    }
                    printf("\nCONTATO EXCLUIDO COM SUCESSO.\n");
                    check = 1;
                    *contadorContatos = *contadorContatos - 1;
                }
            }
        }
        if(check == 0){
            printf("\nNao foram encontrados registros associados aos dados informados.\n");
        }
    }else{
        printf("\nAinda nao ha contatos registrados.\n");
    }

    printf("\n");
    system("PAUSE");
}


//7. Exibir agenda completa
void exibirAgenda(Contato contatos[], int contadorContatos){
    int choice, i, count = 0;

    if(contadorContatos > 0){
        system("CLS");
        printf("EXIBIR AGENDA COMPLETA\n");
        printf("1 - Mostrar somente nome, e-mail e telefone\n");
        printf("2 - Mostrar todas as informacoes\n");
        printf("Insira sua escolha: ");
        scanf("%d", &choice);
        while((choice != 1) && (choice != 2)){
            printf("\nESCOLHA INVALIDA. Informe uma opcao valida: ");
            scanf("%d", &choice);
        }

        system("CLS");
        printf("EXIBIR AGENDA COMPLETA\n");
        for(i = 0; i < contadorContatos; i++){
            count++;
            printf("\n%d. %s\n", count, contatos[i].nome);
            printf("- E-mail: %s\n", contatos[i].email);
            if(choice == 2){
                printf("- Rua: %s\n", contatos[i].endereco.rua);
                printf("- Numero da casa: %d\n", contatos[i].endereco.numero);
                printf("- Complemento: %s\n", contatos[i].endereco.complemento);
                printf("- Bairro: %s\n", contatos[i].endereco.bairro);
                printf("- CEP: %d\n", contatos[i].endereco.cep);
                printf("- Cidade: %s\n", contatos[i].endereco.cidade);
                printf("- Estado: %s\n", contatos[i].endereco.estado);
                printf("- Pais: %s\n", contatos[i].endereco.pais);
                printf("- DDD: %d\n", contatos[i].telefone.ddd);
            }
            printf("- Numero do celular: %d\n", contatos[i].telefone.numero);
            if(choice == 2){
                printf("- Dia em que nasceu: %d\n", contatos[i].aniversario.dia);
                printf("- Mes em que nasceu: %d\n", contatos[i].aniversario.mes);
                printf("- Ano em que nasceu: %d\n", contatos[i].aniversario.ano);
                printf("- Observacao especial: %s\n", contatos[i].especial);
            }
        }
    }else{
        printf("\nAinda nao ha contatos registrados.\n");
    }

    printf("\n");
    system("PAUSE");
}
