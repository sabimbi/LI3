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


void print(AutorPtr a) {

 

    if (a != NULL) {
        
        print(a->left);    
        printf("%s\n",a->nome);

            

            print(a->right);
       
        }

    

}
void printautor(int index) {
    AutorPtr a;
    a = getlista(index);
   
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




void printtabfile(int year, Stats s,char *filename) {
    int i,ano;
FILE *fp;
ano=year;

fp=fopen(filename,"a");
    if (s != NULL) {
        if (ano == s->ano) {
            
            for (i = 0; i < 41; i++) {
                if (s->coautores[i] != 0) {
                    fprintf(fp," %d;%d;%d\n",ano,i+1,s->coautores[i]);
                }
            }
        } else {
            if (year < s->ano) {
                printtabfile(year, s->left,filename);
            } else {
                printtabfile(year, s->right,filename);
            }
        }
    }
fclose(fp);
}
void printstats(int year,Stats s){
    int flag=0;
    while(s!=NULL && flag == 0){
        if(year==s->ano){
            printf("Ano: %d , ",s->ano);
            printf("Nr Publicaçoes: %d\n",s->npublics);
            flag=1;
        }
        else{
            if(year<s->ano){
               s=s->left;
            }else{
                s=s->right;
            }
        }
    }
    
}

int getAutoresASolo(){
    int i,max,min,n,flag;
    Stats s=NULL;
    s=getStats();
    i=max=min=n=0;
    max=getMaxAno();
    min=getMinAno();
    for(i=min;i<=max;i++){
        flag=0;
        s=getStats();
        while(s!=NULL && flag==0){
            if(i==s->ano){
                n+=s->coautores[0];
                flag=1;
            }else{
                if(i<s->ano){
                s=s->left;}else{
                    s=s->right;
                }
            }
        }
    }
 return n;   
}
int getPublics(int year,Stats s){
    int flag,n;
    flag=n=0;
    while(s!=NULL && flag == 0){
        if(year==s->ano){
            n=s->npublics;
            flag=1;
        }
        else{
            if(year<s->ano){
               s=s->left;
            }else{
                s=s->right;
            }
        }
    }
    return n;
}
int menu() {

    int r, i;

   
    char filename[40];
    char *linha;
    char letra;
    int maxano, minano, npublics, nomes,n,min,max,total,totalchars,year;
    float media=0.0;
    int op;
    FILE *fp=NULL;
    Stats stats=NULL;
    AutorPtr a=NULL;
    LenAutor *l;
    l=NULL;
    r = 1;
    i = 0;
    
    letra = '0';
    maxano = minano = npublics = nomes = 0;
    printf("Bem Vindo ao GESTAUTS\n");
    printf("Seleccione uma opção:\n");
    printf("1 - Ler ficheiro \n");
    printf("2 - Listar nº de publicaçoes do intervalo de anos\n");
    printf("4 - Nr de autores que publicaram a solo\n");
    printf("6 - Listar autores que começam pela letra inserida\n");
    printf("7 - Nr de Publicações num intervalo de anos\n");
    printf("10 - Determinar, para um dado ano, uma tabela que contenha o número total depublicações de 1, 2, ou 3 autores; Tal tabela deverá ser guardada num ficheiro de nome dado e também apresentada em ecrã ao utilizador\n");
    printf("11 - Criar ficheiro com uma tabela com os anos,autores e respectivos numero de publicações por nr de autores\n");
    printf("14 - Determinar a média dos comprimentos dos nomes dos autores, bem como os nomes de maior e menor comprimento\n");
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
                    reset_length();
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


                r = 1;
                break;
            }
            case 2:
            {
                maxano = getMaxAno();
                minano = getMinAno();
                if (maxano == 0 && minano == 0) {
                    printf("Por favor faça leitura do ficheiro primeiro\n");
                } else {
                    for (i = minano; i <= maxano; i++) {
                        stats=getStats();
                        
                        printstats(i,stats);
                        
                    }
                }
                r = 1;
                break;
            }
            case 6:
            {
                maxano = getMaxAno();
                minano = getMinAno();
                if (maxano == 0 && minano == 0) {
                    printf("Por favor faça leitura de um ficheiro primeiro\n");
                    break;
                } else {
                    printf("Insira a letra: ");
                    if (scanf("%c", &letra) > 0) {
                        printletra(letra);
                    }
                
                }
            r = 1;
                break;
            }case 14:{
                min=max=total=totalchars=0;
                l=getLen();
                total=0;
                for(i=0;i<27;i++){
                    total+=l[i].total;
                    totalchars+=l[i].totalchars;
                    if(l[i].max>max){
                        
                        max=l[i].max;
                        
                    }else{
                        if(l[i].min<min){
                            min=l[i].min;
                        
                        }}
                }
                media=(float)totalchars/total;
                printf("Max Comprimento: %d\n",max);
            printf("Min Comprimento: %d\n",min);
            printf("Media Comprimento: %f\n",media);
            }
            case 10:{
                year=0;
                printf("Ano: ");
                scanf("%d",&year);
                getchar();
                printf("Nome do ficheiro em qual quer gravar: ");
                if(fgets(filename,40,stdin)!=NULL){
                    fp=NULL;
                fp=fopen(filename,"w");
                fprintf(fp,"#Ano;#Autores;#Publicações\n");
                stats=getStats();
                while(stats->ano!=year){
                    if(year<stats->ano){
                        stats=stats->left;
                    }else{
                        stats=stats->right;
                    }
                }
                printf("#Ano;#Autores;#Publicações\n");
                for(i=0;i<=2;i++){
                    
                    printf("%d;%d;%d\n",stats->ano,i+1,stats->coautores[i]);
                    fprintf(fp,"%d;%d;%d\n",stats->ano,i+1,stats->coautores[i]);
                    
                }
                }
                fclose(fp);
                r=1;
                break;
            }
                case 11:{
                    printf("Nome do ficheiro em qual quer gravar: ");
                    minano=getMinAno();
                    maxano=getMaxAno();
                    if(fgets(filename,40,stdin)!=NULL){
                    for(i=0;filename[i]!='\0';i++){
                        if(filename[i]=='\n'){
                            filename[i]=filename[i+1];
                        }
                    }
                    stats=getStats();
                    fp=fopen(filename,"w");
                    fprintf(fp,"#Ano;#Autores;#Publicações\n");
                    fclose(fp);
                    for (i = minano; i <= maxano; i++) {
                        printtabfile(i,stats,filename);
                    }
                    }
                    
                r=1;
                break;}
                case 4:{
                    minano=getMinAno();
                    maxano=getMaxAno();
                    i=nomes=n=0;
                    nomes=getAutoresASolo();
                    printf("Numero de autores que so publicaram a solo: %d\n",nomes);
                   
                    r=1;
                    break;
                }
                case 7:{
                    printf("De ");
                    scanf("%d",&minano);
                    printf("a ");
                    scanf("%d",&maxano);
                    npublics=n=0;
                    for (i = minano; i <= maxano; i++) {
                        stats=getStats();
                        n=getPublics(i,stats);
                        npublics+=n;
                        
                    }
                    printf("Nr de Publics de %d a %d : %d\n",minano,maxano,npublics);
                    r=1;
                    break;
                    
                }
            case 15:
            {
                r = 0;
                break;
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


