#ifndef __DLLIST__
#define __DLLIST__
#define true 1
#define false 0

typedef struct __jogadpr__{
  char nome[30];
  int idade;
  float peso;
}Jogador;

typedef struct __dlnode__ {
  struct __dlnode__ *next, *prev;
  void *data;
}DLNode;


typedef struct __dllist__ {
  DLNode *first;
  DLNode *cur;
}DLList;



DLList *dllCreate();
int dllDestroy(DLList *dl);
int dllInsertAsFirst(DLList *l, void *data);
int dllInsertAsLast(DLList *dl, void *data);
void listar_elementos(DLList * dl);
void *dllRemoveSpec(DLList *l, void *key, int (*cmp)(void *, void *));
void *dllQuery(DLList * dl, void * key, int(cmp)(void*, void*));
int dllCleanList(DLList *dl);
int compareJogador(void *a, void *b);
void printar_elementos(Jogador *novaComida);
int lista_vazia(DLList *dl);

#endif