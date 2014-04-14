/* 
 * File:   parser.h
 * Author: mesas
 *
 * Created on 7 de Março de 2014, 0:19
 */

#ifndef PARSER_H
#define	PARSER_H



char *newline(char *str);
char *strdup(const char *str);
char *trim(char *str);
int parser_file(char *str);
int numind(char *str);
void reset_index();
void maxminpublic(int year);
void trata_public(char *line);

int getMaxAno();
int getMinAno();
int getNomes();
int getNPublics();
#endif	/* PARSER_H */

