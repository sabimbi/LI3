/* 
 * File:   catalogo.h
 * Author: mesas
 *
 * Created on 29 de Março de 2014, 0:52
 */

#ifndef CATALOGO_H
#define	CATALOGO_H
typedef struct coautores{
    char *nome;
    int npublics;
    struct coautores *left,*right;
}Coautor,*CoautorPtr;

typedef struct catalogo{
    char *nome;
    Coautor *coautores;
    int npublics[100];
    
    struct catalogo *left,*right;
}Catalogo,*CatalogoPtr;
CatalogoPtr copiarindice(CatalogoPtr c);
void printcoaux(CoautorPtr c);
CoautorPtr createcoaux(CoautorPtr c);
CoautorPtr getCoaut(char *autor);
CatalogoPtr updatepublics(CatalogoPtr c,char *autor,int ano);
int countsolo(CatalogoPtr c);
int tamanho(CoautorPtr c);
int nautoresasolo();
void reset_catalogo();
int countautoresasolo(CatalogoPtr c);
CoautorPtr inserircoautor(CoautorPtr c,char *coauthor);
CatalogoPtr catalogarautores(CatalogoPtr catalog,char *autor,char *coautor);
void inserirautores(char **autores,int tamanho);
void inserircatalogo(char *linha);
int eautor(char *str);
int search(CatalogoPtr c,char *autor);
CatalogoPtr getCatalogo();
CoautorPtr getCoautores(char* autor);
void printpublics(CatalogoPtr c, char* autor);
int npublics(CatalogoPtr c,CoautorPtr l,char *autor,int ano);
int npublicsem(CatalogoPtr c,char *autor,int ano);
#endif	/* CATALOGO_H */

