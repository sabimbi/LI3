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
  struct node * next;
} Node;

typedef Node * Adj;
typedef Adj  * Grafo;
typedef struct listautores{
    char *str;
    Grafo *g;
    struct listautores *next;
}Elemento,*Lista;
typedef struct catalogo{
    int ano;
    Lista list[200];   
}Catalogo;

typedef struct catalogoautores{
    Catalogo lista[100];
}CatalogoAutores;
void inserircatalogo(char *str);
Grafo   add_ramo(Grafo g , int v1,int v2);
int procuraradj(Adj l,int v);
Adj ins_lista_adjacentes (Adj l , int v);
#endif	/* CATALOGO_H */

