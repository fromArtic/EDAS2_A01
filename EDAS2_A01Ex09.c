#include <stdio.h>
#include <stdlib.h>

#define MAX 2000 //Maximo de gados

//Registro Gado
typedef struct{
    int codigo;
    float leite;
    float alim;
    struct{
        int mes;
        int ano;
        int idade;
    }nasc;
    char abate;
}Gado;

//Sub-rotinas
void calendario();
int menu();
Gado cadastro();
void preencherAbate();
void totalLeite();
void totalAlimento();
void totalLeiteAbate();
void totalAlimentoAbate();
void gadosAoAbate();

int main(){
    Gado gados[MAX];
    int mesAtual, anoAtual, contadorGados = 0, choice;

    //Adquirindo o mes e ano atual para o calculo da idade dos gados
    calendario(&mesAtual, &anoAtual);

    do{
        choice = menu();
        if((choice < 0) || (choice > 7)){
            printf("\nESCOLHA INVALIDA.\n");
            system("PAUSE");
        }
        switch(choice){
            case 1:
                gados[contadorGados] = cadastro(&contadorGados, mesAtual, anoAtual);
                break;
            case 2:
                preencherAbate(&gados, contadorGados);
                break;
            case 3:
                totalLeite(gados, contadorGados);
                break;
            case 4:
                totalAlimento(gados, contadorGados);
                break;
            case 5:
                totalLeiteAbate(gados, contadorGados);
                break;
            case 6:
                totalAlimentoAbate(gados, contadorGados);
                break;
            case 7:
                gadosAoAbate(gados, contadorGados);
                break;
            case 0:
                printf("\nEncerrando o programa . . .\n");
        }
    }
    while(choice != 0);

    system("PAUSE");
    return 0;
}

//Consulta o mes e ano atual
void calendario(int *mesAtual, int *anoAtual){
    printf("ATUALIZANDO O SISTEMA\n\n");

    //Mes
    printf("Informe o mes atual (somente digitos): ");
    scanf("%d", &*mesAtual);
    while((*mesAtual <= 0) || (*mesAtual > 12)){
        printf("ERRO: Insira um numero valido. Mes atual: ");
        scanf("%d", &*mesAtual);
    }

    //Ano
    printf("E o ano atual: ");
    scanf("%d", &*anoAtual);
    while(*anoAtual < 2021){
        printf("ERRO: Insira um numero valido. Ano atual: ");
        scanf("%d", &*anoAtual);
    }
}

//Menu de opcoes
int menu(){
    int choice;
    system("CLS");
    printf("CONTROLE DA FAZENDA - MENU DE OPCOES\n\n");
    printf("1. Cadastrar cabeca de gado\n");
    printf("2. Atualizar informacoes de abate\n");
    printf("3. Exibir a quantidade total de leite produzida por semana\n");
    printf("4. Exibir a quantidade total de alimento consumida por semana\n");
    printf("5. Exibir a quantidade total de leite que sera produzida por semana apos o abate\n");
    printf("6. Exibir a quantidade total de alimento que sera consumida por semana apos o abate\n");
    printf("7. Exibir quantos gados irao ao abate\n");
    printf("0. Sair\n\n");
    printf("Insira sua escolha: ");
    scanf("%d", &choice);
    return choice;
}

//1. Cadastrar cabeca de gado
Gado cadastro(int *contadorGados, int mesAtual, int anoAtual){
    Gado gado;

    if(*contadorGados >= MAX){
        printf("\nO total de cabecas de gado (%d) foi atingido.\n", MAX);
        system("PAUSE");
    }else{
        printf("\n");
        //Codigo
        printf("Codigo: ");
        scanf("%d", &gado.codigo);
        //Leite produzido
        printf("Litros de leite produzido por semana: ");
        scanf("%f", &gado.leite);
        //Alimento ingerido
        printf("Quantidade de alimento ingerida por semana (em quilos): ");
        scanf("%f", &gado.alim);
        //Data de nascimento (mes)
        printf("Mes de nascimento (somente digitos): ");
        scanf("%d", &gado.nasc.mes);
        while((gado.nasc.mes <= 0) || (gado.nasc.mes > 12)){
            printf("ERRO: Insira um numero valido. Mes de nascimento: ");
            scanf("%d", &gado.nasc.mes);
        }
        //Data de nascimento (ano)
        printf("Ano de nascimento: ");
        scanf("%d", &gado.nasc.ano);
        while(gado.nasc.ano < 1995){
            printf("ERRO: Insira um numero valido. Ano de nascimento: ");
            scanf("%d", &gado.nasc.ano);
        }

        //Calculo da idade
        gado.nasc.idade = anoAtual - gado.nasc.ano;
        if(gado.nasc.mes > mesAtual){
            gado.nasc.idade = gado.nasc.idade - 1;
        }

        //Abate inicia negativo
        gado.abate = 'N';

        printf("\nCADASTRO CONCLUIDO COM SUCESSO.\n");
        system("PAUSE");
        *contadorGados = *contadorGados + 1;
        return gado;
    }
}

//2. Preencher informacoes de abate
void preencherAbate(Gado *gados, int contadorGados){
    int i;

    //Mais de 5 anos
    for(i = 0; i < contadorGados; i++){
        if(gados[i].nasc.idade > 5){
            gados[i].abate = 'S';
        }
    }
    //Produz menos de 40 litros de leite por semana
    for(i = 0; i < contadorGados; i++){
        if(gados[i].leite < 40){
            gados[i].abate = 'S';
        }
    }
    //Produz entre 50 e 70 litros de leite por semana e ingire mais de 50 quilos de alimento por dia
     for(i = 0; i < contadorGados; i++){
        if((gados[i].leite >= 50) && (gados[i].leite <= 70)){
            if(gados[i].alim > 50){
                gados[i].abate = 'S';
            }
        }
    }

    printf("\nDADOS DE ABATE ATUALIZADOS.\n");
    system("PAUSE");
}

//3. Exibir a quantidade total de leite produzida por semana
void totalLeite(Gado gados[], int contadorGados){
    float somatoria = 0;
    int i;

    for(i = 0; i < contadorGados; i++){
        somatoria += gados[i].leite;
    }

    printf("\n-> %.2f L de leite.\n\n", somatoria);
    system("PAUSE");
}

//4. Exibir a quantidade total de alimento consumida por semana
void totalAlimento(Gado gados[], int contadorGados){
    float somatoria = 0;
    int i;

    for(i = 0; i < contadorGados; i++){
        somatoria += gados[i].alim;
    }

    printf("\n-> %.2f kg de alimento.\n\n", somatoria);
    system("PAUSE");
}

//5. Exibir a quantidade total de leite que sera produzida por semana apos o abate
void totalLeiteAbate(Gado gados[], int contadorGados){
    float somatoria = 0;
    int i;

    for(i = 0; i < contadorGados; i++){
        if(gados[i].abate == 'N'){
            somatoria += gados[i].leite;
        }
    }

    printf("\n-> %.2f L de leite.\n\n", somatoria);
    system("PAUSE");
}


//6. Exibir a quantidade total de alimento que sera consumida por semana apos o abate
void totalAlimentoAbate(Gado gados[], int contadorGados){
    float somatoria = 0;
    int i;

    for(i = 0; i < contadorGados; i++){
        if(gados[i].abate == 'N'){
            somatoria += gados[i].alim;
        }
    }

    printf("\n-> %.2f kg de alimento.\n\n", somatoria);
    system("PAUSE");
}

//7. Exibir quantos gados irao ao abate
void gadosAoAbate(Gado gados[], int contadorGados){
    int somatoria = 0;
    int i;

    for(i = 0; i < contadorGados; i++){
        if(gados[i].abate == 'S'){
            somatoria++;
        }
    }

    printf("\n-> %d gados irao ao abate.\n\n", somatoria);
    system("PAUSE");
}
