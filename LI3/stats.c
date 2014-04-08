#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<string.h>

#include "parser.h"
#include "stats.h"
static Stats estatisticas;
void inserirstats(int year,int numautores,int coautores){
    Stats a;
    a=NULL;
    a=estatisticas;
    a=inserir(year,a,numautores,coautores);
    estatisticas=a;
}
Stats inserir(int year,Stats a,int numautores,int coautores){
     
     
    Nodo *m;
    int i;
    m=NULL;
    
     
    if(a==NULL){
        m=(Nodo *) malloc(sizeof(Nodo));
        m->ano=year;
        m->nautores=numautores;
        m->npublics=1;
        m->left=NULL;
        m->right=NULL;
        for(i=0;i<41;i++){
            m->coautores[i]=0;
        }
        m->coautores[coautores]+=1;
        a=m;
    }else{
        if(year==a->ano){
            a->nautores+=numautores;
            a->npublics++;
            a->coautores[coautores]+=1;
    }else{
            if(year<a->ano){
                a->left=inserir(year,a->left,numautores,coautores);
            }else{
                a->right=inserir(year,a->right,numautores,coautores);
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