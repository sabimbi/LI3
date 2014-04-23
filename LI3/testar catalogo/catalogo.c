#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<string.h>
#include"catalogo.h"
#include"parser.h"
static CatalogoAutores indice;
void reset_catalogo(){
    int i,j;
    for(i=0;i<60;i++){
        indice.lista[i]->ano=0;
        for(j=0;j<200;j++){
            indice.lista[i]->list[j]=NULL;
           
        }
    }
}
int hash(char *str){
    int i,j,hash,max;
    for(i=hash=j=0;str[i]!='\0';i++){
        j=str[i]-'0';
        hash+=j;
    }
    i=0;
    j=hash;
    max=0;
    while(i<j){
        if(hash%i==0){
            max=i;
        }
        i++;
    }
    return (hash/max);
}
Lista inserirgrafo(Lista l,Grafo g,char *str){
    Elemento *e;
    e=NULL;
    int i;
    if(l==NULL){
        e=(Elemento *) malloc(sizeof(Elemento));
        for(i=0;i<100;i++){
            e->grafo[i]=g[i];
        }
        e->autor=strdup(str);
        e->next=NULL;
    }else{
        while(strcmp(str,l->autor)!=0){
            l=l->next;
        }
        for(i=0;i<100;i++){
            l->grafo[i]=g[i];
        }
    }
    return l;
}
Grafo retrieve(Lista l,char *str){
    Grafo *g;
    int i;
    g=malloc(100*sizeof(Adj));
    g=NULL;
    while(strcmp(str,l->autor)!=0 && l!=NULL){
        l=l->next;
    }
    if(l!=NULL){
        for(i=0;i<100;i++){
            g[i]=l->grafo[i];
        }
    }
    return g;
}
void inserirautores(char **autores,int size){
    int ano,a,b,index;
    int i,j;
    Lista l=NULL;
    Grafo g[100];
    CatalogoPtr c=NULL;
    a=b=index=0;
    ano=atoi(autores[size-1]);
    c=indice.lista[ano-1950];
    for(i=0;i<size-1;i++){
        a=hash(autores[i]);
        l=c->list[a];
        for(j=0;j<size-1;j++){
            if(j!=i){
            b=hash(autores[j]);   
            if(l==NULL){
                g=add_ramo(g,a,b,autores[j]);
                l=inserirgrafo(l,g,autores[i]);
                c->list[a]=l;
                indice.lista[ano-1950]=c;
            }else{
                g=retrieve(c->list[a],autores[i]);
                g=add_ramo(g,a,b,autores[j]);
            }
            }
    }
    }}
void inserircatalogo(char *linha){
  char ** array  = NULL;
  char *cpy=strdup(linha);
char *str=strtok (cpy, ",");
int i = 0,ano=0;
char *space=NULL;



while (str) {
  array = realloc (array, sizeof (char*) * ++i);
  space=trim(str);
 
  
  if (array == NULL)
    exit (-1); 
  
  array[i-1] = space;
  

  str = strtok (NULL, ",\n");
}

/* realloc one extra element for the last NULL */
i++;
array = realloc (array, sizeof (char*) * i);
array[i] = 0;
for(ano=0;ano<i;ano++){
    printf("%s\n",array[ano]);
}
inserirautores(array,i);

}

Adj ins_lista_adjacentes (Adj l , int v,char *str)
{ Adj a;
if(procuraradj(l,v)==1){
    l->publics++;
    return l;
}else{
  a = (Adj)malloc(sizeof(Node));
  a->autor=strdup(str);
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
Grafo add_ramo(Grafo g , int v1 , int v2,char *str)
{ char *autor;
autor=strdup(str);
  *(g+v1) = ins_lista_adjacentes(*(g+v1),v2,autor);  
  return g;
}