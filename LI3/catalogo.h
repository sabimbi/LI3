/* 
 * File:   catalogo.h
 * Author: mesas
 *
 * Created on 29 de Março de 2014, 0:52
 */

#ifndef CATALOGO_H
#define	CATALOGO_H

typedef struct nodo 
{ char* autor;
  struct nodo * next;
} NODO;

typedef NODO * ADJ;
typedef ADJ  * GRAFO;

#endif	/* CATALOGO_H */

