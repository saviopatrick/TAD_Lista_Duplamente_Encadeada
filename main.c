
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLList.h"

int compareJogador(void *a, void *b) {

  Jogador *jogadorA = (Jogador *)a;
  Jogador *jogadorB = (Jogador *)b;

  return strcmp(jogadorA->nome, jogadorB->nome) == 0;
}

void printar_elementos(Jogador *jogador){
  if(jogador == NULL){
    printf("\nJogador não encontrada\n");
  }else{
    printf("Nome: %s, idade: %d, peso: %.2f", jogador->nome, jogador->idade, jogador->peso);
  }
  printf("\n");
}

int main(void){
  DLList *lista = NULL;
  int opcao;

  do{
    printf("TAD - Lista Duplamente Encadeada\n");
    printf("1 - Criar uma colecao\n");
    printf("2 - Inserir um jogador na colecao\n");
    printf("3 - Consultar jogadores\n");
    printf("4 - Exibir todos os Jogadores\n");
    printf("5 - Remover itens da Lista\n");
    printf("6 - Esvaziar a lista\n");
    printf("7 - Destruir a lista\n");
    scanf("%d", &opcao);

    switch(opcao){
      case 1:
        if(lista == NULL){
          lista = dllCreate();
          if(lista != NULL){
            printf("\nLista criada com sucesso!\n");
          }else{
            printf("\nnão foi possível criar a lista\n");
          }
        }else{
          printf("\nVocê já tem uma lista criada\n");
        }
        break;
      case 2:
        if(lista != NULL){
          Jogador *jogador = (Jogador*)malloc(sizeof(Jogador));
          if(jogador != NULL){
            printf("\nDigite o nome da jogador: ");
            scanf(" %s", jogador->nome);

            printf("Digite o idade do jogador: ");
            scanf(" %d", &jogador->idade);

            printf("Digite o peso do da jogador: ");
            scanf(" %f", &jogador->peso);

            if(dllInsertAsLast(lista, jogador)){
              printf("\njogador inserida com sucesso\n\n");
            }else{
              printf("\nNão foi possivel inserir a jogador\n\n");
            }
          }
        }else{
          printf("\nCrie a lista primeiro\n");
        }
        break;
      case 3:
        if(lista != NULL){
          if(lista_vazia(lista)==false){
            Jogador chave;
            printf("\nDigite o nome da Jogador que você deseja procurar: ");
            scanf("%s", chave.nome);
            printf("\n");
            Jogador *resultado = (Jogador*)dllQuery(lista, &chave, compareJogador);
            printar_elementos(resultado);
          }else{
             printf("\nAdicione primeiro antes de procurar\n");
          }
        }else{
            printf("\nCrie a lista antes de tentar procurar algo\n");
        }
        break;
      case 4:
        if(lista != NULL){
          if(lista_vazia(lista) == false){
            printf("\nJogadors que estão na lista:\n");
            listar_elementos(lista);
          }else{
            printf("\nAdicione primeiro antes de procurar\n");
          }
        }else{
          printf("\nCrie a lista antes de tentar procurar algo\n");
        }
        break;
      case 5:
        if(lista != NULL){
          if(lista_vazia(lista) == false){
            Jogador chave;
            printf("\nDigite o nome da Jogador que deseja remover: ");
            scanf(" %s", chave.nome);

            if(dllRemoveSpec(lista, &chave, compareJogador)){
              printf("\nJogador removida com sucesso!\n");
            }else{
              printf("\nNão foi possivel achar a Jogador na lista\n");
            }
          }else{
            printf("\nInsira uma Jogador antes de tentar remover\n");
          }
        }else{
          printf("\nCrie a lista antes de tentar remover algo\n");
        }
        break;
      case 6:
        if(lista != NULL){
          if(dllCleanList(lista) == true){
            if((lista)){
              printf("\nTodos os elementos foram removidos com sucesso\n");
            }else{
              printf("\nNão foi possivel remover todas as Jogadors\n");
            }
          }else{
            printf("\nA lista não tem nenhuma Jogador dentro dela\n");
          }
        }else{
          printf("\nCrie a lista antes de tentar esvaziar ela\n");
        }
        break;
      case 7:
        if(lista != NULL){
          if(lista_vazia(lista) == false){
            printf("\nA lista não pode ser destruida, pois existem elementos nela\n");
          }else{
            if(dllDestroy(lista)){
              printf("\nLista destruida com sucesso!\n");
              lista = NULL;
            }
          }
        }else{
            printf("\nCrie a lista antes de tentar destruir ela\n");
        }
        break;
      case 8:
        printf("Programa finalizado!");
        exit(0);
        break;
      default:
        printf("\n opção inválida");
        break;
    }

  }while(1);
  return 0;
}
