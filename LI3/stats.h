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
    struct stats *left,*right;
}Nodo,*Stats;
void inserirstats(int year,int numautores);
Stats inserir(int year,Stats s,int numautores);

void reset_stats();
Stats getStats();
#endif	/* STATS_H */

