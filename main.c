#include "stdio.h"
#include "stdlib.h"


// definição do tipo Pessoa
typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    char nome[50];
    Data data;
}Pessoa;

// função para criar uma Pessoa
Pessoa LerPessoa(){
    Pessoa p;
    printf("\nDigite nome e data de nascimento dd mm aaaa:\n");
    scanf("%50[^\n]%d%d%d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);
    return p;
}

// procedimento para imprimir as informações de uma Pessoa
void Imprimir_pessoa(Pessoa p){
    printf("\nNome: %s\nData: %2d/%2d/%4d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}

// estrutura nó que irá compor nossa pilha
typedef struct no{
    Pessoa p;
    struct no *proximo;
}No;

// função para a operaçao push (empilhar)
No* Push(No *topo){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->p = LerPessoa();
        novo->proximo = topo;
        return novo;
    }
    else{
        printf("\nErro ao alocar memoria!!!\n");
        return NULL;
    }
}

// função para a operaçao pop (desempilhar)
No* Pop(No **topo){
    if(*topo != NULL){
        No *remover = *topo;
        *topo = remover->proximo;
        return remover;
    }
    else{
        printf("\nPilha vazia!\n");
    }
    return NULL;
}

// função para imprimir Pilha
void ImprimirPilha(No *topo){
    printf("\n----------------- PILHA -----------------\n");
    while(topo){
        Imprimir_pessoa(topo->p);
        topo = topo->proximo;
    }
    printf("\n--------------- FIM PILHA ----------------\n");
}

int main(){
    No *remover, *topo = NULL;
    int opcao;

    do{
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n-->");
        scanf("%d", &opcao);
        setbuf(stdin, NULL);

        switch(opcao){
            case 1:
                topo = Push(topo);
                break;
            case 2:
                remover = Pop(&topo);
                if(remover){
                    printf("\n-----------------------------------");
                    printf("\nElemento removido com sucesso!\n");
                    Imprimir_pessoa(remover->p);
                    printf("-----------------------------------\n");
                }
                else{
                    printf("\n-----------------------------------");
                    printf("\nSem Nó a ser removido\n");
                    printf("-----------------------------------\n");
                }
                break;
            case 3:
                ImprimirPilha(topo);
                break;
            default:
                if(opcao != 0){
                    printf("\n-----------------------------------");
                    printf("\nOpção inválida!!!\n");
                    printf("-----------------------------------\n");
                }
        }
        
    }while(opcao != 0);
    printf("\n-----------------------------------");
    printf("\nVocê saiu!\n");
    printf("-----------------------------------\n");
    
	return 0;
}
