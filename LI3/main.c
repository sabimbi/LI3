/* 
 * File:   main.c
 * Author: mesas
 *
 * Created on 3 de Março de 2014, 2:37
 */

#include <stdio.h>
#include <stdlib.h>
#include"queries.h"


/*
 * 
 */
#define MAX 40


int menu() {
    int op=0,r=0;
    
    printf("Bem Vindo ao GESTAUTS\n");
    printf("Seleccione uma opção:\n");
    printf("1 - Ler ficheiro \n");
    printf("2 - Listar nº de publicaçoes do intervalo de anos\n");
    printf("3 - Dado um ano e um autor existente, determinar o número de publicações desse autor em tal ano\n");
    printf("4 - Nr de autores que publicaram a solo\n");
    printf("5 - Dado um autor, criar uma tabela com o número de artigos publicados ano a ano (para anos em que não publicou a entrada deverá ficar a 0)\n");
    printf("6 - Listar autores que começam pela letra inserida\n");
    printf("7 - Nr de Publicações num intervalo de anos\n");
    printf("8 - Dado um nome de um autor, determinar o nome ou nomes dos co-autores com quem mais publicou\n");
    printf("9 - Dado um intervalo fechado de anos, determinar a lista de nomes dos autores que publicaram em todos esses anos;\n");
    printf("10 - Determinar, para um dado ano, uma tabela que contenha o número total depublicações de 1, 2, ou 3 autores; Tal tabela deverá ser guardada num ficheiro de nome dado e também apresentada em ecrã ao utilizador\n");
    printf("11 - Criar ficheiro com uma tabela com os anos,autores e respectivos numero de publicações por nr de autores\n");
    printf("13 - Dado um nome de autor e um ano, determinar a sua percentagem de publicações relativamente ao total de publicações desse ano\n");
    printf("14 - Determinar a média dos comprimentos dos nomes dos autores, bem como os nomes de maior e menor comprimento\n");
    printf("15 - Sair\n");
    printf("Opção: ");

    if (scanf("%d", &op) > 0) {


        getchar();
        switch (op) {
            case 1:
            {

                
                r = query1();
                break;
            }
            case 2:
            {

                
                r = query2();
                break;
            }
            case 3:
            {

                
                r = query3();
                break;
            }
            case 4:
            {

                
                r = query4();
                break;
            }
            case 5:
            {

                
                r = query5();
                break;
            }
            case 6:
            {

                
                r = query6();
                break;
            }
            case 7:
            {

                
                r = query7();
                break;
            }
            case 8:
            {

                
                r = query8();
                break;
            }
            case 9:
            {

                
                r = query9();
                break;
            }
            case 10:
            {

                
                r = query10();
                break;
            }
            case 11:
            {

                
                r = query11();
                break;
            }
            case 12:
            {

                
                r = query12();
                break;
            }
            case 13:
            {

                
                r = query13();
                break;
            }
            case 14:
            {

                
                r = query14();
                break;
            }
            case 15:{
                r=0;
                break;
            }
        
        }
    

}
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


