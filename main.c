#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct data{
    int dia, mes, ano;
} DATA;

typedef struct usuarios{
    long int identificador;
    char* nome;
    char* endereco;
    char* telefone;
    struct usuarios *prox;
} USUARIOS;

typedef struct reserva{
    DATA inicio;
    DATA fim;
    long int identificador;
    long int numero;
    struct reserva* prox;
} RESERVA;

typedef struct livro{
    long int identificador;
    char *titulo, *editora, **autor;
    int ano, edicao;
    struct livro *prox;
} LIVRO;

///////////////////////////////////////////

typedef struct usuarios* USU;
typedef struct livro* LIV;
typedef struct autor* AUT;
typedef struct reserva* RES;

///////////////////////////////////////////


void incluir_Usuario(USU* ptrUSUARIO){

    if(*ptrUSUARIO == NULL){
       
        *ptrUSUARIO = (USU) malloc(sizeof(USUARIOS));
        scanf("%ld", &(*ptrUSUARIO)->identificador);
        
        (*ptrUSUARIO)->nome = malloc(100 * sizeof(char));
        scanf(" %[^\n]", (*ptrUSUARIO)->nome);
        
        (*ptrUSUARIO)->endereco = malloc(100 * sizeof(char));
        scanf(" %[^\n]", (*ptrUSUARIO)->endereco);
        
        (*ptrUSUARIO)->telefone = malloc(100 * sizeof(char));
        scanf(" %[^\n]", (*ptrUSUARIO)->telefone);
    }

    else{
        incluir_Usuario(& (**ptrUSUARIO).prox);
    }
}


void excluir_Usuario(USU *ptrUSUARIO, long int encontrar){
    USU temp = *ptrUSUARIO;

    if((*ptrUSUARIO)->identificador == encontrar){
        printf("Campos apagados:\n");
        printf("ID: %ld\n", (*ptrUSUARIO)->identificador);
        printf("Nome: %s\n", (*ptrUSUARIO)->nome);
        printf("Endereço: %s\n", (*ptrUSUARIO)->endereco);
        printf("Telefone: %s\n", (*ptrUSUARIO)->telefone);
        *ptrUSUARIO = (*ptrUSUARIO)->prox;
        free(temp); 
    }

    else{
        excluir_Usuario(& (**ptrUSUARIO).prox, encontrar);
    }
}

void listar_Usuarios(USU* ptrUSUARIO, int contadora){
    
    if(contadora == 4){
        return;
    }
    
    if(*ptrUSUARIO == NULL){
        contadora = 0;
        return;
    }

    else{
        printf("Usuario %d:\n", contadora);
        printf("Identificador: %ld\n", (*ptrUSUARIO)->identificador);
        printf("Nome: %s\n",(*ptrUSUARIO)->nome);
        printf("Endereco: %s\n", (*ptrUSUARIO)->endereco);
        printf("Telefone: %s\n", (*ptrUSUARIO)->telefone);
        printf("--------------------\n");

        contadora++;
        listar_Usuarios(& (**ptrUSUARIO).prox, contadora);
    }
}

void mostrar_alterar_Usuario(USU *ptrUSUARIO, long int encontrar){

    if(*ptrUSUARIO == NULL){
        return;
    }

    else if((*ptrUSUARIO)->identificador == encontrar){
        printf("Identificador: %ld\n", (*ptrUSUARIO)->identificador);
        printf("Nome: %s\n",(*ptrUSUARIO)->nome);
        printf("Endereco: %s\n", (*ptrUSUARIO)->endereco);
        printf("Telefone: %s\n", (*ptrUSUARIO)->telefone);
        printf("Reescreva o nome, endereço e telefone: ");

        scanf(" %[^\n]", (*ptrUSUARIO)->nome);
        scanf(" %[^\n]", (*ptrUSUARIO)->endereco);
        scanf(" %[^\n]", (*ptrUSUARIO)->telefone);    
        return;
    }

    else{
        mostrar_alterar_Usuario(& (**ptrUSUARIO).prox, encontrar);
    }
}
///////////////////////////////////////////////

void incluir_Livro(LIV *ptrLIVRO){
    int quantidade, i;

    if(*ptrLIVRO == NULL){
        
        *ptrLIVRO = (LIV) malloc(sizeof(LIVRO));
        scanf(" %ld", &(*ptrLIVRO)->identificador);
        
        scanf(" %d", &quantidade);
        
        (*ptrLIVRO)->autor = malloc(quantidade * sizeof(char*));
        for(i = 0; i < quantidade; i++){
            (*ptrLIVRO)->autor[i] = malloc(50 * sizeof(char));
            scanf(" %[^\n]", (*ptrLIVRO)->autor[i]);
        }
                
        (*ptrLIVRO)->autor[i] = NULL;

        (*ptrLIVRO)->titulo = malloc(100 * sizeof(char));
        scanf(" %[^\n]", (*ptrLIVRO)->titulo);
        
        scanf(" %d", &(*ptrLIVRO)->edicao);
        
        (*ptrLIVRO)->editora = malloc(100 * sizeof(char));
        scanf(" %[^\n]", (*ptrLIVRO)->editora);

        scanf(" %d", &(*ptrLIVRO)->ano);
    }

    else{
        incluir_Livro(& (**ptrLIVRO).prox);
    }
}


void excluir_Livro(LIV *ptrLIVRO, long int encontrar){
    LIV temp = *ptrLIVRO;

    if((*ptrLIVRO)->identificador == encontrar){
        printf("Campos apagados:\n");
        printf("ID: %ld\n", (*ptrLIVRO)->identificador);
        printf("Autores: ");
        for(int i = 0; (*ptrLIVRO)->autor[i] != NULL; i++){
            printf("%s\n", (*ptrLIVRO)->autor[i]);
        }
        printf("Título: %s\n", (*ptrLIVRO)->titulo);
        printf("Edição: %d\n", (*ptrLIVRO)->edicao);
        printf("Editora: %s\n", (*ptrLIVRO)->editora);
        printf("Ano: %d\n", (*ptrLIVRO)->ano);
        
        (*ptrLIVRO) = (*ptrLIVRO)->prox;
        free(temp);
    }

    else{
        excluir_Livro(& (**ptrLIVRO).prox, encontrar);
    }
}

void mostrar_alterar_Livro(LIV *ptrLIVRO, long int encontrar){
    int i;

    if((*ptrLIVRO)->identificador == encontrar){
        printf("Titulo: %s\n", (*ptrLIVRO)->titulo);
        printf("Edicao: %d\n", (*ptrLIVRO)->edicao);
        printf("Editora: %s\n", (*ptrLIVRO)->editora);
        printf("Autores: ");
        
        for(i = 0; (*ptrLIVRO)->autor[i] != NULL; i++){
            printf("%s\n", (*ptrLIVRO)->autor[i]);
        }
        printf("Ano: %d\n", (*ptrLIVRO)->ano);

        printf("Digite novamente o titula, edicao, editora, autores e o ano: ");

        scanf(" %[^\n]", (*ptrLIVRO)->titulo);
        scanf(" %d", &(*ptrLIVRO)->edicao);
        scanf(" %[^\n]", (*ptrLIVRO)->editora);
        
        for(int j = 0; j < i; j++){
            scanf(" %[^\n]", (*ptrLIVRO)->autor[j]);
        }
        
        scanf(" %d", &(*ptrLIVRO)->ano);
        return;
    }
    
    else(& (**ptrLIVRO).prox, encontrar);
}

void listar_Livros(LIV *ptrLIVRO, int contadora){

    if(*ptrLIVRO == NULL){
        contadora = 0;
        return;
    }

    else{
        printf("Livro %d:\n", contadora);
        printf("Identificador: %ld\n", (*ptrLIVRO)->identificador);
        printf("Titulo: %s\n",(*ptrLIVRO)->titulo);
        printf("Edicao: %d\n", (*ptrLIVRO)->edicao);
        printf("Editora: %s\n", (*ptrLIVRO)->editora);
        printf("Ano: %d\n", (*ptrLIVRO)->ano);
        printf("Autores: ");

        for(int i = 0; (*ptrLIVRO)->autor[i] != NULL; i++){
            printf("%s\n", (*ptrLIVRO)->autor[i]);
        }
        
        printf("--------------------\n");
        
        contadora++;
        listar_Livros(& (**ptrLIVRO).prox, contadora);

    }
}

void incluir_Autor(LIV *ptrLIVRO, long int encontrar){
    int i;

    if(encontrar == (*ptrLIVRO)->identificador){
        for(i = 0; (*ptrLIVRO)->autor[i] != NULL; i++){}
        
        (*ptrLIVRO)->autor[i] = malloc(50 * sizeof(char));
        scanf(" %[^\n]", (*ptrLIVRO)->autor[i]);
    
        (*ptrLIVRO)->autor[i+1] = NULL;
    }

    else(& (**ptrLIVRO).prox, encontrar);
}

void excluir_Autor(LIV *ptrLIVRO, long int ID, char deletar[50]){
    int encerrar = 0;

    for(int i = 0; (*ptrLIVRO)->autor[i] != NULL; i++){
        if(strcmp(deletar, (*ptrLIVRO)->autor[i]) == 0){
            free((*ptrLIVRO)->autor[i]); // Libera a memória
            (*ptrLIVRO)->autor[i] = (*ptrLIVRO)->autor[i+1]; // Desloca os autores restantes
            encerrar = 1;
        }
    }

    if(encerrar != 0 && (*ptrLIVRO)->prox != NULL){
        excluir_Autor(&(*ptrLIVRO)->prox, ID, deletar);
    }
}

///////////////////////////////////////////////

void incluir_Reserva(RES *ptrRESERVA){

    if(*ptrRESERVA == NULL){
        *ptrRESERVA = (RES) malloc(sizeof(RESERVA));
        scanf(" %ld", &(*ptrRESERVA)->identificador);
        scanf(" %ld", &(*ptrRESERVA)->numero);
        scanf(" %d %d %d", &(*ptrRESERVA)->inicio.dia, &(*ptrRESERVA)->inicio.mes, &(*ptrRESERVA)->inicio.ano);
        scanf(" %d %d %d", &(*ptrRESERVA)->fim.dia, &(*ptrRESERVA)->fim.mes, &(*ptrRESERVA)->fim.ano);
    }

    else{
        incluir_Reserva(& (**ptrRESERVA).prox);
    }
}

void excluir_Reserva(RES *ptrRESERVA, long int encontrar, long int livro){
    RES temp = *ptrRESERVA;

    if(((*ptrRESERVA)->identificador == encontrar) && ((*ptrRESERVA)->numero == livro)){
        printf("Campos apagados:\n");
        printf("ID usuário: %ld\n", (*ptrRESERVA)->identificador);
        printf("ID livro: %ld\n",(*ptrRESERVA)->numero);
        printf("Data inicio: %d/%d/%d\n", (*ptrRESERVA)->inicio.dia, (*ptrRESERVA)->inicio.mes, (*ptrRESERVA)->inicio.ano);
        printf("Data fim: %d/%d/%d\n", (*ptrRESERVA)->fim.dia, (*ptrRESERVA)->fim.mes, (*ptrRESERVA)->fim.ano);
        
        (*ptrRESERVA) = (*ptrRESERVA)->prox;
        free(temp);
    }

    else{
        excluir_Reserva(& (**ptrRESERVA).prox, encontrar, livro);
    }

}

void alterar_Reserva(RES *ptrRESERVA, long int encontrar, long int livro){

    if((((*ptrRESERVA)->identificador == encontrar) && ((*ptrRESERVA)->numero == livro))){
        printf("ID do usuário: %ld\n", (*ptrRESERVA)->identificador);
        printf("ID do livro: %ld\n", (*ptrRESERVA)->numero);
        printf("Inicio: %d/%d/%d\n", (*ptrRESERVA)->inicio.dia, (*ptrRESERVA)->inicio.mes, (*ptrRESERVA)->inicio.ano);
        printf("Fim: %d/%d/%d\n", (*ptrRESERVA)->fim.dia, (*ptrRESERVA)->fim.mes, (*ptrRESERVA)->fim.ano);
    
        printf("Digite para alterar: ");
        scanf(" %d %d", &(*ptrRESERVA)->inicio.dia, &(*ptrRESERVA)->inicio.mes);
        scanf(" %d %d", &(*ptrRESERVA)->fim.dia, &(*ptrRESERVA)->fim.mes);
    
        return;
    }

    else{
        alterar_Reserva(& (**ptrRESERVA).prox, encontrar, livro);
    }
}

void listar_Reservas(RES *ptrRESERVA, int contadora){

    if(*ptrRESERVA == NULL){
        contadora = 0;
        return;
    }

    else{
        printf("Reserva %d:\n", contadora);
        printf("ID usuário: %ld\n", (*ptrRESERVA)->identificador);
        printf("ID livro: %ld\n",(*ptrRESERVA)->numero);
        printf("Data inicio: %d/%d/%d\n", (*ptrRESERVA)->inicio.dia, (*ptrRESERVA)->inicio.mes, (*ptrRESERVA)->inicio.ano);
        printf("Data fim: %d/%d/%d\n", (*ptrRESERVA)->fim.dia, (*ptrRESERVA)->fim.mes, (*ptrRESERVA)->fim.ano);
        printf("--------------------\n");
        
        contadora++;
        listar_Reservas(& (**ptrRESERVA).prox, contadora);
    }
}

//////////////////////////////////////////////

void IniciarU(USU *Usu){
    *Usu = NULL;
}

void IniciarL(LIV *Liv){
    *Liv = NULL;
}

void IniciarA(AUT *Aut){
    *Aut = NULL;
}

void IniciarR(RES *Res){
    *Res = NULL;
}

///////////////////////////////////////////////q

int main(){
    USU usuario;
    LIV livro;
    AUT autor;
    RES reserva;

    char opcao, deletar[50];
    int menu, contadora = 1, qtdusuarios;
    long int encontrar, outro;

    IniciarU(&usuario);
    IniciarL(&livro);
    IniciarA(&autor);
    IniciarR(&reserva);

    do{    
        printf("1 - Usuário\n");
        printf("2 - Livro\n");
        printf("3 - Reserva\n");
        printf("4 - Relatórios\n");
        printf("5 - Sair\n");
        printf("Escolha uma opção: ");

        scanf(" %d", &menu);

        switch(menu){
            
            //USUARIOS
            case 1:
                printf("--------------------\n");
                printf("I - Incluir usuario\n");
                printf("E - Excluir usuario\n");
                printf("A - Alterar usuario\n");
                printf("R - Relatórios\n");

                scanf(" %c", &opcao);

                if((opcao == 'I') || (opcao == 'i')){
                    printf("Digite o identificador, nome, endereço e telefone: ");
                    incluir_Usuario(&usuario);
                    printf("--------------------\n");
                }
            
                else if((opcao == 'E') || (opcao == 'e')){
                    printf("Digite o identificador do usuario a ser excluido: ");
                    scanf(" %ld", &encontrar);
                    excluir_Usuario(&usuario, encontrar);
                    printf("--------------------\n");
                }

                else if((opcao == 'A') || (opcao == 'a')){
                    printf("Digite o identificador do usuário à ser alterado: ");
                    scanf(" %ld", &encontrar);
                    mostrar_alterar_Usuario(&usuario, encontrar);
                    printf("--------------------\n");
                }
                
                else if((opcao == 'R') || (opcao == 'r')){
                    printf("Usuarios cadastrados:\n");
                    listar_Usuarios(&usuario, contadora);
                }
                break;
            
            //LIVROS
            case 2: 
                printf("--------------------\n");
                printf("I - Incluir livro\n");
                printf("E - Excluir livro\n");
                printf("A - Alterar livro\n");
                printf("R - Relatórios\n");
                printf("1 - Incluir/Excluir autores\n");

                scanf(" %c", &opcao);

                if((opcao == 'I') || (opcao == 'i')){
                    printf("Digite o ID, quantidade de autores, os autores, titulo, edicao, editora e o ano: ");
                    incluir_Livro(&livro);
                    printf("--------------------\n");
                }
            
                else if((opcao == 'E') || (opcao == 'e')){
                    printf("Digite o identificador do livro a ser excluido: ");
                    scanf(" %ld", &encontrar);
                    excluir_Livro(&livro, encontrar);
                    printf("--------------------\n");
                }

                else if((opcao == 'A') || (opcao == 'a')){
                    printf("Digite o identificador do livro à ser alterado: ");
                    scanf(" %ld", &encontrar);
                    mostrar_alterar_Livro(&livro, encontrar);
                    printf("--------------------\n");
                }
                
                else if((opcao == 'R') || (opcao == 'r')){
                    printf("Livros cadastrados:\n");
                    listar_Livros(&livro, contadora);
                }
                
                else if(opcao == '1'){
                    printf("I - Incluir autor\nE - Excluir autor\n");
                    scanf(" %c", &opcao);
                    
                    if((opcao == 'i') || (opcao == 'I')){
                        printf("Digite o ID do livro e o novo autor: ");
                        scanf(" %ld", &encontrar);
                        incluir_Autor(&livro, encontrar);
                        printf("--------------------\n");
                    }
                
                    else if((opcao == 'e') || (opcao == 'E')){
                        printf("Digite o nome do autor a ser excluido: ");
                        scanf(" %[^\n]", deletar);
                        excluir_Autor(&livro, encontrar,deletar);
                        printf("--------------------\n");
                    }
                }
                break;

            //RESERVA
            case 3: 
                printf("--------------------\n");
                printf("I - Incluir reserva\n");
                printf("E - Excluir reserva\n");
                printf("A - Alterar reserva\n");
                printf("R - Relatórios\n");

                scanf(" %c", &opcao);

                if((opcao == 'i') || (opcao == 'I')){
                    printf("Digite o ID do usuario, ID do livro, data de inicio e data de fim: ");
                    incluir_Reserva(&reserva);
                    printf("--------------------\n");
                }

                else if((opcao == 'e') || (opcao == 'E')){
                    printf("Digite o ID do usuario e o ID do livro para excluir: ");
                    scanf(" %ld %ld", &encontrar, &outro);
                    excluir_Reserva(&reserva, encontrar, outro);
                    printf("--------------------\n");
                }
                
                else if((opcao == 'a') || (opcao == 'A')){
                    printf("Digite o ID do usuario e o ID do livro para alterar: ");
                    scanf(" %ld %ld", &encontrar, &outro);
                    alterar_Reserva(&reserva, encontrar, outro);
                    printf("--------------------\n");
                }

                else if((opcao == 'r') || (opcao == 'R')){
                    listar_Reservas(&reserva, contadora);
                }

                break;
                
            //RELATORIOS
            case 4:
                printf("--------------------\n");
                printf("L - Listar livros\n");
                printf("U - Listar usuários\n");
                printf("R - Listar usuarios com reserva\n");

                scanf(" %c", &opcao);

                if((opcao == 'U') || (opcao == 'u')){
                    listar_Usuarios(&usuario, contadora);
                }
            
                else if((opcao == 'l') || (opcao == 'L')){
                    listar_Livros(&livro, contadora);
                }

                else if((opcao == 'r') || (opcao == 'R')){
                    listar_Reservas(&reserva, contadora);
                }

                break;
            default:
                break;
        }
    }while(menu != 5);
}