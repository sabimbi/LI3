#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<string.h>
#include"catalogo.h"
#include"parser.h"
#include<ctype.h>
static CatalogoPtr indice;
void printcoaux(CoautorPtr c){
    if(c!=NULL){
        printcoaux(c->left);
        printf("Coautor:%s Nr Publics:%d\n",c->nome,c->npublics);
        printcoaux(c->right);
    }
}
void reset_catalogo(){
    indice=NULL;
    
}

int tamanho(CoautorPtr c){
    int r;
    if(c==NULL){
        r=0;
    }else{
        r=1+tamanho(c->left)+tamanho(c->right);
    }
    return r;
}
int countsolo(CatalogoPtr c){
    int r,n;
    if(c==NULL){
        r=0;
    }else{
        n=0;
        
            if(c->coautores!=NULL){
                n=1;
            }
        
        if(n==0){
            r=1+countsolo(c->left)+countsolo(c->right);
        }else{
            r=countsolo(c->left)+countsolo(c->right);
        }
    }
    return r;
}

CatalogoPtr updatepublics(CatalogoPtr c,char *autor,int ano){
    
    int r=0,n=0,index=0;
    if(c!=NULL && r==0){
        if(strcmp(autor,c->nome)==0){
            index=ano-1950;
            n=c->npublics[index];
            n++;
            c->npublics[index]=n;
            r=1;
            
       
    }
         else{
            if(strcmp(autor,c->nome)<0){
                c->left=updatepublics(c->left,autor,ano);
            }else{
                c->right=updatepublics(c->right,autor,ano);
            }
        }   
    }
    return c;
}

CoautorPtr getCoautor(CatalogoPtr c,char *autor){
    CoautorPtr l=NULL;
    
    if(c!=NULL){
        if(strcmp(autor,c->nome)==0){
            l=c->coautores;
            
        }else{
            if(strcmp(autor,c->nome)<0){
                l=getCoautor(c->left,autor);
            }else{
                l=getCoautor(c->right,autor);
            }
        }
    }
  return l;  
}
CoautorPtr createcoaux(CoautorPtr c){
    Coautor *p=NULL;
    if(c!=NULL){
        if(c->npublics>=1){
            p=(Coautor *) malloc(sizeof(Coautor));
            p->npublics=c->npublics;
            p->left=createcoaux(c->left);
            p->right=createcoaux(c->right);
        }
    }
    return p;
}
CoautorPtr getCoaut(char *autor){
    return(getCoautor(indice,autor));
}
CatalogoPtr copiarindice(CatalogoPtr c){
    Catalogo *m=NULL;
    
    
    if(c!=NULL){
        m->nome=strdup(c->nome);
        m->coautores=c->coautores;
        m->left=copiarindice(c->left);
        m->right=copiarindice(c->right);
    }
    return m;
}
CatalogoPtr getCatalogo(){
    return indice;
}

CoautorPtr inserircoautor(CoautorPtr c,char *coauthor){
    Coautor *tmp=NULL;
    char *cpy=NULL;
    int n=0;
    cpy=strdup(coauthor);
    if(numind(coauthor)==0){
    if(c==NULL ){
        tmp=(Coautor *) malloc(sizeof(Coautor));
        tmp->nome=strdup(coauthor);
        tmp->npublics=1;
        tmp->left=tmp->right=NULL;
        c=tmp;
    }else{
        
            if(strcmp(cpy,c->nome)==0){
                n=c->npublics;
                n++;
                c->npublics=n;
                return c;
            }else{
                if(strcmp(cpy,c->nome)<0){
                    c->left=inserircoautor(c->left,cpy);
                }else{
                    c->right=inserircoautor(c->right,cpy);
                }
   
    }
        
    }
    }
    return c;
}

CatalogoPtr catalogarautores(CatalogoPtr catalog,char *autor,char *coautor){
    
    
    Catalogo *c;
    
    int i;
   
    if(catalog==NULL){
        c=(Catalogo *)malloc(sizeof(Catalogo));
        c->nome=strdup(autor);
        c->left=c->right=NULL;
        for(i=0;i<100;i++){
            c->npublics[i]=0;
        }
        c->coautores=(Coautor *) malloc(sizeof(Coautor));
        c->coautores=NULL;
        c->coautores=inserircoautor(c->coautores,coautor);
        return c;
    }else{
        if(strcmp(autor,catalog->nome)==0){
            
            
        catalog->coautores=inserircoautor(catalog->coautores,coautor);
        
        }
        else{
        if(strcmp(autor,catalog->nome)<0){
        catalog->left=catalogarautores(catalog->left,autor,coautor);
        }
        else{
            catalog->right=catalogarautores(catalog->right,autor,coautor);
        }
        }}
    
   
    
    return catalog;
    }
void inserirautores(char **autores,int tamanho){
    int j;
    char *autor,*coautor;
    
   
    autor=coautor=NULL;
    
   j=0;
    
    autor=strdup(autores[0]);
    for(j=1;j<tamanho;j++){
        coautor=strdup(autores[j]);
        indice=catalogarautores(indice,autor,coautor);
    }
        
    
   
      
    
            
   
      
}
    

void inserircatalogo(char *linha){
  char ** array  = NULL;
  char *cpy=strdup(linha);
  char *autor=NULL;
  int i=0,ano=0;
char *str=strtok (cpy, ",");

char *space=NULL;


while (str) {
  array = realloc (array, sizeof (char*) * ++i);
  space=trim(str);
 
  
  if (array == NULL)
    exit (-1); 
  
  
  array[i-1] = space;
  
  

  str = strtok (NULL, ",\n");
}

/* realloc one extra element for the last NULL */
array = realloc (array, sizeof (char*) * (i+1));
array[i]="0";
ano=atoi(array[i-1]);
autor=strdup(array[0]);




inserirautores(array,i);
 indice=updatepublics(indice,autor,ano);








}






int npublicsem(CatalogoPtr c,char *autor,int ano){
    int index=0,num=0,r=0;
   
    
    
   while(c!=NULL && r==0){
       if(strcmp(autor,c->nome)==0){
           
           index=ano-1950;
           num=c->npublics[index];
           r=1;
           
           
   }else{
           if(strcmp(autor,c->nome)<0){
               c=c->left;
           }else{
               c=c->right;
           }
   } 
   
   }
    return num;
}



