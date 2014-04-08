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
    
  struct autor *left,*right;    
}Autor,*AutorPtr;



typedef struct indiceautores{
    int maxano;
    int minano;
    int npublics;
    int nnomes;
}Indiceautores;
int height(AutorPtr a);
int max(int a,int b);
void maxminpublic(int year);

AutorPtr insert(char *str,AutorPtr a);

int getMaxAno();
int getMinAno();
int getNPublics();
int getNomes();
void inserirautor(char *str,int index);
void reset_lista();

int procurar(char *str);
AutorPtr *getlista();
int getMaxAno();
int getMinAno();
int getNPublics();
int getNNomes();
void reset_index();
void setPublics(int npublics);
void setNomes(int nomes);
#endif	/* INDEX_H */

