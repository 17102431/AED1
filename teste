// Nao se preocupem com isso
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"

#define TESTCASE1 "(3 + 5) * (1 + (14/7))\0"
#define RESULT1 true
#define TESTCASE2 "(((4 * (17 - ((((2/1)\0"
#define RESULT2 false
#define TESTCASE3 "3 * 5 + (4 / 2 - (7\0"
#define RESULT3 false
#define TESTCASE4 "\0"
#define RESULT4 true
#define TESTCASE5 "(7) * (8 + 1) * (9 + 2) * ((10 + 3)) * ((11\0"
#define RESULT5 false
#define TESTCASE6 "9 + 5 * (12 + (36/6)\0"
#define RESULT6 false
#define TESTCASE7 "(94)\0"
#define RESULT7 true
#define TESTCASE8 ")\0"
#define RESULT8 false
#define TESTCASE9 "6 * 7\0"
#define RESULT9 true
#define TESTCASE10 "((((((((((((((((((((((((((((((((((((((((((((()))))))))))))))))))))))))))))))))))))))))))))\0"
#define RESULT10 true

#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

// Nodo da Pilha
struct Nodo {
    struct Nodo * prox;
    char c;
};

// Pilha
struct Pilha {
    struct Nodo * topo;
};

typedef struct Pilha Pilha;
typedef struct Nodo Nodo;

// Retorna 1 se a pilha estiver vazia, 0 caso contrario
int isEmpty(Pilha * pilha) {
    if (pilha->topo)
        return 0;
    return 1;
}

// Insere elemento no topo da pilha
void push(Pilha * pilha, char elemento) {
    Nodo * novo = (Nodo*) malloc(sizeof(Nodo));
    novo->c = elemento;

    novo->prox = pilha->topo;
    pilha->topo = novo;
}

/// Remove elemento do topo da pilha, se a pilha nao estiver vazia
void pop(Pilha * pilha) {
    if (!isEmpty(pilha)) {
        Nodo * remover = pilha->topo;
        pilha->topo = remover->prox;
        free(remover);
    }
}


/// Retorna valor do topo da pilha, se a pilha nao estiver vazia
Nodo * top(Pilha * pilha) {
    if (isEmpty(pilha))
        return NULL;
    return pilha->topo;
}

/// Remove todos os elementos da pilha
void clear(Pilha * pilha) {
    while (!isEmpty(pilha)) {
        pop(pilha);
    }
}

// Retorna o numero de diamantes em uma string de entrada
bool balancoParenteses(Pilha *p, char * entrada) {
    int i,contador = 0;
    for(i = 0 ; entrada[i]; i++){
            if(entrada[i] == '('){
                push(p,entrada[i]);
                contador++;
            }
            else if(entrada[i] == ')'){
                pop(p);
                contador--;
            }
            if(contador<0)
            return false;
            
    }
 if(isEmpty(p)){
     return true;
 }
 else{
     return false;
 }


}

int main() {
    // INICIALIZAR PILHA AQUI
    Pilha * p = (Pilha *) malloc(sizeof(Pilha));
    int resultado;

    printf("---Testes de Validacao---\n");
    printf("1. ");
    resultado = balancoParenteses(p, TESTCASE1);
    if (resultado == RESULT1) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED "FAIL. %d != %d\n" RESET, resultado, RESULT1 );
    }
    clear(p);

    printf("2. ");
    resultado = balancoParenteses(p, TESTCASE2);
    if (resultado == RESULT2) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED "FAIL. %d != %d\n" RESET, resultado, RESULT2);
    }
    clear(p);

    printf("3. ");
    resultado = balancoParenteses(p, TESTCASE3);
    if (resultado == RESULT3) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED "FAIL. %d != %d\n" RESET, resultado, RESULT3);
    }
    clear(p);

    printf("4. ");
    resultado = balancoParenteses(p, TESTCASE4);
    if (resultado == RESULT4) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED "FAIL. %d != %d\n" RESET, resultado, RESULT4);
    }
    clear(p);

    printf("5. ");
    resultado = balancoParenteses(p, TESTCASE5);
    if (resultado == RESULT5) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED "FAIL. %d != %d\n" RESET, resultado, RESULT5);
    }
    clear(p);

    printf("6. ");
    resultado = balancoParenteses(p, TESTCASE6);
    if (resultado == RESULT6) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED "FAIL. %d != %d\n" RESET, resultado, RESULT6);
    }
    clear(p);

    printf("7. ");
    resultado = balancoParenteses(p, TESTCASE7);
    if (resultado == RESULT7) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED "FAIL. %d != %d\n" RESET, resultado, RESULT7);
    }
    clear(p);

    printf("8. ");
    resultado = balancoParenteses(p, TESTCASE8);
    if (resultado == RESULT8) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED "FAIL. %d != %d\n" RESET, resultado, RESULT8);
    }
    clear(p);

    printf("9. ");
    resultado = balancoParenteses(p, TESTCASE9);
    if (resultado == RESULT9) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED "FAIL. %d != %d\n" RESET, resultado, RESULT9);
    }
    clear(p);

    printf("10. ");
    resultado = balancoParenteses(p, TESTCASE10);
    if (resultado == RESULT10) {
        printf(GREEN "PASS!\n" RESET);
    }
    else {
        printf(RED "FAIL. %d != %d\n" RESET, resultado, RESULT10);
    }
    clear(p);

    return 0;
}
