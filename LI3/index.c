#include<stdlib.h>
#include<stdio.h>
#include"strings.h"
#include"string.h"
#include"index.h"

#include"parser.h"

static AutorPtr lista[27];
static Indiceautores indice;

int altura(AutorPtr a)
{
    if (a == NULL)
        return 0;
    return a->altura;
}
int max(int a, int b)
{
    return (a > b)? a : b;
}
AutorPtr rightRotate(AutorPtr y)
{
    AutorPtr x = y->left;
    AutorPtr T2 = x->right;
 
    
    x->right = y;
    y->left = T2;
 
    
    y->altura = max(altura(y->left), altura(y->right))+1;
    x->altura = max(altura(x->left), altura(x->right))+1;
 
    
    return x;
}
AutorPtr leftRotate(AutorPtr x)
{
    AutorPtr y = x->right;
    AutorPtr T2 = y->left;
 
    
    y->left = x;
    x->right = T2;
 
    
    x->altura = max(altura(x->left), altura(x->right))+1;
    y->altura = max(altura(y->left), altura(y->right))+1;
 
    
    return y;
}
int getBalance(AutorPtr n)
{
    if (n == NULL)
        return 0;
    return altura(n->left) - altura(n->right);
}
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
      /* 1.  Perform the normal BST rotation */
    int balance = getBalance(a);
    if (a == NULL){
        a=(Autor *) malloc(sizeof(Autor));
        a->left=a->right=NULL;
        a->nome=strdup(str);
        a->altura = max(altura(a->left), altura(a->right)) + 1;
        return a;
    }else{
        
        if(strcmp(str,a->nome)!=0){
    if (strcmp(str,a->nome)<0){
        a->left  = insert(str,a->left);}
    else{
        a->right = insert(str,a->right);}
 
    /* 2. Update altura of this ancestor node */
    
 
    /* 3. Get the balance factor of this ancestor node to check whether
       this node became unbalanced */
    
 
   
 
    
    if (balance > 1 && strcmp(str,a->left->nome)<0){
        a=rightRotate(a);
    }else{
    
    if (balance < -1 && strcmp(str,a->right->nome)>0){
        a=leftRotate(a);
 
    }
    if (balance > 1 && strcmp(str,a->left->nome)>0)
    {
        a->left =  leftRotate(a->left);
        a=rightRotate(a);
    }else{
 
    
    if (balance < -1 && strcmp(str,a->right->nome)<0)
    {
        a->right = rightRotate(a->right);
        a=leftRotate(a);
    }
    }}}}
    /* return the (unchanged) node pointer */
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