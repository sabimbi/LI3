/* 
 * File:   main.c
 * Author: mesas
 *
 * Created on 3 de Março de 2014, 2:37
 */

#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>
#include "parser.h"
#include"index.h"
#include"stats.h"
#include<string.h>
#include<strings.h>
/*
 * 
 */
#define MAX 40
typedef struct stack{
    char *str;
    struct stack *next;
}Node,*Stack;

Stack push(Stack s,char *str){
    Node *m;
    
    m=NULL;
    if(s==NULL){
        m=(Node *) malloc(sizeof(Node));
        m->str=strdup(str);
        m->next=NULL;
        
        
    }else{
        m=(Node *) malloc(sizeof(Node));
        m->str=strdup(str);
        m->next=s;
        
    }
    return m;
}
void print(AutorPtr a) {

    char op;
    op = '0';

    if (a != NULL) {
        
        print(a->left);    
        printf("%s\n",a->nome);

            

            print(a->right);
       
        }

    

}
void printautor(int index) {
    AutorPtr a, *autor;
    autor = getlista();
    a = autor[index];
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




void printstats(int year, Stats s) {
    int i;
    if (s != NULL) {
        if (year == s->ano) {
            printf("Ano: %d\n", s->ano);
            printf("Nº de publicacoes: %d\n", s->npublics);
            for (i = 0; i < 41; i++) {
                if (s->coautores[i] != 0) {
                    if(i==0){printf("A solo: %d\n",s->coautores[i]);}else{
					printf("Com %d coautor(s): %d publicacoes\n", i, s->coautores[i]);}
                }
            }
        } else {
            if (year < s->ano) {
                printstats(year, s->left);
            } else {
                printstats(year, s->right);
            }
        }
    }

}

void printano(int year) {
    Stats s;
    s = getStats();
    printstats(year, s);
}
void printstack(Stack s){
    while(s!=NULL){
        printf("%s\n",s->str);
        s=s->next;
    }
}
Stack s;

int menu() {

    int r, i;
    int index;
    char l;
    char filename[40];
    char *linha;
    char letra;
    int max, min, npublics, nomes;
    int op;
    AutorPtr a,*autor;
    char *str;
    s=NULL;
    r = 1;
    i = 0;
    autor=NULL;
    letra = '0';
    max = min = npublics = nomes = 0;
    printf("Bem Vindo ao GESTAUTS\n");
    printf("Seleccione uma opção:\n");
    printf("1 - Ler ficheiro \n");
    printf("2 - Listar nº de publicaçoes do intervalo de anos\n");
    printf("6 - Listar autores que começam pela letra inserida\n");
    printf("15 - Sair\n");
    printf("Opção: ");

    if (scanf("%d", &op) > 0) {


        getchar();
        switch (op) {
            case 1:
            {

                printf("Ficheiro para leitura: ");
                if (fgets(filename, 40, stdin) != NULL) {
                    linha = newline(filename);
                    reset_index();
                    reset_stats();
                    reset_lista();
                    if (parser_file(linha) == 0) {
                        printf("Erro na abertura do ficheiro(Talvez ficheiro não exista ou tenha outro nome?)\n");
                    } else {

                        max = getMaxAno();
                        min = getMinAno();
                        npublics = getNPublics();
                        nomes = getNomes();
                        printf("Ficheiro lido: %s\n", linha);
                        printf("Nº publicacoes: %d\n", npublics);
                        printf("Anos: [%d a %d]\n", min, max);

                        printf("Nº de nomes lidos: %d\n", nomes);

                    }
                } else {
                    printf("Erro na abertura do ficheiro");
                }


                r = 1;
                break;
            }
            case 2:
            {
                max = getMaxAno();
                min = getMinAno();
                if (max == 0 && min == 0) {
                    printf("Por favor faça leitura do ficheiro primeiro\n");
                } else {
                    for (i = min; i <= max; i++) {
                        printano(i);
                    }
                }
                r = 1;
                break;
            }
            case 6:
            {
                max = getMaxAno();
                min = getMinAno();
                if (max == 0 && min == 0) {
                    printf("Por favor faça leitura de um ficheiro primeiro\n");
                    break;
                } else {
                    printf("Insira a letra: ");
                    if (scanf("%c", &letra) > 0) {
                        printletra(letra);
                    }
                r = 1;
                break;
            }
            case 15:
            {
                r = 0;
                break;
            }
        }

        }}
    return r;

}

void interpretador() {
    int resultado;

    int ciclo = 1;

    while (ciclo == 1) {
        resultado = menu();

        if (resultado == 0) {
            ciclo = 0;

        }

    }

}

int main() {

    interpretador();
    return 0;
}


