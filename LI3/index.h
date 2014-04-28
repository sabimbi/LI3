/* 
 * File:   index.h
 * Author: mesas
 *
 * Created on 21 de Março de 2014, 19:11
 */

#ifndef INDEX_H
#define	INDEX_H
typedef struct autor{
    char *nome;
    int altura;
    int len;
  struct autor *left,*right;    
}Autor,*AutorPtr;
typedef struct lengthautor{
    char max[1024];
    char min[1024];
    int maxchar,minchar;
    double media;
    int total;
    int totalchars;
}LenAutor;


typedef struct indiceautores{
    int maxano;
    int minano;
    int npublics;
    int nnomes;
}Indiceautores;
int height(AutorPtr a);
int max(int a,int b);
void maxminpublic(int year);
int min(int a,int b);
AutorPtr insert(char *str,AutorPtr a);
int maxchar(AutorPtr a);
int minchar(AutorPtr a);
int contachars(AutorPtr a);
int contautores(AutorPtr a);
void setTotal(int total,int index);
int getMaxAno();
int getMinAno();
int getNPublics();
int getNomes();
char *getMaxLen();
char *getMinLen();
int getMedia();
void inserirautor(char *str,int index);
void reset_lista();
void reset_length();
int procurar(char *str);
AutorPtr getlista(int index);
LenAutor getLen();
int getMaxAno();
int getMinAno();
int getNPublics();
int getNNomes();
void reset_index();
void setPublics(int npublics);
void setNomes(int nomes);
#endif	/* INDEX_H */

