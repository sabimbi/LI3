#include<stdlib.h>
#include<stdio.h>
#include"strings.h"
#include"string.h"
#include"index.h"

#include"parser.h"

static AutorPtr lista[27];
static Indiceautores indice;



void maxminpublic(int year) {
    int max, min, cpy;
    max = indice.maxano;
    min = indice.minano;

    if (year > max) {
        cpy = max;
        max = year;
        min = cpy;
    } else {
        if (year < max && year < min) {
            min = year;
        }
    }
    indice.maxano = max;
    indice.minano = min;
}

void reset_lista() {
    int i;
    for (i = 0; i < 27; i++) {
        lista[i] = NULL;
    }
}

void inserirautor(char *str, int index) {
    AutorPtr p;

    if (index < 0) {
        p = lista[26];
        p = insert(str, p);
        lista[26] = p;
    } else {
        index = -65 + index;
        p = lista[index];
        p = insert(str, p);
        lista[index] = p;
    }
}

AutorPtr insert(char *str, AutorPtr a) {
    Autor *p;
    
    p = NULL;
    if (a == NULL) {
        p = (Autor *) malloc(sizeof (Autor));
        p->nome = strdup(str);
        p->left = NULL;
        p->right = NULL;
        p->altura = 1;
        a = p;
    } else {
        if (strcmp(str, a->nome) != 0) {
            if (strcmp(str, a->nome) < 0) {
                a->left = insert(str, a->left);
            } else {
                a->right = insert(str, a->right);
            }
        }
    }
    
    return a;
}

int procurar(char *str) {
    int index;
    int flag;
    AutorPtr p;

    char l;
    l = str[0];
    flag = 0;
    index = (int) l;
    index = -65 + index;
    p = lista[index];
    while (p != NULL && flag == 0) {
        if (strcmp(str, p->nome) == 0) {
            flag = 1;

        } else {
            if (strcmp(str, p->nome) < 0) {
                p = p->left;
            } else {
                p = p->right;
            }
        }
    }
    return flag;
}

AutorPtr* getlista() {
    return lista;
}

int getMaxAno() {
    return indice.maxano;
}

int getMinAno() {
    return indice.minano;
}

int getNPublics() {
    return indice.npublics;
}

int getNomes() {
    return indice.nnomes;
}

void reset_index() {

    indice.maxano = 0;
    indice.minano = 0;
    indice.npublics = 0;
    indice.nnomes = 0;




}

void setPublics(int npublics) {
    indice.npublics = npublics;
}

void setNomes(int nomes) {
    indice.nnomes += nomes;
}