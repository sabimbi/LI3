/* 
 * File:   catalogo.h
 * Author: mesas
 *
 * Created on 29 de Março de 2014, 0:52
 */

#ifndef CATALOGO_H
#define	CATALOGO_H

typedef struct node 
{ int v;
int publics;
char *autor;
  struct node * next;
} Node;

typedef Node * Adj;
typedef Adj  * Grafo;
typedef struct listautores{
    char *autor;
    Grafo grafo[100];
    struct listautores *next;
}Elemento,*Lista;
typedef struct catalogo{
    int ano;
    Lista list[200];   
}Catalogo,*CatalogoPtr;

typedef struct catalogoautores{
    CatalogoPtr lista[100];
}CatalogoAutores;
void inserircatalogo(char *str);
int hash(char *str);
Grafo   add_ramo(Grafo g , int v1,int v2,char *str);
int procuraradj(Adj l,int v);
Adj ins_lista_adjacentes (Adj l , int v,char *str);
#endif	/* CATALOGO_H */

