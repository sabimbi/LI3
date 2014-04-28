#include <ctype.h>
#include "parser.h"
#include"index.h"
#include"stats.h"
#include "catalogo.h"
#include<string.h>
#include<strings.h>
#include<stdio.h>
#include<stdlib.h>
static AutorPtr aux;
void printpublics(CatalogoPtr c,char *autor){
    int i;
    char op;
    int maxano,minano;
    if(c!=NULL){
        if(strcmp(autor,c->nome)==0){
            maxano=getMaxAno();
            minano=getMinAno();
            for(i=minano,op='S';i<=maxano&& op=='S';i++){
                
                printf("Ano: %d\nNr Publics: %d\n",i,c->npublics[i-1950]);
                printf("Proximo?: ");
                scanf("%c",&op);
                getchar();
            }
        }
    }
}
int size(AutorPtr a){
    int r;
    if(a!=NULL){
        r=1+size(a->left)+size(a->right);
    }else{
        r=0;
    }
    return r;
}
AutorPtr inseriraux(AutorPtr a,char *nome){
    Autor *p;
    if(a==NULL){
        p=(Autor *) malloc(sizeof(Autor));
        p->nome=strdup(nome);
        p->len=strlen(nome);
        p->right=p->left=NULL;
        a=p;
    }else{
        if(strcmp(nome,a->nome)!=0){
        if(strcmp(nome,a->nome)<0){
            a->left=inseriraux(a->left,nome);
        }else{
            a->right=inseriraux(a->right,nome);
        }
        }}
    return a;
}
void printaux(AutorPtr a){
    if(a!=NULL){
        printaux(a->left);
        printf("%s\n",a->nome);
        printaux(a->right);
    }
}
void print(AutorPtr a) {
    
    
    int i=0,op=0;
    if (a != NULL) {
        print(a->left);
        aux=inseriraux(aux,a->nome);
        i=size(aux);
        
        if(i!=100){
            
        print(a->right);    
        }else{
            printaux(aux);
            printf("Proximo? 1 -Sim 0 - Nao\n");
            printf("Opção: ");
            scanf("%d",&op);
            getchar();
            if(op==1){
                aux=NULL;
                print(a);
            }
        }
        
}
}
void printautor(int index) {
    AutorPtr a;
    a = getlista(index);
    
    aux=NULL;
    print(a);
}

void printletra(char c) {

    int index;
    char l;
    l = c;
    if (l >= 'a' && l <= 'z') {
        l = l - 32;
        index = (int) l;
        index = -65 + index;
    } else {
        index = (int) l;
        index = -65 + index;
    }



    printautor(index);
}

void printtabfile(int year, Stats s, char *filename) {
    int i, ano;
    FILE *fp;
    ano = year;

    fp = fopen(filename, "a");
    if (s != NULL) {
        if (ano == s->ano) {

            for (i = 0; i < 41; i++) {
                if (s->coautores[i] != 0) {
                    fprintf(fp, " %d;%d;%d\n", ano, i + 1, s->coautores[i]);
                }
            }
        } else {
            if (year < s->ano) {
                printtabfile(year, s->left, filename);
            } else {
                printtabfile(year, s->right, filename);
            }
        }
    }
    fclose(fp);
}

void printstats(int year, Stats s) {
    int flag = 0;
    while (s != NULL && flag == 0) {
        if (year == s->ano) {
            printf("Ano: %d , ", s->ano);
            printf("Nr Publicaçoes: %d\n", s->npublics);
            flag = 1;
        } else {
            if (year < s->ano) {
                s = s->left;
            } else {
                s = s->right;
            }
        }
    }

}

int getPublics(int year, Stats s) {
    int flag, n;
    flag = n = 0;
    while (s != NULL && flag == 0) {
        if (year == s->ano) {
            n = s->npublics;
            flag = 1;
        } else {
            if (year < s->ano) {
                s = s->left;
            } else {
                s = s->right;
            }
        }
    }
    return n;
}

int query1() {
    int maxano, minano, npublics, nomes;
    
    char filename[40];
    char *linha;
    maxano = minano = npublics = nomes = 0;
    printf("Ficheiro para leitura: ");
    if (fgets(filename, 40, stdin) != NULL) {
        linha = newline(filename);
        reset_index();
        reset_stats();
        reset_lista();
        reset_length();
        reset_catalogo();
        if (parser_file(linha) == 0) {
            printf("Erro na abertura do ficheiro(Talvez ficheiro não exista ou tenha outro nome?)\n");
        } else {

            maxano = getMaxAno();
            minano = getMinAno();
            npublics = getNPublics();
            nomes = getNomes();
            printf("Ficheiro lido: %s\n", linha);
            printf("Nº publicacoes: %d\n", npublics);
            printf("Anos: [%d a %d]\n", minano, maxano);

            printf("Nº de nomes lidos: %d\n", nomes);


        }
    } else {
        printf("Erro na abertura do ficheiro");
    }


    return 1;
}

int query2() {
    int maxano, minano, i;
    char op;
    Stats stats = NULL;
    minano = getMinAno();
maxano = getMaxAno();
op='S';
    if (maxano == 0 && minano == 0) {
        printf("Por favor faça leitura do ficheiro primeiro\n");
    } else {
        for (i = minano; i <= maxano && op=='S'; i++) {
            stats = getStats();

            printstats(i, stats);
            printf("Proximo?: ");
            scanf("%c",&op);
            getchar();
        }
    }
    return 1;
}

int query3() {
    char filename[40];
    char *linha=NULL;
    int ano, npublics;
    CatalogoPtr c=NULL;
    ano = npublics = 0;
    printf("Nome do autor: ");
    if (fgets(filename, 40, stdin) != NULL) {
        linha = newline(filename);
    }
    ano = 0;

    printf("Ano: ");
    if(scanf("%d", &ano)>0){
        c=getCatalogo();
    npublics = npublicsem(c,linha, ano);
    printf("Nr Publicações: %d\n", npublics);}

    return 1;
}

int query4() {
    int solo=0;


solo=nautoresasolo();
printf("Nº autores a solo: %d\n",solo);
return 1;
}

int query5() {
    char filename[40],*linha=NULL;
    CatalogoPtr c=NULL;
    printf("Autor: ");
    if(fgets(filename,40,stdin)!=NULL){
        linha=newline(filename);
    }
    c=getCatalogo();
    printpublics(c,linha);
return 1;
}

int query6() {
    int maxano = 0, minano = 0;
    char letra;
    maxano = getMaxAno();
    minano = getMinAno();
    letra = '0';
    if (maxano == 0 && minano == 0) {
        printf("Por favor faça leitura de um ficheiro primeiro\n");
        
    } else {
        printf("Insira a letra: ");
        if (scanf("%c", &letra) > 0) {
            printletra(letra);
        }

    }
    return 1;
}
int query7(){
    int maxano = 0, minano = 0,i,n,npublics;
    Stats stats=NULL;
    printf("De ");
                if(scanf("%d", &minano)>0){
                printf("a ");
                if(scanf("%d", &maxano)>0){
                npublics=n=0;
                for (i = minano; i <= maxano; i++) {
                    stats = getStats();
                    n = getPublics(i, stats);
                    npublics += n;

                }
                printf("Nr de Publics de %d a %d : %d\n", minano, maxano, npublics);}}
                return 1;
                
}
int query8(){
    return 1;
}
int query9(){
    return 1;
}
int query10(){
    int year = 0;
    FILE *fp;
    char filename[40];
    Stats stats=NULL;
    int i;
                printf("Ano: ");
                if(scanf("%d", &year)>0){
                getchar();
                printf("Nome do ficheiro em qual quer gravar: ");
                if (fgets(filename, 40, stdin) != NULL) {
                    fp = NULL;
                    fp = fopen(filename, "w");
                    fprintf(fp, "#Ano;#Autores;#Publicações\n");
                    stats = getStats();
                    while (stats->ano != year) {
                        if (year < stats->ano) {
                            stats = stats->left;
                        } else {
                            stats = stats->right;
                        }
                    }
                    printf("#Ano;#Autores;#Publicações\n");
                    for (i = 0; i <= 2; i++) {

                        printf("%d;%d;%d\n", stats->ano, i + 1, stats->coautores[i]);
                        fprintf(fp, "%d;%d;%d\n", stats->ano, i + 1, stats->coautores[i]);

                    }
                fclose(fp);
                }
                }
                return 1;
}
int query11(){
    int maxano,minano;
    char filename[40];
    char *nome=NULL;
    int i;
    FILE *fp;
    Stats stats=NULL;
    maxano=minano=0;
    
    printf("Nome do ficheiro em qual quer gravar: ");
                minano = getMinAno();
                maxano = getMaxAno();
                if (fgets(filename, 40, stdin) != NULL) {
                    nome=newline(filename);
                    }
                    stats = getStats();
                    fp = fopen(nome, "w");
                    fprintf(fp, "#Ano;#Autores;#Publicações\n");
                    fclose(fp);
                    for (i = minano; i <= maxano; i++) {
                        printtabfile(i, stats, filename);
                    }
                    return 1;
                }
    

int query12(){
    return 1;
}
int query13(){
    char filename[40];
    char *linha=NULL;
    Stats stats=NULL;
    int ano, npublics,publics;
    double percentagem=0.0;
    CatalogoPtr c=NULL;
    ano = npublics = publics=0;
    printf("Nome do autor: ");
    if (fgets(filename, 40, stdin) != NULL) {
        linha = newline(filename);
    }
    ano = 0;

    printf("Ano: ");
    if(scanf("%d", &ano)>0){
        c=getCatalogo();
        stats=getStats();
    npublics = npublicsem(c,linha, ano);
    publics=getPublics(ano,stats);
    percentagem=(double)npublics/publics;
    percentagem=percentagem*100;
    printf("Percentagem relativa ao nr publicações de %d: %f\n",ano,percentagem);
    
    }
    return 1;
}
int query14(){
    int maxano,minano;
    maxano=minano=0;
    maxano=getMaxAno();
                minano=getMinAno();
                if(minano==0 || maxano==0){
                    printf("Por favor faça leitura do ficheiro primeiro\n");
                }else{
                printf("Max Comprimento: %s\n", getMaxLen());
                printf("Min Comprimento: %s\n", getMinLen());
                printf("Media Comprimento: %d\n", getMedia());}
return 1;
}