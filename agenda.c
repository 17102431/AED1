#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50 // tamanho máximo dos nomes
#define TAM 15 // tamanho de cada número de celular

// estrutura de um contato na agenda
struct agenda{
    char nome[MAX];
    char idade[TAM];
    char celular[TAM];
}typedef contato;

// estrutura auxiliar contendo as variáveis de controle necessárias
struct variables{
    int controleMenu;
    int contadorContatos;
    int tamanhoBuffer;
    int flag;
    char sort;
    int i;
    int j;
    int k;
}typedef variavel;

// estrutura contendo uma string auxiliar para as funcoes de buscar() e apagar()
struct searchBar{
    char busca[MAX];
    int flag;
}typedef busca;

// declaração dos ponteiros
void *buffer;
struct agenda *pContatos;
struct variables *pControle;
struct searchBar *pBusca;

// declaração das funções
void insereContato();
void apagaContato();
void buscaContato();
void imprimeContatos();
void imprimeMenu();
void Insertionsort (int data[], int n);


int main(){
    // no melhor caso, o usuário sai direto do programa (controleMenu == 5)
    system("clear");
    buffer = malloc(sizeof(variavel));
    if (buffer == NULL){
        exit(1); 
    }
    pControle = buffer;
    pControle->controleMenu = 0;
    pControle->contadorContatos = 0;
    printf("Felipe Saraiva Dos Santos\nAED I - 2019/1\nAgenda");
    while(pControle->controleMenu != 5){
        imprimeMenu();
        scanf("%d", &pControle->controleMenu);
        getchar();
        switch (pControle->controleMenu){
            case 1:
                insereContato();
                break;
            case 2:
                apagaContato();
                break;
            case 3:
                buscaContato();
                break;
            case 4:
                system("clear");
                imprimeContatos();
                printf("Enter para continuar...\n");
                getchar();
                break;
            default: 
                if (pControle->controleMenu != 5){
                    printf("Opcao invalida.\n");
                }
        }
    }
    printf("\nSaindo da agenda...\nAgenda finalizada com sucesso!\n");
    free(buffer);
}

void insereContato(){
    (pControle->contadorContatos)++;
    pControle->tamanhoBuffer = sizeof(variavel) + sizeof(busca)+ (pControle->contadorContatos)*sizeof(contato);
    buffer = realloc(buffer, (pControle->tamanhoBuffer));
    pControle = buffer;
    pContatos = buffer + (pControle->tamanhoBuffer) - sizeof(contato);
    printf("\nNovo contato\nNome: ");
    fgets(pContatos->nome, MAX, stdin);
    printf("Idade: ");
    fgets(pContatos->idade, TAM, stdin);
    printf("Celular: ");
    fgets(pContatos->celular, TAM, stdin);
    printf("Contato inserido com sucesso.\n");
}

void apagaContato(){
    pBusca = buffer + sizeof(variavel);
    printf("\nContato a ser excluido: ");
    fgets(pBusca->busca, MAX, stdin);
    pBusca->flag = 0;
    contato *comparadorContato;
    comparadorContato = buffer + sizeof(variavel) + sizeof(busca);
    for (pControle->i = 0; pControle->i < pControle->contadorContatos; (pControle->i)++){
        if (strcmp(pBusca->busca,comparadorContato->nome) == 0){
            pBusca->flag++;
            pControle->j = pControle->i;
        }
        comparadorContato++;
    }
    if (pBusca->flag != 0){
        contato *contatoExcluido, *proximoContato;
        contatoExcluido = buffer + sizeof(variavel) + sizeof(busca) + (pControle->j * sizeof(contato));
        for (pControle->i = 0; pControle->i < ((pControle->contadorContatos) - (pControle->j)); (pControle->i)++){
            proximoContato = buffer + sizeof(variavel) + sizeof(busca) + (pControle->j+pControle->i+1) * sizeof(contato);
            strcpy(contatoExcluido->nome,proximoContato->nome);
            strcpy(contatoExcluido->celular,proximoContato->celular);
            contatoExcluido = buffer + sizeof(variavel) + sizeof(busca) + (pControle->j+pControle->i+1) * sizeof(contato);
        }
        pControle->contadorContatos--;
        pControle->tamanhoBuffer = pControle->tamanhoBuffer - sizeof(contato);
        buffer = realloc(buffer, pControle->tamanhoBuffer);
        printf("Contato excluido.\n");
    } else {
        printf("Esse contato nao existe.\n");
    }        
}

void buscaContato(){
    pBusca = buffer + sizeof(variavel);
    printf("\nPesquisar: ");
    fgets(pBusca->busca, MAX, stdin);
    pBusca->flag = 0;
    pControle->k = 0;
    contato *comparadorContato;
    comparadorContato = buffer + sizeof(variavel) + sizeof(busca);
    for (pControle->i = 0; pControle->i < pControle->contadorContatos; (pControle->i)++){
        for (pControle->j = 0; pControle->j < strlen(pBusca->busca)-1; (pControle->j)++){
            if (pBusca->busca[pControle->j] != comparadorContato->nome[pControle->j]){
                pBusca->flag++;
            }
        }
        if (pBusca->flag == 0){
            (pControle->k)++;
            if(pControle->k == 1){
                printf("\n");
            }
            printf("Contato %d:\n Nome: %s", (pControle->i)+1, comparadorContato->nome);
            printf(" Celular: %s", comparadorContato->celular);
        }
        comparadorContato++;
        pBusca->flag = 0;
    }
    if (pControle->k == 0){
        printf("Nenhum contato corresponde a sua busca.\n");
    }
    printf("\n");
}

void imprimeContatos(){
    contato *imprimeContatos;
    imprimeContatos = buffer + sizeof(variavel) + sizeof(busca);
    if (pControle->contadorContatos == 0){
        printf("\nAinda nao existem contatos.");
    }
    printf("\n");
    for (pControle->i = 0; pControle->i < pControle->contadorContatos; (pControle->i)++){
        printf("Contato %d:\n Nome: %s", (pControle->i)+1, imprimeContatos->nome);
        printf(" Idade: %s", imprimeContatos->idade );
        printf(" Celular: %s", imprimeContatos->celular);
        (imprimeContatos)++;
    } 
    printf("\n");  
}

void imprimeMenu(){
    printf("\n--------------------\n1. Incluir Contato\n2. Apagar Contato\n3. Buscar Contato\n4. Imprimir Contatos\n5. Sair\nSelecione sua opção: ");
}

//void Insertionsort (int data[], int n) { 
//    contato *ordenaContatos;
 //   ordenaContatos = buffer + sizeof(variavel) + sizeof(busca);
//
//    for (pControle->j = 1; pControle->j < contadorContatos; pControle->j++) { 
//        pControle->i = pControle->j - 1;
//        pControle->k = data[j]; 
//        while ( (pControle->i >= 0) && (pControle->tmp < data[i]) ) { 
//            data[i+1] = data[i];
//             pControle->i--; 
//        }//while
//
//        data[i+1] = pControle->tmp; 
//    }//for
// }//Insertionsort