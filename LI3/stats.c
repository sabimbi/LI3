#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<string.h>

#include "parser.h"
#include "stats.h"
static Stats estatisticas;
void inserirstats(int year,int numautores){
    Stats a;
    a=NULL;
    a=estatisticas;
    a=inserir(year,a,numautores);
    estatisticas=a;
}
Stats inserir(int year,Stats a,int numautores){
     
     
    Nodo *m;
    m=NULL;
     
     
    if(a==NULL){
        m=(Nodo *) malloc(sizeof(Nodo));
        m->ano=year;
        m->nautores=numautores;
        m->npublics=1;
        m->left=NULL;
        m->right=NULL;
        a=m;
    }else{
        if(year==a->ano){
            a->nautores+=numautores;
            a->npublics++;
    }else{
            if(year<a->ano){
                a->left=inserir(year,a->left,numautores);
            }else{
                a->right=inserir(year,a->right,numautores);
            }
    }
     
}
return a;
}


void reset_stats(){
    estatisticas=NULL;
}
Stats getStats(){
    return estatisticas;
}