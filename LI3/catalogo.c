#include<stdio.h>
#include<stdlib.h>
#include"catalogo.h"
static CatalogoAutores index;
void reset_catalogo(){
    int i;
    for(i=0;i<60;i++){
        index.lista[i].ano=0;
        index.lista[i].size=0;
        index.lista[i].g=NULL;    }
}
Adj ins_lista_adjacentes (Adj l , int v)
{ Adj a;
if(procuraradj(l,v)==1){
    l->publics++;
    return l;
}else{
  a = (Adj)malloc(sizeof(Node));

  a->v   = v;
  a->next = l;
  return a;}
}

int procuraradj(Adj l,int v){
    int r;
    r=0;
    while(l!=NULL && r==0){
        if(l->v==v){
            r=1;
        }
    }
    return r;
}
Grafo add_ramo(Grafo g , int v1 , int v2)
{
  *(g+v1) = ins_lista_adjacentes(*(g+v1),v2);  
  return g;
}