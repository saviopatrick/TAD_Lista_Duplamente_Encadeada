
#include "DLList.h"
#include <stdlib.h>
#include <stdio.h>



DLList *dllCreate(){
  DLList *dl;
  dl = (DLList*)malloc(sizeof(DLList));
  if(dl != NULL){
    dl->first = NULL;
    dl->cur = NULL;
    return dl;
  }
  return NULL;
}

int dllDestroy(DLList *dl){
  if(dl != NULL){
    if(dl->first == NULL){
      free(dl);
      return true;
    }
  }
  return false;
}
//funcao de inserir um elemento

int dllInsertAsFirst(DLList *l, void *data) {
  DLNode *newnode;

  if (l != NULL) {
    newnode = (DLNode *)malloc(sizeof(DLNode));
    if (newnode != NULL) {

      newnode->data = data;
      newnode->prev = NULL;
      newnode->next = l->first;

      if (l->first != NULL) {
        l->first->prev = newnode;
      }

      l->first = newnode;
      return true;
    }
  }
  return false;
}

//funcao de inserir um elemento

int dllInsertAsLast(DLList *dl, void *data){
  DLNode *newnode, *last;
  if(dl!=NULL){
    if(dl->first == NULL){
      last = NULL;
    }else{
      last = dl->first;
      while(last->next != NULL){
        last = last->next;
      }
    }

    newnode = (DLNode*)malloc(sizeof(DLNode));
    if(newnode != NULL){
      newnode->next = NULL;
      newnode->data = data;
      newnode->prev = last;
    }

    if(last == NULL){
      dl->first = newnode;
    }else{
      last->next = newnode;
    }
    return true;
  }
  return false;
}


void listar_elementos(DLList * dl){
  DLNode *spec; void *data;
  if(dl != NULL){
    if(dl->first != NULL){
      spec = dl->first;
      while(spec != NULL){
        printar_elementos(spec->data);
        spec = spec->next;
      }
    }
  }
}


//funcao de remocao especifica
void *dllRemoveSpec(DLList *dl, void *key, int (*cmp)(void *, void *)) {
  DLNode *spec, *nextspec, *prevspec; int stat = false; void *data;
  if(dl != NULL){
    if(dl->first != NULL){
      spec = dl->first;
      stat = cmp(key, spec->data);
      while(stat != true && spec->next != NULL){
        spec = spec->next;
        stat = cmp(key, spec->data);
      }

      if(stat == true){
        prevspec = spec->prev;
        nextspec = spec->next;
        data = spec->data;
        if(prevspec != NULL){
          prevspec->next = nextspec;
        }
        if(nextspec != NULL){
           nextspec->prev = prevspec;
        }
        if(dl->first == spec){
          dl->first = nextspec;
        }
        free(spec);
        return true;
      }
    }
  }
  return false;
}



//funcao de pesquisa
void *dllQuery(DLList * dl, void * key, int(cmp)(void*, void*)){
  DLNode *spec; int stat; void *data;
  if(dl != NULL){
    if(dl->first != NULL){
      spec = dl->first;
      stat = cmp(key, spec->data);
      while(stat != true && spec->next != NULL){
        spec = spec->next;
        stat = cmp(key, spec->data);
      }

      if(stat == true){
        return spec->data;
      }
    }
  }
  return NULL;
}


int dllCleanList(DLList *dl){
  DLNode *spec;
  if(dl != NULL){
    if(dl->first != NULL){
      while(dl->first != NULL){
        spec = dl->first;
        dl->first = spec->next;
        if(spec->next != NULL){
          spec->next->prev = NULL;
        }
      }
      free(spec);

      return true;
    }
  }
  return false;
}


int lista_vazia(DLList *dl){
 if(dl != NULL){
    if(dl->first == NULL){
      return true;
    }
  }
  return false;
}
