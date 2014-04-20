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
        indice.lista[i].ano=0;
        for(j=0;j<200;j++){
            indice.lista[i].list[j]=NULL;
           
        }
    }
}
void inserirautores(char **autores,int size){
    int ano,a,b,index;
    int i,j;
    Lista l=NULL;
    Grafo g=NULL;
    a=b=index=0;
    ano=atoi(autores[size-1]);
    for(i=0;i<size-1;i++){
        
        for(j=0;j<size-1;j++){
            if(j!=i){
               
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