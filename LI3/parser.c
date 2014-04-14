#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<string.h>
#include<ctype.h>
#include"parser.h"
#include"index.h"
#include"stats.h"
#include"catalogo.h"


char *strdup(const char *str)
{
    int n = strlen(str) + 1;
    char *dup = malloc(n);
    if(dup)
    {
        strcpy(dup, str);
    }
    return dup;
}





int startspace (char *str){
    int r;
    if(str[0]==' '){
        r=1;
    }
    else{
        r=0;
    }
    return r;
}
char *trim(char *str)
{
    
    int i,j,k;
    i=j=k=0;
    for(i=0;str[i]!='\0';i++){
        if(str[0]==' '){
            for(j=i;str[j]!='\0';j++){
                str[j]=str[j+1];
            }
            i=0;
        }if(str[i]==' ' && str[i+1]==' '){
            k=i;
            for(j=i;str[j]!='\0';j++){
                str[j]=str[j+1];
            }
           i=k; 
        }
        
    }
    return str;
}
int numind(char *str){
    int i=str[0]-'0';
    int r;
    if(i>=0 && i<=9 ){
        r=1;
    }else{
        r=0;
    }
    return r;
}
void tratar_public(char *line){
    char *str,*space;
    int c;
    
    int i,n,ano,nomes,coautores;
    
    
    
    ano=nomes=coautores=0;
   
    str=space=NULL;
    
    str=strtok(line,",");
    
    n=1;
    while(str!=NULL){
    space=trim(str);
    
    if(numind(str)==1){
        ano=atoi(str);
        maxminpublic(ano);
        
        inserirstats(ano,(n-1),(n-2));
  n=1;
  
    }else{
       
        c=str[0];
        i=(int)c;
        inserirautor(space,i);
        
        
        nomes++;
        n++;
    }
    
    str=strtok(NULL,",");
    
    
    }
    setNomes(nomes);
}

char * newline(char *str){
    int i;
    i=0;
    while(str[i]!='\n'){
        i++;
    }
    str[i]='\0';
    return str;
}

int parser_file(char *str) {


    FILE *fp;
    char *linha;
    int i=0;
    int r=0;
    int nlinhas=0;
    char c;
    
    linha=(char *) malloc(1024*sizeof(char));
    fp = fopen(str, "r");
    if(fp==NULL){
        r=0;
    }else{
    while((c=fgetc(fp))!=EOF ){
        
        if(c!='\n' ){
        i++;
        linha=(char*) realloc (linha,i*sizeof(char));
        linha[i-1]=c;
        }
        else{
            i--;
            linha[i]='\0';
            tratar_public(linha);
            inserircatalogo(linha);
            
         nlinhas++;
         
        i=0;
        
        }
       
    }
    
    r=1;
    setPublics(nlinhas);
    }
    return r;

}

