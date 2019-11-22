#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct elem
{
    int idade;
    struct elem *prox;
} elem;


typedef struct pilha
{
    struct elem *topo;
    int tamanho;
} pilha;


pilha *PILHA_construtor()
{
    pilha *p = (pilha*)malloc(sizeof(pilha));
    if(p==NULL)
        exit(1);
    else
        p->topo = NULL;
        p->tamanho = 0;
    return p;
}

bool PILHA_vazia(pilha *p)
{
    if (p->topo == NULL)
        return true;
    else
        return false;
}

int PILHA_tamanho(pilha *p)
{
    return p->tamanho;
}

void PILHA_exibir(pilha *p)
{
    elem *aux = p->topo;
    printf("\nPilha: \"");
    while(aux!= NULL)
    {
        printf("%d ",aux->idade);
        aux = aux->prox;
    }
    printf("\"\n");
}


bool PILHA_push(pilha *p, elem *dado)
{
    elem *novo = (elem*)malloc(sizeof(elem));
    novo->idade = dado;
    novo->prox = p->topo;
    p->topo = novo;
    p->tamanho++;
    return true;
}

bool PILHA_pop(pilha *p, elem *dado)
{
    elem *aux;

    if (PILHA_vazia(p))
        return false;
    else
    {
        aux = p->topo;
        p->topo = aux->prox;
        dado = aux->idade;
        p->tamanho--;
        free(aux);
    }
}
/*void destruir(pilha *p){
    int num;
    while(p->topo != NULL){
        num = p->topo->idade;
        PILHA_pop(p,num);
        p->tamanho = 0;
    }
}*/

int main()
{
    pilha *p = PILHA_construtor();
    int op;
    int num;
    do{
    printf("\n1 - PUSH\n2 - POP\n3 - TAMANHO\n4 - DESTRUIR PILHA\n5 - SAIR\nESCOLHA SUA OPÇ: ");
    scanf("%d",&op);
    if (op == 1){
        printf("Digite um numero: ");
        scanf("%d",&num);
        PILHA_push(p,num);
        PILHA_exibir(p);
    }
    else if(op == 2){
        PILHA_pop(p,num);
        PILHA_exibir(p);

    }else if(op == 3){
        int tam = PILHA_tamanho(p);
        printf("TAMANHO : %d", tam);
    }
    else if (op == 5){
       // destruir(p);
    }
    else{
        free(p);
    }
    }while(op!= 0 && op!= 5);
    return 0;
}
