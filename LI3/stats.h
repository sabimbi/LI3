/* 
 * File:   stats.h
 * Author: mesas
 *
 * Created on 22 de Março de 2014, 17:57
 */

#ifndef STATS_H
#define	STATS_H


typedef struct stats{
    int ano;
    int nautores;
    int npublics;
    int coautores[41];
    struct stats *left,*right;
}Nodo,*Stats;


void inserirstats(int year,int numautores,int coautores);
Stats inserir(int year,Stats s,int numautores,int coautores);

void reset_stats();
Stats getStats();
#endif	/* STATS_H */

