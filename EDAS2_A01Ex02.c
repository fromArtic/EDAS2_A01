#include <stdio.h>
#include <stdlib.h>

#define MAX 1000 //Maximo de filmes
#define codigoTAM 5 //Quantidade de digitos do codigo do filme

//Registro Filme
typedef struct{
    char titulo[213];
    char diretor[35];
    int ano;
    char genero[15];
    char sinopse[500];
    char codigo[codigoTAM];
    char consulta[213];
}Filme;

//Sub-rotinas
int menu(); //Menu de opcoes
Filme cadastrar(); //a) Cadastrar filme
void alterar(); //b) Alterar filme
void listarPorCadastro(); //c) Listar filmes
void listarPorAno(); //d) Listar filmes por ano
void consultar(); //e) Consultar um filme em especifico pelo nome
Filme buscarFilme(); //Buscar por filme

int main(){
    Filme filmes[MAX],  filmeConsulta;
    int choice, contadorFilmes = 0;

    do{
        //Menu de opcoes
        choice = menu();
        if((choice < 0) || (choice > 5)){
            printf("\nESCOLHA INVALIDA.\n");
            system("PAUSE");
        }
        switch(choice){
            //Cadastrar filme
            case 1:
                if((contadorFilmes < MAX)){
                    filmes[contadorFilmes] = cadastrar(filmes, &contadorFilmes);
                }else{
                    printf("\nO limite maximo de filmes cadastrados (%d) foi atingido.\n", MAX);
                    system("PAUSE");
                }
                break;
            //Alterar informacoes de um filme
            case 2:
                if(contadorFilmes > 0){
                    filmeConsulta = buscarFilme(choice);
                    alterar(filmes, contadorFilmes, filmeConsulta);
                }else{
                    printf("\nAinda nao ha registros.\n");
                    system("PAUSE");
                }
                break;
            //Listar filmes por ordem de cadastro
            case 3:
                if(contadorFilmes > 0){
                    listarPorCadastro(filmes, contadorFilmes);
                }else{
                    printf("\nAinda nao ha registros.\n");
                    system("PAUSE");
                }
                break;
            //Listar filmes por ano de lancamento
            case 4:
                if(contadorFilmes > 0){
                    listarPorAno(filmes, contadorFilmes);
                }else{
                    printf("\nAinda nao ha registros.\n");
                    system("PAUSE");
                }
                break;
            //Procurar filme por nome
            case 5:
                if(contadorFilmes > 0){
                    filmeConsulta = buscarFilme(choice);
                    consultar(filmes, contadorFilmes, filmeConsulta);
                }else{
                    printf("\nAinda nao ha registros.\n");
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
    printf("LOCADORA - MENU DE OPCOES\n\n");
    printf("1. Cadastrar filme\n");
    printf("2. Alterar informacoes de um filme\n");
    printf("3. Listar filmes por ordem de cadastro\n");
    printf("4. Listar filmes por ano (do mais recente para o mais antigo)\n");
    printf("5. Procurar filme por nome\n");
    printf("0. Sair\n\n");
    printf("Insira sua escolha: ");
    scanf("%d", &choice);
    return choice;
}

//a) Cadastrar filme
Filme cadastrar(Filme filmes[], int *contadorFilmes){
    Filme filme;
    int i, check = 0;

    //Titulo, diretor, ano de lancamento, genero e sinopse
    getchar();
    printf("\nNOVO CADASTRO DE FILME\n\n");
    printf("Titulo: ");
    gets(filme.titulo);
    printf("Diretor: ");
    gets(filme.diretor);
    printf("Ano de lancamento: ");
    scanf("%d", &filme.ano);
    getchar();
    printf("Genero: ");
    gets(filme.genero);
    printf("Sinopse: ");
    gets(filme.sinopse);

    //Codigo
    printf("Codigo (%d digitos): ", codigoTAM);
    gets(filme.codigo);
    for(i = 0; i < MAX; i++){
        //Quantidade de digitos invalida
        while(strlen(filme.codigo) != codigoTAM){
            printf("ERRO: O codigo deve possuir %d digitos. Insira um codigo valido: ", codigoTAM);
            gets(filme.codigo);
        }
        //Codigo ja vinculado a outro filme
        if(stricmp(filme.codigo, filmes[i].codigo) == 0){
            check = 1;
            while(check == 1){
                printf("ERRO: O codigo inserido ja esta vinculado a outro filme. Insira outro codigo: ");
                gets(filme.codigo);
                if((filme.codigo, filmes[i].codigo) != 0){
                    check = 0;
                }
            }
        }
    }

    ++*contadorFilmes;
    printf("\nCADASTRO CONCLUIDO COM SUCESSO.\n");
    system("PAUSE");
    return filme;
}

//b) Alterar filme
void alterar(Filme filmes[], int contadorFilmes, Filme filmeConsulta){
    int i, j, check = 0, check2 = 0;

    system("CLS");
    printf("ALTERAR INFORMACOES\n\n");

    //Informacoes atuais
    for(i = 0; i < contadorFilmes; i++){
        if(stricmp(filmes[i].codigo, filmeConsulta.consulta) == 0){
            printf("INFORMACOES ATUAIS\n");
            printf("Titulo: %s\n", filmes[i].titulo);
            printf("Diretor: %s\n", filmes[i].diretor);
            printf("Ano de lancamento: %d\n", filmes[i].ano);
            printf("Genero: %s\n", filmes[i].genero);
            printf("Sinopse: %s\n", filmes[i].sinopse);
            printf("Codigo: %s\n\n", filmes[i].codigo);
            check++;
        }
    }

    //Alteracao das informacoes
    for(i = 0; i < contadorFilmes; i++){
        if(stricmp(filmes[i].codigo, filmeConsulta.consulta) == 0){
            //Titulo, diretor, ano de lancamento, genero e sinopse
            printf("Novo titulo: ");
            gets(filmes[i].titulo);
            printf("Novo diretor: ");
            gets(filmes[i].diretor);
            printf("Novo ano de lancamento: ");
            scanf("%d", &filmes[i].ano);
            getchar();
            printf("Novo genero: ");
            gets(filmes[i].genero);
            printf("Nova sinopse: ");
            gets(filmes[i].sinopse);

            //Codigo
            printf("Novo codigo (%d digitos): ", codigoTAM);
            gets(filmes[i].codigo);
            for(j = 0; j < MAX; j++){
                //Quantidade de digitos invalida
                while(strlen(filmes[i].codigo) != codigoTAM){
                    printf("ERRO: O codigo deve possuir %d digitos. Insira um novo codigo valido: ", codigoTAM);
                    gets(filmes[i].codigo);
                }
                //Codigo ja vinculado a outro filme
                if(stricmp(filmes[i].codigo, filmes[j].codigo) == 0){
                    check2 = 1;
                    while(check2 == 1){
                        printf("ERRO: O codigo inserido ja esta vinculado a outro filme. Insira outro codigo: ");
                        gets(filmes[i].codigo);
                        if((filmes[i].codigo, filmes[j].codigo) != 0){
                            check2 = 0;
                        }
                    }
                }
            }

            printf("\nINFORMACOES ALTERADAS COM SUCESSO.\n");
        }
    }

    for(i = 0; i < contadorFilmes; i++){
        if(stricmp(filmes[i].titulo, filmeConsulta.consulta) == 0){
            printf("Para alterar o conteudo desse titulo voce deve informar seu respectivo codigo.\n\n");
            check++;
        }
    }

    if(check == 0){
        printf("Nao foram encontrados registros sobre o codigo informado.\n\n");
    }

    system("PAUSE");
}

//c) Listar filmes
void listarPorCadastro(Filme filme[], int contadorFilmes){
    int i;

    system("CLS");
    printf("FILMES REGISTRADOS\n\n");

    for(i = 0; i < contadorFilmes; i++){
        printf("%d. %s\n", i + 1, filme[i].titulo);
        printf("Diretor: %s\n", filme[i].diretor);
        printf("Ano de lancamento: %d\n", filme[i].ano);
        printf("Genero: %s\n", filme[i].genero);
        printf("Sinopse: %s\n", filme[i].sinopse);
        printf("Codigo: %s\n", filme[i].codigo);
        printf("\n");
    }

    system("PAUSE");
}

//d) Listar filmes por ano
void listarPorAno(Filme filme[], int contadorFilmes){
    int i, j;

    system("CLS");
    printf("FILMES REGISTRADOS (do mais recente para o mais antigo)\n\n");

    for(i = 2021; i > 0; i--){
        for(j = 0; j < contadorFilmes; j++){
            if(filme[j].ano == i){
                printf("%d - %s\n", filme[j].ano, filme[j].titulo);
                printf("Diretor: %s\n", filme[j].diretor);
                printf("Genero: %s\n", filme[j].genero);
                printf("Sinopse: %s\n", filme[j].sinopse);
                printf("Codigo: %s\n", filme[j].codigo);
                printf("\n");
            }
        }
    }

    system("PAUSE");
}

//e) Consultar um filme em especifico pelo nome
void consultar(Filme filmes[], int contadorFilmes, Filme filmeConsulta){
    int i, check = 0;

    system("CLS");
    printf("CONSULTA\n\n");

    for(i = 0; i < contadorFilmes; i++){
        if((stricmp(filmes[i].titulo, filmeConsulta.consulta) == 0) || (stricmp(filmes[i].codigo, filmeConsulta.consulta) == 0)){
            printf("- %s\n", filmes[i].titulo);
            printf("Diretor: %s\n", filmes[i].diretor);
            printf("Ano de lancamento: %d\n", filmes[i].ano);
            printf("Genero: %s\n", filmes[i].genero);
            printf("Sinopse: %s\n", filmes[i].sinopse);
            printf("Codigo: %s\n\n", filmes[i].codigo);
            check++;
        }
    }

    if(check == 0){
        printf("Nao foram encontrados registros sobre o titulo ou codigo informado.\n\n");
    }

    system("PAUSE");
}

//Buscar por filme
Filme buscarFilme(int choice){
    Filme filme;

    getchar();
    printf("\n");

    if(choice == 2){
        printf("Informe o codigo do filme a ser alterado: ");
    }
    if(choice == 5){
        printf("Informe o titulo ou codigo do filme a ser consultado: ");
    }

    gets(filme.consulta);
    return filme;
}
