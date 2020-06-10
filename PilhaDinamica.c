
struct no2 {
    char info;
    struct no2 *anterior;

};
typedef struct no2 No2;

typedef struct pilha{
    No2 *topo;

}Pilha;

void inicialize(Pilha *p){
   p->topo = NULL;
}

int isEmpty(Pilha *p){
    if(p->topo == NULL){
        return 1;
    }else {
        return 0;
    }

}

int push(Pilha *p, char info){
    No2 *novoNo;
    novoNo = (No2*)malloc(sizeof(No2));

    if(novoNo != NULL){
      novoNo->info = info;
      novoNo->anterior = p->topo;
      p->topo = novoNo;
      return 1;
    } else{
      return 0;
    }

}

char* pop(Pilha *p){
    if(isEmpty(p) == 1){
        return NULL;
    } else{
        No2 *noRemovido;
        char *infoRemovida;
        noRemovido = p->topo;
        infoRemovida = (char*)malloc(sizeof(char));
        infoRemovida = p->topo->info;
        p->topo = p->topo->anterior;
        free(noRemovido);
        return infoRemovida;
    }

}

char* top(Pilha *p){
     if(isEmpty(p) == 1){
        return NULL;
     } else{
        return &p->topo->info;
     }

}

int listStack(Pilha *p){
    if(isEmpty(p) == 1){
        return 0;
    } else{
        No2 *noAux;
        noAux = p->topo;
        while(noAux != NULL){
           printf("%c\n", noAux->info);
           noAux = noAux->anterior;
        }
    }

}









